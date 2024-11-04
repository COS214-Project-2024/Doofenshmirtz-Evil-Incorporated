/**
 * @file District.h
 * @brief Defines the District class for managing a collection of CityUnit objects.
 * 
 * The District class is a composite structure that allows for the management of multiple
 * CityUnit objects, such as buildings and landmarks, within a city simulation. It provides
 * methods for adding, removing, and updating units, as well as collecting resources and utilities.
 */


#ifndef DISTRICT_H
#define DISTRICT_H

#include "CityUnit.h"
#include "ConcreteIterator.h"

/**
 * @class District
 * @brief A class that represents a district composed of multiple CityUnits.
 * 
 * Inherits from CityUnit and manages a collection of nested city units.
 * The class provides functionality for adding, removing, and managing
 * CityUnits, as well as policy-based updates and resource collection.
 */
class District : public CityUnit {

private:
    std::vector<CityUnit*> containedCityUnit; ///< Collection of CityUnits within the district.
    float educationPolicyMultiplier = 1; ///< Multiplier for education-related policies.
    float shortweekPolicyMultiplier = 1; ///< Multiplier for short workweek policies.

public:
    /**
     * @brief Constructs a new District object.
     */
    District();

    /**
     * @brief Adds a new CityUnit to the district.
     * @param newUnit Pointer to the CityUnit to be added.
     */
    void add(CityUnit* newUnit);

    /**
     * @brief Removes a specified CityUnit from the district.
     * @param unit Pointer to the CityUnit to be removed.
     * @throws std::exception if the unit is not found in the district.
     */
    void remove(CityUnit* unit);

    /**
     * @brief Destructor for the District class.
     * 
     * Cleans up dynamically allocated CityUnits and clears the containedCityUnit vector.
     */
    ~District();

    /**
     * @brief Updates all CityUnits in the district.
     * 
     * Also employs residents based on available employment slots.
     */
    void update();

    /**
     * @brief Employs residents from residential units in commercial units with available jobs.
     */
    void employResidents();

    /**
     * @brief Allows residents to relax at available landmark units.
     */
    void partyResidents();

    /**
     * @brief Creates an iterator for the district.
     * @return A pointer to the created Iterator.
     */
    Iterator* createIterator();

    /**
     * @brief Calculates the average employment rate for the district.
     * @return The average employment rate as a double.
     */
    double getEmploymentRate();

    /**
     * @brief Collects taxes from all residents in the district.
     * @return The total amount of tax collected.
     */
    double payTaxes();

    /**
     * @brief Evaluates the average happiness level of the district.
     * @return The average happiness as an integer.
     * @throws std::exception if the total happiness is negative.
     */
    int evaluateHappiness();

    /**
     * @brief Counts the total number of citizens in all residential units.
     * @return The total number of citizens.
     */
    int countCitizens();

    /**
     * @brief Sets the tax rate for the district.
     * @param amount The tax rate to be set.
     */
    void setTaxRate(double amount);

    /**
     * @brief Calculates the distance to another CityUnit.
     * @param other Pointer to the other CityUnit.
     * @return The distance as an integer.
     * @note This is a placeholder implementation.
     */
    int calculateDistanceTo(CityUnit* other) override;

    /**
     * @brief Gets the remaining capacity of the district.
     * @return The remaining capacity as an integer.
     * @note This is a placeholder implementation.
     */
    int getRemainingCapacity() override {
        // Placeholder implementation
        return 0;
    }

    /**
     * @brief Gets the used capacity of the district.
     * @return The used capacity as an integer.
     * @note This is a placeholder implementation.
     */
    int getUsedCapacity() override {
        // Placeholder implementation
        return 0;
    }

    /**
     * @brief Updates the education policy multiplier.
     * @param mult The new multiplier value.
     */
    void updateEducationMultiplier(float mult);

    /**
     * @brief Updates the short workweek policy multiplier.
     * @param mult The new multiplier value.
     */

    void updateWeekMultiplier(float mult);

    /**
     * @brief Evaluates the traffic conditions based on residents' travel strategies.
     */
    void evaluateTrafficConditions();

    /**
     * @brief Generates a JSON representation of the district.
     * @return A JSON object representing the district and its CityUnits.
     */
    nlohmann::json getJSONrepresentation();

    /**
     * @brief Collects resources from all CityUnits within the district.
     * @return A map of resource names to their respective quantities.
     */
    std::map<std::string, int> collectResources() override;

    /**
     * @brief Collects utilities from all CityUnits within the district.
     * @return A map of utility names to their respective quantities.
     */
    std::map<std::string, double> collectUtilities() override;
};

#endif
