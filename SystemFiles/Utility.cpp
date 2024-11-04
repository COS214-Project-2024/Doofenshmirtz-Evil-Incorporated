/**
 * @file Utility.cpp
 * @brief Implements the Utility class, an abstract base class for utility buildings.
 * 
 * The Utility class represents a type of building that provides essential services 
 * to a city, such as power, water, sewage, etc. It extends the Building class 
 * and defines common behaviors and attributes for all utility buildings.
 */


#include "Utility.h"

// Note: This currently calls the parent constructor with a set number. Whoever is implementing this, it should be a random number [10,100]
 /**
     * @brief Constructs a Utility object with the specified capacity.
     * 
     * @param totalCap The total capacity of the utility building.
     * @param usedCap The amount of capacity currently in use.
     */
Utility::Utility(int totalCap, int usedCap) : Building(totalCap, usedCap) {
}

 /**
     * @brief Virtual destructor for the Utility class.
     */
Utility::~Utility()
{
}

 /**
     * @brief Collects resources from the utility building.
     * 
     * This method overrides the collectResources method from the Building class.
     * 
     * @return A map containing the names and quantities of resources collected.
     */
std::map<std::string, int> Utility::collectResources() {
    return {}; // Returns an empty map as required
}

    /**
     * @brief Collects utility usage data from the utility building.
     * 
     * This method overrides the collectUtilities method from the Building class.
     * 
     * @return A map containing the types of utilities and their respective quantities.
     */
std::map<std::string, double> Utility::collectUtilities()
{
return {};
}

    /**
     * @brief Gets a JSON representation of the utility building.
     * 
     * This method overrides the getJSONrepresentation method from the Building class.
     * 
     * @return A JSON object representing the current state of the utility building.
     */
nlohmann::json Utility::getJSONrepresentation()
{
    return nlohmann::json();
}
