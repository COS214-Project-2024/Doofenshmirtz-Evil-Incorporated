#include "IndustrialFactory.h"

/**
 * @class IndustrialFactory
 * @brief Factory class for creating Industrial buildings in the city simulation.
 * 
 * The IndustrialFactory class implements the factory method to create instances
 * of the Industrial building type and provides resource cost details for building
 * industrial structures.
 */

/**
 * @brief Constructs an IndustrialFactory and initializes resource costs.
 * 
 * Sets the base cost for an Industrial building and specifies resource requirements
 * in terms of quantities for Wood, Steel, Concrete, and Brick.
 */
IndustrialFactory::IndustrialFactory() {
   // std::cout << "Type: Industrial factory" << std::endl;
    cost = 50; 
    resourceCost["Wood"] = 300000;
    resourceCost["Steel"] = 50;
    resourceCost["Concrete"] = 50;
    resourceCost["Bricks"] = 50;
}

/**
 * @brief Factory method to create an Industrial building.
 * 
 * @return A pointer to a new Industrial building with preset total capacity, 
 *         initial used capacity, and tax rate.
 */
Building* IndustrialFactory::factoryMethod() {
    return new Industrial(100, 0);
}

/**
 * @brief Retrieves the resource cost for constructing an Industrial building.
 * 
 * @return A map containing the required resource types and their respective costs.
 */
std::map<std::string, int> IndustrialFactory::getResourceCost() {
    return resourceCost;
}

/**
 * @brief Destructor for the IndustrialFactory class.
 */
IndustrialFactory::~IndustrialFactory()
{
}

/**
 * @brief Gets the monetary cost to build an Industrial structure.
 * 
 * @return The construction cost of an Industrial building.
 */
int IndustrialFactory::getCost() {
    return cost;
}
