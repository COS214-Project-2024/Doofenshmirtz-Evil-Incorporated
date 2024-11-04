/**
 * @file District.cpp
 * @brief Implements the District class for managing a collection of CityUnit objects.
 * 
 * The District class is a composite structure that allows for the management of multiple
 * CityUnit objects, such as buildings and landmarks, within a city simulation. It provides
 * methods for adding, removing, and updating units, as well as collecting resources and utilities.
 */


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
District::District() : CityUnit(0, 0) {}

/**
 * @brief Adds a new CityUnit to the district.
 * @param newUnit The CityUnit to be added.
 */
void District::add(CityUnit *newUnit)
{
    containedCityUnit.push_back(newUnit);
}

/**
 * @brief Removes a specified CityUnit from the district.
 * @param unit The CityUnit to be removed.
 * @throws std::exception if the unit is not found in the district.
 */
void District::remove(CityUnit *unit)
{
    CityUnit *itemToRemove = unit;
    auto it = std::find(containedCityUnit.begin(), containedCityUnit.end(), itemToRemove);

    if (it != containedCityUnit.end())
    {
        containedCityUnit.erase(it);
    }
    else
    {
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
    for (auto unit : containedCityUnit)
    {
        if (unit != nullptr)
        {
            delete unit;
            unit = nullptr;
        }
    }
    containedCityUnit.clear();
}

/**
 * @brief Updates all CityUnits within the district and employs residents.
 */
void District::update()
{
    for (auto unit : containedCityUnit)
    {
        unit->update();
    }
    this->employResidents();
}

/**
 * @brief Employs residents from residential units in available commercial units.
 * 
 * Ensures residents without jobs are employed in commercial units with open slots.
 */
void District::employResidents()
{
    std::vector<Commercial *> availableCommercialUnits;
    for (auto unit : containedCityUnit)
    {
        if (Commercial *commercialUnit = dynamic_cast<Commercial *>(unit))
        {
            if (commercialUnit->getEmploymentRate() < 1)
            {
                availableCommercialUnits.push_back(commercialUnit);
            }
        }
    }

    for (auto unit : containedCityUnit)
    {
        if (Residential *residentialUnit = dynamic_cast<Residential *>(unit))
        {
            for (auto person : residentialUnit->getResidents())
            {
                if (person->getJob() == nullptr)
                {
                    for (auto commercialUnit : availableCommercialUnits)
                    {
                        if (commercialUnit->getEmploymentRate() < 1)
                        {
                            person->employCitizen(commercialUnit);
                            break;
                        }
                    }
                }
            }
        }
    }
}

/**
 * @brief Sends residents to available landmark units for leisure activities.
 */
void District::partyResidents()
{
    std::vector<Landmark *> availableLandmarkUnits;
    for (auto unit : containedCityUnit)
    {
        if (Landmark *LandmarkUnit = dynamic_cast<Landmark *>(unit))
        {
            if (LandmarkUnit->getRemainingCapacity() > 0)
            {
                availableLandmarkUnits.push_back(LandmarkUnit);
            }
        }
    }

    for (auto unit : containedCityUnit)
    {
        if (Residential *residentialUnit = dynamic_cast<Residential *>(unit))
        {
            for (auto person : residentialUnit->getResidents())
            {
                if (person->getLeisure() == nullptr)
                {
                    for (auto LandmarkUnit : availableLandmarkUnits)
                    {
                        if (LandmarkUnit->getRemainingCapacity() > 0)
                        {
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
Iterator *District::createIterator()
{
    Iterator *it = new ConcreteIterator(this->containedCityUnit);
    return it;
}

/**
 * @brief Calculates the average employment rate for the district.
 * @return The average employment rate as a double.
 */
double District::getEmploymentRate()
{
    if (containedCityUnit.empty())
    {
        return 0.0;
    }

    double totalEmploymentRate = 0.0;
    int divisionCounter = 0;
    for (const auto &unit : containedCityUnit)
    {
        double unitEmploymentRate = unit->getEmploymentRate();
        std::cout << "\n\nBuilding employment rate " << unitEmploymentRate << "\n";
        if (unitEmploymentRate != 0)
        {
            totalEmploymentRate += unitEmploymentRate;
            divisionCounter++;
        }
    }

    return (divisionCounter != 0) ? (totalEmploymentRate / divisionCounter) : 0.0;
}

/**
 * @brief Collects taxes from residents in the district.
 * @return The total amount of tax collected.
 */
double District::payTaxes()
{
    double totalTax = 0.0;
    for (auto unit : containedCityUnit)
    {
        if (Residential *residentialUnit = dynamic_cast<Residential *>(unit))
        {
            for (auto person : residentialUnit->getResidents())
            {
                double tax = (person->getBalance() * this->taxRate);
                totalTax += tax;
                person->takeTax(tax);
            }
        }
    }
    return totalTax * this->educationPolicyMultiplier;
}

/**
 * @brief Evaluates the average happiness level of the district.
 * @return The average happiness as an integer.
 * @throws std::exception if total happiness is negative.
 */
int District::evaluateHappiness()
{
    int totalHappiness = 0;
    int unitCounter = 0;
    for (auto unit : containedCityUnit)
    {
        int evaluatedHappinessForUnit = unit->evaluateHappiness();
        if (evaluatedHappinessForUnit != 0)
        {
            unitCounter++;
            totalHappiness += evaluatedHappinessForUnit;
        }
    }

    if (totalHappiness < 0)
    {
        throw "Negative happiness";
    }

    int averageHappiness = (unitCounter > 0) ? (totalHappiness / unitCounter) : 0;
    float adjustedHappiness = averageHappiness * this->shortweekPolicyMultiplier;
    return std::max(0, std::min(100, static_cast<int>(adjustedHappiness)));
}

/**
 * @brief Counts the total number of citizens in all residential units within the district.
 * @return The total number of citizens.
 */
int District::countCitizens()
{
    int totalCitizens = 0;
    for (auto unit : containedCityUnit)
    {
        if (Residential *residentialUnit = dynamic_cast<Residential *>(unit))
        {
            totalCitizens += residentialUnit->getResidents().size();
        }
    }
    return totalCitizens;
}

/**
 * @brief Sets the tax rate for the district.
 * @param amount The tax rate to be set.
 */
void District::setTaxRate(double amount)
{
    this->taxRate = amount;
}

/**
 * @brief Retrieves the remaining capacity of the District.
 * 
 * @return An integer representing the remaining capacity.
 * @note This is a placeholder implementation that currently returns 0.
 */
int District::getRemainingCapacity()
{
    return 0;
}

/**
 * @brief Calculates the distance from this District to another CityUnit.
 * 
 * @param other A pointer to the CityUnit to calculate the distance to.
 * @return An integer representing the distance to the other CityUnit.
 * @note This is a placeholder implementation that currently returns 0.
 */
int District::calculateDistanceTo(CityUnit *other)
{
    return 0;
}

/**
 * @brief Retrieves the used capacity of the District.
 * 
 * @return An integer representing the used capacity.
 * @note This is a placeholder implementation that currently returns 0.
 */
int District::getUsedCapacity()
{
    return 0;
}


/**
 * @brief Updates the education policy multiplier.
 * @param mult The new multiplier for education policy.
 */
void District::updateEducationMultiplier(float mult)
{
    this->educationPolicyMultiplier = mult;
}

/**
 * @brief Updates the short week policy multiplier.
 * @param mult The new multiplier for the short week policy.
 */
void District::updateWeekMultiplier(float mult)
{
    this->shortweekPolicyMultiplier = mult;
}

/**
 * @brief Evaluates traffic conditions based on residents' travel strategies.
 */
void District::evaluateTrafficConditions()
{
    std::map<std::string, int> travelStrategyMap = {
        {"PublicTransportStrategy", 0},
        {"RailwayStrategy", 0},
        {"RoadStrategy", 0},
        {"AirportStrategy", 0}};

    std::map<std::string, std::string> helperMap = {
        {"PublicTransportStrategy", "progress-public"},
        {"RailwayStrategy", "progress-train"},
        {"RoadStrategy", "progress-car"},
        {"AirportStrategy", "progress-plane"}};

    for (auto unit : containedCityUnit)
    {
        if (Residential *residentialUnit = dynamic_cast<Residential *>(unit))
        {
            for (auto person : residentialUnit->getResidents())
            {
                std::string travelMethod = person->lastUsedStrategyName;
                travelStrategyMap[travelMethod]++;
            }
        }
    }

    int totalCitizenCount = this->countCitizens();
    for (const auto &travelPair : travelStrategyMap)
    {
        double dblRatio = travelPair.second / totalCitizenCount;
        int ratioPercentageInt = static_cast<int>(dblRatio * 100);

        nlohmann::json message = {
            {"type", "valueUpdate"},
            {"data", {{"id", helperMap[travelPair.first]}, {"value", std::to_string(ratioPercentageInt)}}}};

        std::cout << message << std::endl;
        WebSocketNotifier::get_mutable_instance().log(message);
    }
}

/**
 * @brief Generates a JSON representation of the district.
 * @return A JSON object representing the district.
 */
nlohmann::json District::getJSONrepresentation()
{
    nlohmann::json district = {
        {"name", "district_x"},
        {"children", nlohmann::json::array()}};

    for (size_t i = 0; i < containedCityUnit.size(); ++i)
    {
        district["children"].push_back(containedCityUnit[i]->getJSONrepresentation());
    }

    return district;
}

/**
 * @brief Collects resources from all nested CityUnit objects within the district.
 * 
 * This method iterates through all CityUnit objects contained in the district,
 * retrieves their resources, and aggregates them into a single collection.
 * 
 * @return A map containing the aggregated resources, where the keys are resource names
 *         and the values are the total amounts of each resource.
 */
std::map<std::string, int> District::collectResources()
{
    std::map<std::string, int> allResources; ///< Collector for resources

    for (CityUnit* nestedUnit : this->containedCityUnit)
    {
        // Get resources from each contained CityUnit
        std::map<std::string, int> nestedResources = nestedUnit->collectResources();

        // Aggregate resources
        for (const auto& resourcePair : nestedResources)
        {
            allResources[resourcePair.first] += resourcePair.second;
        }
    }

    return allResources;
}

/**
 * @brief Collects utility usage from all nested CityUnit objects within the district.
 * 
 * This method aggregates utility data from all contained CityUnit objects, combining
 * the utility usage into a comprehensive report for the entire district.
 * 
 * @return A map containing the aggregated utilities, where the keys are utility names
 *         and the values are the total usage of each utility.
 */
std::map<std::string, double> District::collectUtilities()
{
    std::map<std::string, double> allUtilities; ///< Collector for utilities

    for (CityUnit* nestedUnit : this->containedCityUnit)
    {
        // Get utilities from each contained CityUnit
        std::map<std::string, double> nestedUtilities = nestedUnit->collectUtilities();

        // Aggregate utility usage
        for (const auto& utilityPair : nestedUtilities)
        {
            allUtilities[utilityPair.first] += utilityPair.second;
        }
    }

    return allUtilities;
}
