#include "WasteSiteFactory.h"

/**
 * @class WasteSiteFactory
 * @brief Factory class for creating Waste Site buildings in the city simulation.
 * 
 * The WasteSiteFactory class implements the factory method to create instances
 * of the Waste Site building type and provides resource cost details for building
 * waste management sites.
 */

/**
 * @brief Constructs a WasteSiteFactory and initializes resource costs.
 * 
 * Sets the base cost for a Waste Site building and specifies resource requirements
 * in terms of quantities for Wood, Steel, Concrete, and Brick.
 */
WasteSiteFactory::WasteSiteFactory() {
   // std::cout << "Type: WasteSite factory" << std::endl;
    cost = 50; 
    resourceCost["Wood"] = 50;
    resourceCost["Steel"] = 50;
    resourceCost["Concrete"] = 50;
    resourceCost["Bricks"] = 50;
}

/**
 * @brief Destructor for the WasteSiteFactory class.
 */
WasteSiteFactory::~WasteSiteFactory()
{
}

/**
 * @brief Retrieves the monetary cost to build a Waste Site structure.
 * 
 * @return The construction cost of a Waste Site building.
 */
int WasteSiteFactory::getCost()
{
    return cost;
}

/**
 * @brief Provides the resource costs needed to build a Waste Site building.
 * 
 * @return A map containing the required resource types and their respective costs.
 */
std::map<std::string, int> WasteSiteFactory::getResourceCost()
{
    return resourceCost;
}

/**
 * @brief Factory method to create a Waste Site building.
 * 
 * @return A pointer to a new Waste Site building with preset total capacity, 
 *         initial used capacity, and tax rate.
 */
Building* WasteSiteFactory::factoryMethod() {
    return new Waste(100, 0, 20.0);
}
