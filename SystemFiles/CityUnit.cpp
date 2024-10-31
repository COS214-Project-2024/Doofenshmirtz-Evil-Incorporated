#include "CityUnit.h"

CityUnit::CityUnit(int totalCap, int usedCap, double taxR) : totalCapacity(totalCap), usedCapacity(usedCap), taxRate(taxR) {
}

CityUnit::~CityUnit()
{
}

std::map<std::string, int> CityUnit::collectResources() {
    // non-industrial buildings return no resources
    return std::map<std::string, int>();
}