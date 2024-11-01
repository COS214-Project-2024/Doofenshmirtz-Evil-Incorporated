#include "CityUnit.h"

CityUnit::CityUnit(int totalCap, int usedCap) : totalCapacity(totalCap), usedCapacity(usedCap){
}

CityUnit::~CityUnit()
{
}

std::map<std::string, int> CityUnit::collectResources() {
    // non-industrial buildings return no resources
    return std::map<std::string, int>();
}

inline void CityUnit::setTaxRate(double amount)
{
    this->taxRate = amount;
}
