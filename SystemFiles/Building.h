#ifndef BUILDING_H
#define BUILDING_H

#include "CityUnit.h"
#include <nlohmann/json.hpp>

/**
 * @class Building
 * @brief Represents a building within a city unit.
 * 
 * The Building class inherits from CityUnit and provides functionality 
 * for managing residents, calculating capacities, and evaluating 
 * various building metrics.
 */
class Building : public CityUnit {
public:
    /**
     * @brief Constructs a Building object.
     * 
     * Initializes a Building with specified total and used capacities.
     * @param totalCap The total capacity of the building.
     * @param usedCap The current used capacity of the building.
     */
    Building(int totalCap, int usedCap);

    /**
     * @brief Destructor for the Building class.
     * 
     * Cleans up any resources used by the Building, particularly the 
     * residents.
     */
    virtual ~Building();

    /**
     * @brief Calculates the distance to a specified destination CityUnit.
     * 
     * @param destination A pointer to the destination CityUnit.
     * @return An integer representing the distance to the destination.
     */
    int calculateDistanceTo(CityUnit* destination);

    /**
     * @brief Gets a reference to the vector of residents in the building.
     * 
     * @return A vector of pointers to Citizen objects representing the residents.
     */
    std::vector<Citizen*>& getResidents();

    /**
     * @brief Gets the remaining capacity of the building.
     * 
     * @return The remaining capacity as an integer.
     * @throws const char* If usedCapacity is greater than totalCapacity.
     */
    int getRemainingCapacity();

    /**
     * @brief Gets the used capacity of the building.
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
     * @brief Calculates the employment rate of citizens in the building.
     * 
     * @return A decimal value between 0 and 1 representing the employment rate.
     */
    double getEmploymentRate();

    /**
     * @brief Abstract method to update the building's state.
     */
    virtual void update() = 0;

    /**
     * @brief Evaluates the happiness level of residents in the building.
     * 
     * @return The average happiness level of residents.
     * @throws const char* If the total satisfaction is negative.
     */
    virtual int evaluateHappiness();

    /**
     * @brief Counts the number of citizens in the building.
     * 
     * @return The total number of citizens as an integer.
     */
    int countCitizens();

    /**
     * @brief Adds a new Citizen to the building.
     * 
     * @param newCitizen A pointer to the Citizen to be added.
     */
    void pushBackResident(Citizen* newCitizen);

    /**
     * @brief Updates the education multiplier for the building.
     * 
     * @param mult The new education multiplier to be applied.
     */
    void updateEducationMultiplier(float mult);

    /**
     * @brief Updates the week multiplier for the building.
     * 
     * @param mult The new week multiplier to be applied.
     */
    void updateWeekMultiplier(float mult);

    /**
     * @brief Evaluates traffic conditions related to the building.
     */
    void evaluateTrafficConditions();

    /**
     * @brief Collects resources from the building.
     * 
     * @return A map of resource names to their quantities.
     */
    virtual std::map<std::string, int> collectResources() = 0;

    /**
     * @brief Collects utilities from the building.
     * 
     * @return A map of utility names to their values.
     */
    virtual std::map<std::string, double> collectUtilities() = 0;

    /**
     * @brief Gets a JSON representation of the building.
     * 
     * @return A nlohmann::json object representing the building.
     */
    virtual nlohmann::json getJSONrepresentation() = 0;

    /**
     * @brief Dummy implementations to ensure concrete buildings work as expected.
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
};

#endif // BUILDING_H
