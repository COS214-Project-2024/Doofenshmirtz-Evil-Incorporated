#include "Water.h"

Water::Water(int totalCap, int usedCap) : Utility(totalCap, usedCap)
{
}

Water::~Water()
{
}

void Water::update() {
    this->usedCapacity += 10;
    if(usedCapacity > totalCapacity)
    {
        usedCapacity = totalCapacity;
    }

}

std::map<std::string,int> Water::collectResources()
{
return std::map<std::string,int>();
}

std::map<std::string, double> Water::collectUtilities()
{
	std::map<std::string, double> utilities;
    utilities["WaterPlant"] = usedCapacity ;
    return utilities;
}


nlohmann::json Water::getJSONrepresentation()
{
    nlohmann::json building = {
        {"name" , "Water"},
        {"value", this->totalCapacity}
    };    

    return building;
}
