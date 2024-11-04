/**
 * @file WaterPlantFactory.cpp
 * @brief Implements the WaterPlantFactory class for creating Water building objects.
 */

#include "WaterPlantFactory.h"

/**
 * @class WaterPlantFactory
 * @brief Factory class for creating Water Plant buildings in the city simulation.
 * 
 * The WaterPlantFactory class implements the factory method to create instances
 * of the Water Plant building type and provides resource cost details for building
 * water treatment facilities.
 */

/**
 * @brief Constructs a WaterPlantFactory and initializes resource costs.
 * 
 * Sets the base cost for a Water Plant building and specifies resource requirements
 * in terms of quantities for Wood, Steel, Concrete, and Brick.
 */
WaterPlantFactory::WaterPlantFactory() {
    //std::cout << "Type: Waterplant factory" << std::endl;
    cost = 380000; 
    resourceCost["Wood"] = 50;
    resourceCost["Steel"] = 50;
    resourceCost["Concrete"] = 50;
    resourceCost["Bricks"] = 50;
}

/**
 * @brief Destructor for the WaterPlantFactory class.
 */
WaterPlantFactory::~WaterPlantFactory()
{
}

/**
 * @brief Retrieves the monetary cost to build a Water Plant structure.
 * 
 * @return The construction cost of a Water Plant building.
 */
int WaterPlantFactory::getCost()
{
    return cost;
}

/**
 * @brief Provides the resource costs needed to build a Water Plant building.
 * 
 * @return A map containing the required resource types and their respective costs.
 */
std::map<std::string, int> WaterPlantFactory::getResourceCost()
{
    return resourceCost;
}

/**
 * @brief Factory method to create a Water Plant building.
 * 
 * @return A pointer to a new Water Plant building with preset total capacity, 
 *         initial used capacity, and tax rate.
 */
Building* WaterPlantFactory::factoryMethod() {

    // Static engine and distribution to initialize only once
    static std::mt19937 randomEngine(static_cast<unsigned>(std::time(nullptr)));
    static std::uniform_int_distribution<int> dist(80, 120); // Range [80, 120]
    
    int rand = dist(randomEngine); // Generate a random number in the range

    return new Water(rand, 0);
}
