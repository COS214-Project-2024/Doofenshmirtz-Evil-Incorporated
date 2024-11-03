#include "Power.h"

Power::Power(int totalCap, int usedCap) : Utility(totalCap, usedCap)
{
}

Power::~Power()
{
}

void Power::update() {
    this->usedCapacity += 10;
    if(usedCapacity > totalCapacity)
    {
        usedCapacity = totalCapacity;
    }
}

std::map<std::string, int> Power::collectResources()
{
    return std::map<std::string, int>();
}

std::map<std::string, double> Power::collectUtilities()
{
	std::map<std::string, double> utilities;
    utilities["PowerPlant"] = usedCapacity ;
    return utilities;
}

nlohmann::json Power::getJSONrepresentation()
{
    nlohmann::json building = {
        {"name" , "Power"},
        {"value", this->totalCapacity}
    };    

    return building;
}
