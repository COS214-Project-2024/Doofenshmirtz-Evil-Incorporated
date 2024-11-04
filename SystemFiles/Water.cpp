/**
 * @file BuildingFactory.h
 * @brief Defines the BuildingFactory class for creating building objects.
 */

#include "Water.h"

 /**
     * @brief Constructs a Water object with the specified total and used capacity.
     * 
     * @param totalCap The total capacity of the water utility plant.
     * @param usedCap The amount of capacity currently in use.
     */
Water::Water(int totalCap, int usedCap) : Utility(totalCap, usedCap)
{
}

/**
     * @brief Destructor for the Water class.
     */
Water::~Water()
{
}

    /**
     * @brief Updates the state of the water utility plant.
     * 
     * This method provides the logic for updating the water plant's 
     * operational status, such as processing and distributing water.
     */
void Water::update() {
    this->usedCapacity += 10;
    if(usedCapacity > totalCapacity)
    {
        usedCapacity = totalCapacity;
    }

}

    /**
     * @brief Collects resources from the water utility plant.
     * 
     * This method overrides the collectResources method from the Utility class.
     * 
     * @return A map containing the names and quantities of water resources collected.
     */
std::map<std::string,int> Water::collectResources()
{
return std::map<std::string,int>();
}

    /**
     * @brief Collects utility usage data from the water utility plant.
     * 
     * This method overrides the collectUtilities method from the Utility class.
     * 
     * @return A map containing the types of utilities and their respective quantities related to water management.
     */
std::map<std::string, double> Water::collectUtilities()
{
	std::map<std::string, double> utilities;
    utilities["WaterPlant"] = usedCapacity ;
    return utilities;
}

    /**
     * @brief Gets a JSON representation of the water utility plant.
     * 
     * This method overrides the getJSONrepresentation method from the Utility class.
     * 
     * @return A JSON object representing the current state of the water utility plant.
     */
nlohmann::json Water::getJSONrepresentation()
{
    nlohmann::json building = {
        {"name" , "Water"},
        {"value", this->totalCapacity}
    };    

    return building;
}
