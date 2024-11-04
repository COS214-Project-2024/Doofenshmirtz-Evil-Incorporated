/**
 * @file BuildingFactory.h
 * @brief Defines the BuildingFactory class for creating building objects.
 */

#include "Waste.h"

Waste::Waste(int totalCap, int usedCap) : Utility(totalCap, usedCap)
{
}

Waste::~Waste()
{
}

void Waste::update() {
    this->usedCapacity += 10;
    if(usedCapacity > totalCapacity)
    {
        usedCapacity = totalCapacity;
    }
}

std::map<std::string, int> Waste::collectResources()
{
    return std::map<std::string, int>();
}

std::map<std::string, double> Waste::collectUtilities()
{
	std::map<std::string, double> utilities;
    utilities["WasteSite"] = usedCapacity ;
    return utilities;
}

nlohmann::json Waste::getJSONrepresentation()
{
    nlohmann::json building = {
        {"name" , "Waste"},
        {"value", this->totalCapacity}
    };    

    return building;
}
