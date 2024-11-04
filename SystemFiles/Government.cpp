#include "Government.h"
#include "Industrial.h"
#include "WebSocketNotifier.h"
#include <iostream>
#include "Residential.h"
#include "Power.h"
#include "Water.h"
#include "Sewage.h"
#include "Waste.h"
#include "BetterEducationPolicy.h"
#include "ShortWorkWeekPolicy.h"
#include "SetTax.h"
#include "SpendResources.h"
#include "District.h"

// Intialize constants
const double POWER_PER_CITIZEN = 0.2;
const double WATER_PER_CITIZEN = 0.15;
const double WASTE_PER_CITIZEN = 0.3;
const double SEWAGE_PER_CITIZEN = 0.25;

Government::Government(int governmentBalance) {
	this->governmentBalance = governmentBalance;

	nlohmann::json message = {
	{"type", "valueUpdate"},
	{"data", 	{
					{"id", "money"},
					{"value", std::to_string(governmentBalance)}
				}
				}};
	WebSocketNotifier::get_mutable_instance().log(message);

	// Intialize Map
	resources["Wood"] = 0;
    resources["Concrete"] = 0;
    resources["Steel"] = 0;
    resources["Bricks"] = 0;

	utilities["PowerPlant"] = 0;
    utilities["WaterPlant"] = 0;
    utilities["WasteSite"] = 0;
    utilities["SewageSystem"] = 0;
}

void Government::evaluateTrafficConditions()
{
	for (CityUnit* unit : observerList) 
	{
		unit->evaluateTrafficConditions();
	}

}

void Government::evaluateHappiness()
{
	for (CityUnit* unit : observerList) 
	{
		this->averageHappiness = unit->evaluateHappiness();

		nlohmann::json message = {
		{"type", "valueUpdate"},
		{"data", 	{
						{"id", "satisfaction"},
						{"value", std::to_string(this->averageHappiness)}
					}
					}};
		WebSocketNotifier::get_mutable_instance().log(message);
	}

}

void Government::renderCity()
{
	for(CityUnit* unit : observerList)
	{
		nlohmann::json message = {
        	{"type", "cityVisuals"},
        	{"data", unit->getJSONrepresentation()}
    	};

		WebSocketNotifier::get_mutable_instance().log(message);
	}
}

Government::~Government()
{
    for (auto it = observerList.begin(); it != observerList.end(); it++) {
		delete *it;
	}
	for (auto it = myCommand.begin(); it != myCommand.end(); it++) {
		delete *it;
	}
}

void Government::collectTaxes() {
	int currentBalance = this->governmentBalance;
	for (CityUnit* unit : observerList) {
		this->governmentBalance += unit->payTaxes();
	}

	// Front end update
    nlohmann::json message = {
	{"type", "valueUpdate"},
	{"data", 	{
					{"id", "money"},
					{"value", std::to_string(governmentBalance)}
				}
				}};
	WebSocketNotifier::get_mutable_instance().log(message);

	int afterTaxBalance = this->governmentBalance - currentBalance;

	message = {
		{"type", "news"},
		{"data", "Tax has been collected: 🪙" + std::to_string(afterTaxBalance)}};
	WebSocketNotifier::get_mutable_instance().log(message);
}

void Government::attach(CityUnit * myObserver) {
	observerList.push_back(myObserver);
}


void Government::detach(CityUnit* myObserver) {
	for (auto it = observerList.begin(); it != observerList.end(); it++) {
		if (*it == myObserver) {
			observerList.erase(it);
			delete myObserver;
			break;
		}
	}
}

void Government::notify() {
	for (CityUnit* unit : observerList) {
		unit->update();
	}
}

