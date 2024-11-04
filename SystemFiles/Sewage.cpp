/**
 * @file BuildingFactory.h
 * @brief Defines the BuildingFactory class for creating building objects.
 */

#include "Sewage.h"

 /**
     * @brief Constructs a Sewage object with specified total and used capacity.
     * @param totalCap The total capacity of the sewage system.
     * @param usedCap The current used capacity of the sewage system.
     */
Sewage::Sewage(int totalCap, int usedCap) : Utility(totalCap, usedCap)
{
}

  /**
     * @brief Destructor for the Sewage class.
     * 
     * Cleans up resources used by the Sewage object.
     */
Sewage::~Sewage()
{
}

/**
     * @brief Updates the state of the sewage system.
     * 
     * This method may involve refreshing internal states or triggering
     * updates based on external conditions.
     */
void Sewage::update() {
    this->usedCapacity += 10;
    if(usedCapacity > totalCapacity)
    {
        usedCapacity = totalCapacity;
    }
}

/**
     * @brief Collects resources from the sewage system.
     * @return A map containing the resources collected from the system.
     */
std::map<std::string, int> Sewage::collectResources()
{
    return std::map<std::string, int>();
}

    /**
     * @brief Collects utility data from the sewage system.
     * @return A map containing utility data collected from the system.
     */
std::map<std::string, double> Sewage::collectUtilities()
{
	std::map<std::string, double> utilities;
    utilities["SewageSystem"] = usedCapacity ;
    return utilities;
}

/**
     * @brief Provides a JSON representation of the sewage system.
     * @return A JSON object representing the state of the sewage system.
     */
nlohmann::json Sewage::getJSONrepresentation()
{
    nlohmann::json building = {
        {"name" , "Sewage"},
        {"value", this->totalCapacity}
    };    

    return building;
}
