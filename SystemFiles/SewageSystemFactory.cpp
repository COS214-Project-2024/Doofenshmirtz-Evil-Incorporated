/**
 * @file SewageSystemFactory.cpp
 * @brief Implements the SewageSystemFactory class for creating SewageSystemFactory objects.
 */

#include "SewageSystemFactory.h"

/**
 * @class SewageSystemFactory
 * @brief Factory class for creating Sewage System buildings in the city simulation.
 * 
 * The SewageSystemFactory class implements the factory method to create instances
 * of the Sewage System building type and provides resource cost details for building
 * sewage systems.
 */

/**
 * @brief Constructs a SewageSystemFactory and initializes resource costs.
 * 
 * Sets the base cost for a Sewage System building and specifies resource requirements
 * in terms of quantities for Wood, Steel, Concrete, and Brick.
 */
SewageSystemFactory::SewageSystemFactory() {
   // std::cout << "Type: SewageSystem factory" << std::endl;
    cost = 220000; 
    resourceCost["Wood"] = 50;
    resourceCost["Steel"] = 50;
    resourceCost["Concrete"] = 50;
    resourceCost["Bricks"] = 50;
}

/**
 * @brief Destructor for the SewageSystemFactory class.
 */
SewageSystemFactory::~SewageSystemFactory()
{
}

/**
 * @brief Retrieves the monetary cost to build a Sewage System structure.
 * 
 * @return The construction cost of a Sewage System building.
 */
int SewageSystemFactory::getCost()
{
    return cost;
}

/**
 * @brief Provides the resource costs needed to build a Sewage System building.
 * 
 * @return A map containing the required resource types and their respective costs.
 */
std::map<std::string, int> SewageSystemFactory::getResourceCost()
{
    return resourceCost;
}

/**
 * @brief Factory method to create a Sewage System building.
 * 
 * @return A pointer to a new Sewage System building with preset total capacity, 
 *         initial used capacity, and tax rate.
 */
Building* SewageSystemFactory::factoryMethod() {

    // Static engine and distribution to initialize only once
    static std::mt19937 randomEngine(static_cast<unsigned>(std::time(nullptr)));
    static std::uniform_int_distribution<int> dist(80, 120); // Range [80, 120]
    
    int rand = dist(randomEngine); // Generate a random number in the range

    return new Sewage(rand, 0);
}
