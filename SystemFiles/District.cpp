#include "District.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include "Residential.h"
#include "Commercial.h"
#include "Landmark.h"
#include "WebSocketNotifier.h"


/**
 * @brief Constructs a District object.
 */
District::District() : CityUnit(0, 0) {
}


/**
 * @brief Adds a new CityUnit to the district.
 * @param newUnit The CityUnit to be added.
 */
void District::add(CityUnit* newUnit) {
	containedCityUnit.push_back(newUnit);
}

/**
 * @brief Removes a specified CityUnit from the district.
 * @param unit The CityUnit to be removed.
 * @throws std::exception if the unit is not found in the district.
 */
void District::remove(CityUnit* unit) {
	CityUnit* itemToRemove = unit;

	auto it = std::find(containedCityUnit.begin(),containedCityUnit.end(),itemToRemove);

	if (it != containedCityUnit.end())
	{
		containedCityUnit.erase(it);
	}else{
		throw "Item to remove not found";
	}
}


/**
 * @brief Destructor for the District class.
 *
 * Cleans up dynamically allocated CityUnits and clears the containedCityUnit vector.
 */
District::~District()
{
	for (auto unit : containedCityUnit) {
        if (unit != nullptr) {
            delete unit;  // Ensure each unit is only deleted once
            unit = nullptr;  // Avoid dangling pointers
        }
    }
    containedCityUnit.clear();
}


/**
 * @brief Updates all CityUnits within the district and employs residents.
 */
void District::update() {
	for (auto unit:containedCityUnit){
		unit->update();
	}
	this->employResidents();
}


/**
 * @brief Employs residents from residential units in available commercial units.
 *
 * The method ensures that residents without jobs are employed in commercial units
 * that have open employment slots.
 */
void District::employResidents(){
// Step 1: Collect available commercial units with open employment slots
    std::vector<Commercial*> availableCommercialUnits;
    for (auto unit : containedCityUnit) {
        if (Commercial* commercialUnit = dynamic_cast<Commercial*>(unit)) {
            if (commercialUnit->getEmploymentRate() < 1) {
                availableCommercialUnits.push_back(commercialUnit);
            }
        }
    }

    // Step 2: Iterate over all residential units and employ residents if they don't have a job
    for (auto unit : containedCityUnit) {
        if (Residential* residentialUnit = dynamic_cast<Residential*>(unit)) {
            for (auto person : residentialUnit->getResidents()) {
                if (person->getJob() == nullptr) {
                    // Step 3: Try to employ the person in an available commercial unit
                    for (auto commercialUnit : availableCommercialUnits) {
                        if (commercialUnit->getEmploymentRate() < 1) {
                            person->employCitizen(commercialUnit);
                            break;  // Exit loop after employment to avoid extra iterations
                        }
                    }
                }
            }
        }
    }
}

void District::partyResidents()
{
    std::vector<Landmark*> availableLandmarkUnits;
    for (auto unit : containedCityUnit) {
        if (Landmark* LandmarkUnit = dynamic_cast<Landmark*>(unit)) {
            if (LandmarkUnit->getRemainingCapacity()>0) {
                availableLandmarkUnits.push_back(LandmarkUnit);
            }
        }
    }

    for (auto unit : containedCityUnit) {
        if (Residential* residentialUnit = dynamic_cast<Residential*>(unit)) {
            for (auto person : residentialUnit->getResidents()) {
                if (person->getLeisure() == nullptr) {

                    for (auto LandmarkUnit : availableLandmarkUnits) {
                        if (LandmarkUnit->getRemainingCapacity()>0) {
                            person->relaxCitizen(LandmarkUnit);
                            break;  
                        }
                    }
                }
            }
        }
    }
}

/**
 * @brief Creates an iterator for the district.
 * @return A pointer to the created Iterator.
 */
Iterator* District::createIterator() {
	Iterator* it = new ConcreteIterator(this->containedCityUnit);
	return it;
}


/**
 * @brief Calculates the average employment rate for the district.
 * @return The average employment rate as a double.
 */
