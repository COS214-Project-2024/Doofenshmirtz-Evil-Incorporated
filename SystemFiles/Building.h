/**
 * @file Building.h
 * @brief Defines the Building class for representing and managing buildings in the city.
 */

#ifndef BUILDING_H
#define BUILDING_H

#include "CityUnit.h"
#include <nlohmann/json.hpp>

/**
 * @brief Represents a building within the city.
 * 
 * The Building class is an abstract class derived from CityUnit,
 * providing functionality to manage residents, capacities, and other
 * building-related operations.
 */
class Building : public CityUnit {
public:
    /**
     * @brief Constructs a Building object with specified total and used capacity.
     * 
     * @param totalCap The total capacity of the building.
     * @param usedCap The current used capacity of the building.
     */
    Building(int totalCap, int usedCap);

    /**
     * @brief Destroys the Building object.
     */
    virtual ~Building();

    /**
     * @brief Calculates the distance to another CityUnit.
     * 
     * @param destination A pointer to the CityUnit destination.
     * @return An integer representing the calculated distance.
     */
    int calculateDistanceTo(CityUnit* destination);

    /**
     * @brief Gets the residents of the building.
     * 
     * @return A reference to the vector of residents.
     */
    std::vector<Citizen*>& getResidents();

    /**
     * @brief Gets the remaining capacity of the building.
     * 
     * @return The remaining capacity as an integer.
     * @throws "Value Error: usedCapacity greater that totalCapacity" 
     * if usedCapacity exceeds totalCapacity.
     */
    int getRemainingCapacity();

    /**
     * @brief Gets the currently used capacity of the building.
     * 
     * @return The used capacity as an integer.
     */
    int getUsedCapacity();

    /**
     * @brief Gets the total capacity of the building.
     * 
     * @return The total capacity as an integer.
     */
    int getTotalCapacity() const;

    /**
     * @brief Calculates the employment rate in the building.
     * 
     * This function computes the rate of employed residents.
     * Returns a decimal value between 0 and 1.
     * 
     * @return The employment rate as a double.
     */
    double getEmploymentRate();

    /**
     * @brief Updates the building state.
     * 
     * This is a pure virtual function that must be implemented in derived classes.
     */
    virtual void update() = 0;

    /**
     * @brief Evaluates the happiness of residents in the building.
     * 
     * Calculates the average satisfaction of the residents and returns it.
     * 
     * @return The average satisfaction as an integer.
     * @throws "Value Error: Satisfaction < 0" if total satisfaction is negative.
     */
    virtual int evaluateHappiness();

    /**
     * @brief Counts the number of citizens in the building.
     * 
     * @return The number of citizens as an integer.
     */
    int countCitizens();

    /**
     * @brief Dummy implementations to ensure concrete buildings work as expected.
     * 
     * The following methods are placeholders that can be overridden in derived classes.
     */
    void add(CityUnit* newUnit) {};
    void remove(CityUnit* unit) {};
    void employResidents() {};
    void partyResidents() {};
    Iterator* createIterator() {
        return nullptr;
    };
    void setTaxRate(double amount) {};
    double payTaxes() {
        return 0;
    };

    /**
     * @brief Adds a new resident to the building.
     * 
     * @param newCitizen A pointer to the Citizen object to be added.
     */
    void pushBackResident(Citizen* newCitizen);

    /**
     * @brief Updates the education multiplier for the building.
     * 
     * @param mult The multiplier value to be applied.
     */
    void updateEducationMultiplier(float mult);

    /**
     * @brief Updates the week multiplier for the building.
     * 
     * @param mult The multiplier value to be applied.
     */
    void updateWeekMultiplier(float mult);

    /**
     * @brief Evaluates traffic conditions related to the building.
     * 
     * Implementation for evaluating traffic conditions can be defined as needed.
     */
    void evaluateTrafficConditions();

    /**
     * @brief Collects resources from the building.
     * 
     * This is a pure virtual function that must be implemented in derived classes.
     * 
     * @return A map of resources collected, with resource names as keys and quantities as values.
     */
    virtual std::map<std::string, int> collectResources() = 0;

    /**
     * @brief Collects utility information from the building.
     * 
     * This is a pure virtual function that must be implemented in derived classes.
     * 
     * @return A map of utilities collected, with utility names as keys and values as doubles.
     */
    virtual std::map<std::string, double> collectUtilities() = 0;

    /**
     * @brief Gets a JSON representation of the building.
     * 
     * This is a pure virtual function that must be implemented in derived classes.
     * 
     * @return A JSON object representing the building.
     */
    virtual nlohmann::json getJSONrepresentation() = 0;
};

#endif
