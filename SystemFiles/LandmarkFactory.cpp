/**
 * @file LandmarkFactory.cpp
 * @brief Implements the LandmarkFactory class for creating Landmark building objects.
 */

#include "LandmarkFactory.h"

/**
 * @class LandmarkFactory
 * @brief Factory class for creating Landmark buildings in the city simulation.
 * 
 * The LandmarkFactory class implements the factory method to create instances
 * of the Landmark building type and provides resource cost details for building
 * landmark structures.
 */

/**
 * @brief Constructs a LandmarkFactory and initializes resource costs.
 * 
 * Sets the base cost for a Landmark building and specifies resource requirements
 * in terms of quantities for Wood, Steel, Concrete, and Brick.
 */
LandmarkFactory::LandmarkFactory() {
 //   std::cout << "Type: Landmark factory" << std::endl;
    cost = 180000; 
    resourceCost["Wood"] = 50;
    resourceCost["Steel"] = 50;
    resourceCost["Concrete"] = 50;
    resourceCost["Bricks"] = 50;
}

/**
 * @brief Factory method to create a Landmark building.
 * 
 * @return A pointer to a new Landmark building with preset total capacity, 
 *         initial used capacity, and tax rate.
 */
Building* LandmarkFactory::factoryMethod() {

    // Static engine and distribution to initialize only once
    static std::mt19937 randomEngine(static_cast<unsigned>(std::time(nullptr)));
    static std::uniform_int_distribution<int> dist(80, 120); // Range [80, 120]
    
    int rand = dist(randomEngine); // Generate a random number in the range

    return new Landmark(rand, 0);
}

/**
 * @brief Retrieves the resource cost for constructing a Landmark building.
 * 
 * @return A map containing the required resource types and their respective costs.
 */
std::map<std::string, int> LandmarkFactory::getResourceCost() {
    return resourceCost;
}

/**
 * @brief Destructor for the LandmarkFactory class.
 */
LandmarkFactory::~LandmarkFactory()
{
}

/**
 * @brief Gets the monetary cost to build a Landmark structure.
 * 
 * @return The construction cost of a Landmark building.
 */
int LandmarkFactory::getCost() {
    return cost;
}