double District::getEmploymentRate() {
	if (containedCityUnit.empty()) {
        return 0.0; // Avoid division by zero if no units are present
    }

    double totalEmploymentRate = 0.0;
    for (const auto& unit : containedCityUnit) {
        totalEmploymentRate += unit->getEmploymentRate();
    }

    // Return average employment rate
    return totalEmploymentRate / containedCityUnit.size();

}

/**
 * @brief Collects taxes from residents in the district.
 * @return The total amount of tax collected.
 */
double District::payTaxes() {

	double totalTax = 0.0;
    for (auto unit : containedCityUnit) {
        if (Residential* residentialUnit = dynamic_cast<Residential*>(unit)) {
            for (auto person : residentialUnit->getResidents()) {  // Ensure `getResidents()` is correct
                double tax = (person->getBalance() * this->taxRate);
                totalTax += (tax);
                person->takeTax(tax);  // Deduct tax from citizen’s balance
            }
        }
    }
    return totalTax*educationPolicyMultiplier;
}


/**
 * @brief Evaluates the average happiness level of the district.
 * @return The average happiness as an integer.
 * @throws std::exception if total happiness is negative.
 */
int District::evaluateHappiness() {
	int totalHappiness = 0;
    int unitCounter = 0;
	for (auto unit:containedCityUnit)
	{   
        int evaluatedHappinessForUnit = unit->evaluateHappiness();
		if(evaluatedHappinessForUnit != 0)
        {
            unitCounter++;
            totalHappiness += evaluatedHappinessForUnit;
        }
	}

	if (totalHappiness<0)
	{
		throw "Negative happiness";
	}
	return (totalHappiness/unitCounter)*shortweekPolicyMultiplier;
}


/**
 * @brief Counts the total number of citizens in all residential units within the district.
 * @return The total number of citizens.
 */
int District::countCitizens() {
		int totalCitizens = 0;

    for (auto unit : containedCityUnit) {
        if (Residential* residentialUnit = dynamic_cast<Residential*>(unit)) {
            // Count citizens in each Residential unit's residents list
            totalCitizens += residentialUnit->getResidents().size();
        }
    }

    return totalCitizens;
;
}

void District::setTaxRate(double amount)
{
    this->taxRate = amount;
}

void District::updateEducationMultiplier(float mult)
{
    this->educationPolicyMultiplier = mult;
    this->shortweekPolicyMultiplier = 1;
}

void District::updateWeekMultiplier(float mult)
{
    this->shortweekPolicyMultiplier = mult;
    this->educationPolicyMultiplier = 1;
}

void District::evaluateTrafficConditions()
{
    // Loop through all residents and count how many use each type of travel strategy
    std::map<std::string, int> travelStrategyMap;
    travelStrategyMap["PublicTransportStrategy"] = 0;
    travelStrategyMap["RailwayStrategy"] = 0;
    travelStrategyMap["RoadStrategy"] = 0;
    travelStrategyMap["AirportStrategy"] = 0;

    std::map<std::string, std::string> helperMap;
    helperMap["PublicTransportStrategy"] = "progress-public";
    helperMap["RailwayStrategy"] = "progress-train";
    helperMap["RoadStrategy"] = "progress-car";
    helperMap["AirportStrategy"] = "progress-plane";

    for (auto unit : containedCityUnit) 
    {   
        if (Residential* residentialUnit = dynamic_cast<Residential*>(unit)) 
        {   
            for (auto person : residentialUnit->getResidents()) 
            {  
                std::string travelMethod = person->lastUsedStrategyName;
                travelStrategyMap[travelMethod]++;
            }
        }
    }

    // Take ratio of strategy used per citizen and send info to socket
    int totalCitizenCount = this->countCitizens();

	for (const auto& travelPair : travelStrategyMap) 
    {   
        double dblRatio = travelPair.second / totalCitizenCount;
        int ratioPercentageInt = (int)(dblRatio * 100);

        std::cout << "Travel Strategy " << travelPair.first << " had " << travelPair.second << " users\n";

        nlohmann::json message = {
			{"type", "valueUpdate"},
			{"data", {
						{"id", helperMap[travelPair.first]},
						{"value", std::to_string(ratioPercentageInt)}
					}
			}};

		std::cout << message << std::endl;
		WebSocketNotifier::get_mutable_instance().log(message);
    }
    

}
