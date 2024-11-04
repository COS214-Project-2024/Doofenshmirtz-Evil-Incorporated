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
    cost = 400000; 
    resourceCost["Wood"] = 0;
    resourceCost["Steel"] = 0;
    resourceCost["Concrete"] = 0;
    resourceCost["Bricks"] = 0;
}

/**
 * @brief Factory method to create an Industrial building.
 * 
 * @return A pointer to a new Industrial building with preset total capacity, 
 *         initial used capacity, and tax rate.
 */
Building* IndustrialFactory::factoryMethod() {

    // Static engine and distribution to initialize only once
    static std::mt19937 randomEngine(static_cast<unsigned>(std::time(nullptr)));
    static std::uniform_int_distribution<int> dist(80, 120); // Range [80, 120]
    
    int rand = dist(randomEngine); // Generate a random number in the range

    return new Industrial(rand, 0);
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
