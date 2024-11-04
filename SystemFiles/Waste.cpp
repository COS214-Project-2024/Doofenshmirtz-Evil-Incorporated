/**
 * @file Waste.cpp
 * @brief Implements the Waste class, representing a waste management utility building.
 * 
 * The Waste class extends the Utility class and is responsible for managing waste 
 * resources within the city. It provides methods to update the state of the waste 
 * site, collect waste resources, and retrieve utility-related data in JSON format.
 */

#include "Waste.h"

  /**
     * @brief Constructs a Waste object with the specified total and used capacity.
     * 
     * @param totalCap The total capacity of the waste management site.
     * @param usedCap The amount of capacity currently in use.
     */
Waste::Waste(int totalCap, int usedCap) : Utility(totalCap, usedCap)
{
}

  /**
     * @brief Destructor for the Waste class.
     */
Waste::~Waste()
{
}

 /**
     * @brief Updates the state of the waste management site.
     * 
     * This method provides the logic for updating the waste site's 
     * operational status, such as processing waste.
     */
void Waste::update() {
    this->usedCapacity += 10;
    if(usedCapacity > totalCapacity)
    {
        usedCapacity = totalCapacity;
    }
}

   /**
     * @brief Collects resources from the waste management site.
     * 
     * This method overrides the collectResources method from the Utility class.
     * 
     * @return A map containing the names and quantities of waste resources collected.
     */
std::map<std::string, int> Waste::collectResources()
{
    return std::map<std::string, int>();
}

  /**
     * @brief Collects utility usage data from the waste management site.
     * 
     * This method overrides the collectUtilities method from the Utility class.
     * 
     * @return A map containing the types of utilities and their respective quantities related to waste management.
     */
std::map<std::string, double> Waste::collectUtilities()
{
	std::map<std::string, double> utilities;
    utilities["WasteSite"] = usedCapacity ;
    return utilities;
}

    /**
     * @brief Gets a JSON representation of the waste management site.
     * 
     * This method overrides the getJSONrepresentation method from the Utility class.
     * 
     * @return A JSON object representing the current state of the waste management site.
     */
nlohmann::json Waste::getJSONrepresentation()
{
    nlohmann::json building = {
        {"name" , "Waste"},
        {"value", this->totalCapacity}
    };    

    return building;
}