void Government::collectResources() {
	for (CityUnit* unit : observerList) 
	{
    	std::map<std::string, int> unitResources = unit->collectResources();

        for (const auto& resourcePair : unitResources) {
            this->resources[resourcePair.first] += resourcePair.second;
        }
		

    }
    // Send the current state of resources to the frontend
    for (const auto& resourcePair : this->resources) {
        nlohmann::json message = {
            {"type", "valueUpdate"},
            {"data", {
                        {"id", resourcePair.first},
                        {"value", std::to_string(resourcePair.second)}
                    }
            }};
        
        std::cout << message << std::endl;
        WebSocketNotifier::get_mutable_instance().log(message);
    }
}


void Government::updateUtilitiesUsage() {
    // Track total demand
    std::map<std::string, double> totalDemand;
    std::map<std::string, double> totalCapacity;
	std::map<std::string, double> demandMultipliers = {
    {"PowerPlant", POWER_PER_CITIZEN},
    {"WaterPlant", WATER_PER_CITIZEN},
    {"WasteSite", WASTE_PER_CITIZEN},
    {"SewageSystem", SEWAGE_PER_CITIZEN}
};

	// Clear map & reintializse
	//this->utilities.clear();
	
    // Initialize utility types
    const std::vector<std::string> utilityTypes = {"PowerPlant", "WaterPlant", "WasteSite", "SewageSystem"};
    for (const auto& type : utilityTypes) {
        totalDemand[type] = 0;
        totalCapacity[type] = 0;
    }

    // First pass: collect total population
    int totalPopulation = 0;
    for (CityUnit* unit : observerList) {
		totalPopulation = unit->countCitizens();
    }

    // Second pass: collect utility data from each district
    for (CityUnit* unit : observerList) {

        std::map<std::string, double> utilities = unit->collectUtilities();

        for (const auto& utilityPair : utilities) {
            totalCapacity[utilityPair.first] += utilityPair.second; // Total capacity
        }
    }


    // Calculate stress levels
    for (const auto& type : utilityTypes) {
        double populationDemand = totalPopulation * demandMultipliers[type];
        double currentUsage = totalCapacity[type]; // Use previously calculated totals
        if (currentUsage > 0) {
            double demandStress = populationDemand / currentUsage;
            utilities[type] = std::min(1.0, demandStress);
        } else {
            utilities[type] = 1.0; // Maximum stress if no capacity
        }

        // Send updated utility status to frontend
        nlohmann::json message = {
            {"type", "valueUpdate"},
            {"data", {
                {"id", type},
                {"value", std::to_string(utilities[type] * 100)}
            }}
        };
        WebSocketNotifier::get_mutable_instance().log(message);
    }
}



void Government::executeEductation(){

	for(CityUnit* unit : this->observerList)
	{
		GovernmentCommand* educationPolicy = new BetterEducationPolicy(unit, governmentBalance);
    	educationPolicy->executeCommand();
    	delete educationPolicy;  		
	}

}

	void Government::executeShortWorkWeek()
	{
		for(CityUnit* unit : this->observerList)
	{
		GovernmentCommand* workPolicy = new ShortWorkWeekPolicy(unit, governmentBalance);
            workPolicy->executeCommand();
            delete workPolicy;		
	}
	}


	void Government::executeNewTax(double tax)
	{
		for(CityUnit* unit : this->observerList)
		{
			GovernmentCommand* taxPolicy = new SetTax(unit, tax);
        	taxPolicy->executeCommand();
        	delete taxPolicy;	
		}
	}

	void Government::executeSpendResources(){

		for(CityUnit* unit : this->observerList)
		{		
			GovernmentCommand* spendResourcesCommand = new SpendResources(unit, unit->getEmploymentRate(), this->getResources(), this->governmentBalance, (unit->evaluateHappiness() / 100.0), this->getUtilities());
			spendResourcesCommand->executeCommand();
			delete spendResourcesCommand;  // Clean up
		}
	}

    void Government::findEmployment()
    {
		for(CityUnit* unit : this->observerList)
		{
			unit->employResidents();
		}
    }

int Government::getGovernmentBalance() {
	return this->governmentBalance;
}