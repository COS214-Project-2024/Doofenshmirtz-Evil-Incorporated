/**
 * @file Power.cpp
 * @brief Implements the Power class for Power building objects.
 */

#include "Power.h"

/**
     * @brief Constructs a Power object.
     * 
     * @param totalCap The total capacity of the power plant.
     * @param usedCap The currently used capacity of the power plant.
     */
Power::Power(int totalCap, int usedCap) : Utility(totalCap, usedCap)
{
}

 /**
     * @brief Destroys the Power object.
     */
Power::~Power()
{
}

/**
     * @brief Updates the state of the power plant.
     * 
     * This function is called to perform any necessary updates 
     * on the power plant, such as recalculating resources or utilities.
     */
void Power::update() {
    this->usedCapacity += 10;
    if(usedCapacity > totalCapacity)
    {
        usedCapacity = totalCapacity;
    }
}

/**
     * @brief Collects resources from the power plant.
     * 
     * This function overrides the collectResources function in 
     * the Utility class and returns a map of resources collected 
     * from the power plant.
     * 
     * @return std::map<std::string, int> A map containing the 
     * collected resources with their corresponding quantities.
     */
std::map<std::string, int> Power::collectResources()
{
    return std::map<std::string, int>();
}

 /**
     * @brief Collects utility data from the power plant.
     * 
     * This function overrides the collectUtilities function in 
     * the Utility class and returns a map of utility data 
     * associated with the power plant.
     * 
     * @return std::map<std::string, double> A map containing 
     * the collected utility data with their corresponding values.
     */
std::map<std::string, double> Power::collectUtilities()
{
	std::map<std::string, double> utilities;
    utilities["PowerPlant"] = usedCapacity ;
    return utilities;
}

/**
     * @brief Generates a JSON representation of the power plant.
     * 
     * This function creates a JSON object containing relevant 
     * information about the power plant, which can be used for 
     * visualization purposes in the frontend.
     * 
     * @return nlohmann::json A JSON object representing the 
     * power plant and its properties.
     */
nlohmann::json Power::getJSONrepresentation()
{
    nlohmann::json building = {
        {"name" , "Power"},
        {"value", this->totalCapacity}
    };    

    return building;
}
