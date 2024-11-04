/**
 * @file BuildingFactory.h
 * @brief Defines the BuildingFactory class for creating building objects.
 */

#include "CityUnit.h"
#include <iostream>

CityUnit::CityUnit(int totalCap, int usedCap) : totalCapacity(totalCap), usedCapacity(usedCap){
}

CityUnit::~CityUnit()
{
}


void CityUnit::setTaxRate(double amount)
{
    this->taxRate = amount;
}
