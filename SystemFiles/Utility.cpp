/**
 * @file BuildingFactory.h
 * @brief Defines the BuildingFactory class for creating building objects.
 */

#include "Utility.h"

// Note: This currently calls the parent constructor with a set number. Whoever is implementing this, it should be a random number [10,100]
Utility::Utility(int totalCap, int usedCap) : Building(totalCap, usedCap) {
}

Utility::~Utility()
{
}

std::map<std::string, int> Utility::collectResources() {
    return {}; // Returns an empty map as required
}

std::map<std::string, double> Utility::collectUtilities()
{
return {};
}

nlohmann::json Utility::getJSONrepresentation()
{
    return nlohmann::json();
}
