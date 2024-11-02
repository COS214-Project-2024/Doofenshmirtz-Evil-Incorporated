#include "ResidentialFactory.h"

/**
 * @class ResidentialFactory
 * @brief Factory class for creating Residential buildings in the city simulation.
 * 
 * The ResidentialFactory class implements the factory method to create instances
 * of the Residential building type and provides resource cost details for building
 * residential structures.
 */

/**
 * @brief Constructs a ResidentialFactory and initializes resource costs.
 * 
 * Sets the base cost for a Residential building and specifies resource requirements
 * in terms of quantities for Wood, Steel, Concrete, and Brick.
 */
ResidentialFactory::ResidentialFactory() {
   // std::cout << "Type: Residential factory" << std::endl;
    cost = 50; 
    resourceCost["Wood"] = 50;
    resourceCost["Steel"] = 50;
    resourceCost["Concrete"] = 50;
    resourceCost["Bricks"] = 50;
}

/**
 * @brief Factory method to create a Residential building.
 * 
 * @return A pointer to a new Residential building with preset total capacity, 
 *         initial used capacity, and tax rate.
 */
Building* ResidentialFactory::factoryMethod() {
    return new Residential(100, 0);
}

/**
 * @brief Retrieves the resource cost for constructing a Residential building.
 * 
 * @return A map containing the required resource types and their respective costs.
 */
std::map<std::string, int> ResidentialFactory::getResourceCost() {
    return resourceCost;
}

/**
 * @brief Destructor for the ResidentialFactory class.
 */
ResidentialFactory::~ResidentialFactory()
{
}

/**
 * @brief Gets the monetary cost to build a Residential structure.
 * 
 * @return The construction cost of a Residential building.
 */
int ResidentialFactory::getCost() {
    return cost;
}
