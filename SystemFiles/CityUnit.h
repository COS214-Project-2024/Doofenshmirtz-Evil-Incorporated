/**
 * @file CityUnit.h
 * @brief Defines the CityUnit class, which represents a unit in the city with various properties and functionalities.
 */

#ifndef CITYUNIT_H
#define CITYUNIT_H

#include <vector>
#include <map>
#include "Citizen.h"
#include "Iterator.h"
#include <nlohmann/json.hpp>

/**
 * @class CityUnit
 * @brief Abstract base class representing a unit within the city, such as buildings or districts.
 */
class CityUnit {
protected:
    int totalCapacity;              ///< Total capacity of the city unit
    int usedCapacity;               ///< Currently used capacity of the city unit
    std::vector<Citizen*> resident; ///< List of residents (Citizens) living in the city unit
    double taxRate = 0.1;           ///< Tax rate applicable to the city unit

    /**
     * @brief Protected constructor to prevent direct instantiation of CityUnit.
     * 
     * @param totalCap The total capacity of the city unit.
     * @param usedCap The currently used capacity of the city unit.
     */
    CityUnit(int totalCap, int usedCap);

public:
    /**
     * @brief Virtual destructor for the CityUnit class.
     * 
     * This destructor cleans up resources associated with the CityUnit.
     */
    virtual ~CityUnit();

    /**
     * @brief Adds a new city unit to this unit (pure virtual function).
     * 
     * @param newUnit Pointer to the CityUnit to be added.
     */
    virtual void add(CityUnit* newUnit) = 0;

    /**
     * @brief Removes a city unit from this unit (pure virtual function).
     * 
     * @param unit Pointer to the CityUnit to be removed.
     */
    virtual void remove(CityUnit* unit) = 0;

    /**
     * @brief Calculates the distance to another city unit (pure virtual function).
     * 
     * @param destination Pointer to the destination CityUnit.
     * @return The distance to the destination.
     */
    virtual int calculateDistanceTo(CityUnit* destination) = 0;

    /**
     * @brief Retrieves a list of residents living in this city unit.
     * 
     * @return A reference to a vector containing pointers to the residents.
     */
    virtual std::vector<Citizen*>& getResidents() {
        static std::vector<Citizen*> emptyList;  ///< An empty list for units without residents
        return emptyList;

    }

    /**
     * @brief Gets the remaining capacity of the city unit (pure virtual function).
     * 
     * @return The remaining capacity.
     */
    virtual int getRemainingCapacity() = 0;

    /**
     * @brief Gets the used capacity of the city unit (pure virtual function).
     * 
     * @return The currently used capacity.
     */
    virtual int getUsedCapacity() = 0;

    /**
     * @brief Updates the state or status of the city unit (pure virtual function).
     */
    virtual void update() = 0;

    /**
     * @brief Employs residents of the city unit (pure virtual function).
     */
    virtual void employResidents() = 0;

    /**
     * @brief Organizes a party for the residents of the city unit (pure virtual function).
     */
    virtual void partyResidents() = 0;

    /**
     * @brief Creates an iterator for the city unit (pure virtual function).
     * 
     * @return A pointer to the created Iterator.
     */
    virtual Iterator* createIterator() = 0;

    /**
     * @brief Calculates the employment rate of the residents (pure virtual function).
     * 
     * @return The employment rate as a double.
     */
    virtual double getEmploymentRate() = 0;

    /**
     * @brief Sets the tax rate for the city unit.
     * 
     * @param amount The tax rate to be set.
     */
    void setTaxRate(double amount);

    /**
     * @brief Collects taxes from residents (pure virtual function).
     * 
     * @return The total taxes collected as a double.
     */
    virtual double payTaxes() = 0;

    /**
     * @brief Evaluates the happiness of the residents (pure virtual function).
     * 
     * @return The average happiness score of the residents.
     */
    virtual int evaluateHappiness() = 0;

    /**
     * @brief Counts the number of citizens residing in the city unit (pure virtual function).
     * 
     * @return The number of citizens.
     */
    virtual int countCitizens() = 0;

    /**
     * @brief Collects resources from the city unit (pure virtual function).
     * 
     * @return A map of resource names and their respective quantities.
     */
    virtual std::map<std::string, int> collectResources() = 0;

    /**
     * @brief Collects utility usage data from the city unit (pure virtual function).
     * 
     * @return A map of utility types and their respective usage as doubles.
     */
    virtual std::map<std::string, double> collectUtilities() = 0;

    /**
     * @brief Updates the education multiplier for the city unit (pure virtual function).
     * 
     * @param mult The multiplier value to be applied.
     */
    virtual void updateEducationMultiplier(float mult) = 0;

    /**
     * @brief Updates the weekly multiplier for the city unit (pure virtual function).
     * 
     * @param mult The multiplier value to be applied.
     */
    virtual void updateWeekMultiplier(float mult) = 0;

    /**
     * @brief Evaluates traffic conditions around the city unit (pure virtual function).
     */
    virtual void evaluateTrafficConditions() = 0;

    /**
     * @brief Gets the JSON representation of the city unit (pure virtual function).
     * 
     * @return A nlohmann::json object representing the city unit.
     */
    virtual nlohmann::json getJSONrepresentation() = 0;
	
    /**
     * @brief Capacity used of building setter
     *
     */
	  void setUsedCapacity(int val){
		  this->usedCapacity = val;
	  }

};

#endif // CITYUNIT_H
