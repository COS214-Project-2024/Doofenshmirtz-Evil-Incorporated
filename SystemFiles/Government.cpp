/**
 * @file BuildingFactory.h
 * @brief Defines the BuildingFactory class for creating building objects.
 */

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
const double POWER_PER_CITIZEN = 0.2; /**< Power usage per citizen */
const double WATER_PER_CITIZEN = 0.15; /**< Water usage per citizen */
const double WASTE_PER_CITIZEN = 0.3; /**< Waste generation per citizen */
const double SEWAGE_PER_CITIZEN = 0.25; /**< Sewage generation per citizen */

/**
     * @brief Constructs a Government instance with a specified balance.
     * @param governmentBalance Initial balance for the government.
     */
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

/**
     * @brief Evaluates traffic conditions for all city units.
     */
void Government::evaluateTrafficConditions()
{
	for (CityUnit* unit : observerList) 
	{
		unit->evaluateTrafficConditions();
	}

}

/**
     * @brief Evaluates the happiness of citizens in all city units.
     */
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

/**
     * @brief Renders the city's visuals by updating the frontend with city unit representations.
     */
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

/**
     * @brief Destroys the Government instance, freeing allocated resources.
     */
Government::~Government()
{
    for (auto it = observerList.begin(); it != observerList.end(); it++) {
		delete *it;
	}
	for (auto it = myCommand.begin(); it != myCommand.end(); it++) {
		delete *it;
	}
}

/**
     * @brief Collects taxes from all city units and updates the government balance.
     */
void Government::collectTaxes() {
	for (CityUnit* unit : observerList) {
		this->governmentBalance += unit->payTaxes();;
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
}

/**
     * @brief Attaches an observer (CityUnit) to the government for updates.
     * @param myObserver Pointer to the CityUnit to be attached.
     */
void Government::attach(CityUnit * myObserver) {
	observerList.push_back(myObserver);
}

 /**
     * @brief Detaches an observer (CityUnit) from the government.
     * @param myObserver Pointer to the CityUnit to be detached.
     */
void Government::detach(CityUnit* myObserver) {
	for (auto it = observerList.begin(); it != observerList.end(); it++) {
		if (*it == myObserver) {
			observerList.erase(it);
			delete myObserver;
			break;
		}
	}
}
/**
     * @brief Notifies all attached city units to update their state.
     */
void Government::notify() {
	for (CityUnit* unit : observerList) {
		unit->update();
	}
}
/**
     * @brief Collects resources from all city units and updates the internal resource state.
     */
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

/**
     * @brief Updates the utility usage based on citizen demands and available capacities.
     */
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


/**
     * @brief Executes the Better Education policy for all city units.
     */
void Government::executeEductation(){

	for(CityUnit* unit : this->observerList)
	{
		GovernmentCommand* educationPolicy = new BetterEducationPolicy(unit, governmentBalance);
    	educationPolicy->executeCommand();
    	delete educationPolicy;  		
	}

}
/**
     * @brief Executes the Short Work Week policy for all city units.
     */
	void Government::executeShortWorkWeek()
	{
		for(CityUnit* unit : this->observerList)
	{
		GovernmentCommand* workPolicy = new ShortWorkWeekPolicy(unit, governmentBalance);
            workPolicy->executeCommand();
            delete workPolicy;		
	}
	}

/**
     * @brief Executes a new tax policy for all city units.
     * @param tax The tax rate to be set.
     */
	void Government::executeNewTax(double tax)
	{
		for(CityUnit* unit : this->observerList)
		{
			GovernmentCommand* taxPolicy = new SetTax(unit, tax);
        	taxPolicy->executeCommand();
        	delete taxPolicy;	
		}
	}
 /**
     * @brief Executes resource spending commands for all city units.
     */
	void Government::executeSpendResources(){

		for(CityUnit* unit : this->observerList)
		{		
			GovernmentCommand* spendResourcesCommand = new SpendResources(unit, unit->getEmploymentRate(), this->getResources(), this->governmentBalance, (unit->evaluateHappiness() / 100.0), this->getUtilities());
			spendResourcesCommand->executeCommand();
			delete spendResourcesCommand;  // Clean up
		}
	}
/**
     * @brief Finds employment for residents in all city units.
     */
    void Government::findEmployment()
    {
		for(CityUnit* unit : this->observerList)
		{
			unit->employResidents();
		}
    }

/**
     * @brief Gets the current government balance.
     * @return Current balance of the government.
     */
int Government::getGovernmentBalance() {
	return this->governmentBalance;
}