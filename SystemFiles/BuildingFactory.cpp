/**
 * @file BuildingFactory.cpp
 * @brief Implementation of the BuildingFactory class for building creation.
 */

#include "BuildingFactory.h"

/**
 * @brief Builds a building using the factory method.
 * 
 * This function calls the `factoryMethod()` to create a building object,
 * which can then be added to a city.
 * 
 * @return A pointer to the created Building object.
 */
Building* BuildingFactory::build() {
    product = this->factoryMethod();
    return product;
}

/**
 * @brief Destructor for the BuildingFactory class.
 */
BuildingFactory::~BuildingFactory() {
    // Destructor body
    product = nullptr;
}

/**
 * @brief Constructs a new BuildingFactory instance.
 * 
 * Outputs a message to indicate that a new building has been created.
 */
BuildingFactory::BuildingFactory() {
  //  std::cout << "Created a new building factory" << std::endl;
}
