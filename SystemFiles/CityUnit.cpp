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