#include "CityUnit.h"
#include <iostream>

/**
 * @class CityUnit
 * @brief Represents a unit within a city that has a capacity and tax rate.
 * 
 * The CityUnit class manages the total and used capacities and the tax rate 
 * associated with a city unit.
 */

/**
 * @brief Constructs a CityUnit object.
 * 
 * Initializes a CityUnit with specified total and used capacities.
 * @param totalCap The total capacity of the city unit.
 * @param usedCap The current used capacity of the city unit.
 */
CityUnit::CityUnit(int totalCap, int usedCap) : totalCapacity(totalCap), usedCapacity(usedCap) {
}

/**
 * @brief Destructor for the CityUnit class.
 * 
 * Cleans up any resources used by the CityUnit. Currently, it has no 
 * special cleanup needs, but it's provided for potential future use.
 */
CityUnit::~CityUnit() {
}

/**
 * @brief Sets the tax rate for the city unit.
 * 
 * @param amount The new tax rate to be applied.
 */
void CityUnit::setTaxRate(double amount) {
    this->taxRate = amount;
}
