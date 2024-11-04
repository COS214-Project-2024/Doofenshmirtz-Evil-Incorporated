/**
 * @file CommercialFactory.cpp
 * @brief Implementation of the CommercialFactory class, responsible for creating commercial buildings.
 */

#include "CommercialFactory.h"

/**
 * @brief Constructs a new CommercialFactory instance.
 * 
 * Initializes the cost and resource requirements specific to commercial buildings.
 */
CommercialFactory::CommercialFactory() {
   // std::cout << "Type: Commercial factory" << std::endl;
    cost = 200000; 
    resourceCost["Wood"] = 50;
    resourceCost["Steel"] = 50;
    resourceCost["Concrete"] = 50;
    resourceCost["Bricks"] = 50;
}

/**
 * @brief Factory method for creating a new commercial building.
 * 
 * @return A pointer to a newly created Commercial building object.
 */
Building* CommercialFactory::factoryMethod() {

    // Static engine and distribution to initialize only once
    static std::mt19937 randomEngine(static_cast<unsigned>(std::time(nullptr)));
    static std::uniform_int_distribution<int> dist(80, 120); // Range [80, 120]
    
    int rand = dist(randomEngine); // Generate a random number in the range

    return new Commercial(rand,0);
}

/**
 * @brief Gets the resource cost for creating a commercial building.
 * 
 * @return A map containing resource types as keys and their required quantities as values.
 */
std::map<std::string, int> CommercialFactory::getResourceCost() {
    return resourceCost;
}

/**
 * @brief Destructor for the CommercialFactory class.
 */
CommercialFactory::~CommercialFactory() {
    // Destructor body
}

/**
 * @brief Gets the cost of creating a commercial building.
 * 
 * @return The integer cost for building construction.
 */
int CommercialFactory::getCost() {
    return cost;
}
