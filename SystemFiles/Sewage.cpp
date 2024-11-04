/**
 * @file BuildingFactory.h
 * @brief Defines the BuildingFactory class for creating building objects.
 */

#include "Sewage.h"

Sewage::Sewage(int totalCap, int usedCap) : Utility(totalCap, usedCap)
{
}

Sewage::~Sewage()
{
}

void Sewage::update() {
    this->usedCapacity += 10;
    if(usedCapacity > totalCapacity)
    {
        usedCapacity = totalCapacity;
    }
}

std::map<std::string, int> Sewage::collectResources()
{
    return std::map<std::string, int>();
}

std::map<std::string, double> Sewage::collectUtilities()
{
	std::map<std::string, double> utilities;
    utilities["SewageSystem"] = usedCapacity ;
    return utilities;
}

nlohmann::json Sewage::getJSONrepresentation()
{
    nlohmann::json building = {
        {"name" , "Sewage"},
        {"value", this->totalCapacity}
    };    

    return building;
}
