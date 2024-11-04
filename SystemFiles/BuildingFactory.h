/**
 * @file BuildingFactory.h
 * @brief Defines the BuildingFactory class for creating building objects.
 */

#ifndef BUILDINGFACTORY_H
#define BUILDINGFACTORY_H

#include "Building.h"
#include <iostream>
#include <map>
#include <string>
#include <random>

/**
 * @class BuildingFactory
 * @brief Abstract factory class for creating buildings.
 * 
 * The BuildingFactory class defines the interface for creating building objects.
 * Derived classes are responsible for defining specific types of buildings and 
 * their associated costs.
 */
class BuildingFactory {

private:
    /// Pointer to the product being created.
    Building* product;

public:
    /**
     * @brief Default constructor for BuildingFactory.
     */
    BuildingFactory();

    /**
     * @brief Builds a building object.
     * 
     * @return A pointer to a Building object.
     */
    Building* build();

    /**
     * @brief Virtual destructor for BuildingFactory.
     */
    virtual ~BuildingFactory();

    /**
     * @brief Gets the cost of the building.
     * 
     * @return The cost of building as an integer.
     */
    virtual int getCost() = 0;

    /**
     * @brief Gets the resource cost of the building.
     * 
     * @return A map of resource names and their associated costs.
     */
    virtual std::map<std::string, int> getResourceCost() = 0;

protected:
    /// The cost of the building.
    int cost = 0;

    /// A map storing resource costs for the building.
    std::map<std::string, int> resourceCost;

    /**
     * @brief Factory method for creating specific building objects.
     * 
     * This method should be implemented by derived classes to create
     * specific types of buildings.
     * 
     * @return A pointer to a Building object.
     */
    virtual Building* factoryMethod() = 0;
};

#endif // BUILDINGFACTORY_H
