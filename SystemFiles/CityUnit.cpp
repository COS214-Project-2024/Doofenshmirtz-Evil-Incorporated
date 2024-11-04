/**
 * @file CityUnit.cpp
 * @brief Implements the CityUnit class for creating City composites.
 */


#include "CityUnit.h"
#include <iostream>


CityUnit::CityUnit(int totalCap, int usedCap) 
    : totalCapacity(totalCap), usedCapacity(usedCap), taxRate(0.0) {
    // Constructor initializes total and used capacities and sets tax rate to 0
}

CityUnit::~CityUnit() {
    // Destructor; currently does not manage dynamic memory.
}

/**
 * @brief Sets the tax rate for the city unit.
 * 
 * @param amount The tax rate to be set.
 */
void CityUnit::setTaxRate(double amount) {
    this->taxRate = amount; // Assigns the provided tax rate to the member variable
}