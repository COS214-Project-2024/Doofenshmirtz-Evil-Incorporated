/**
 * @file CommercialFactory.h
 * @brief Defines the CommercialFactory class for creating commercial building objects.
 */

#ifndef COMMERCIALFACTORY_H
#define COMMERCIALFACTORY_H

#include "BuildingFactory.h"
#include "Commercial.h"

/**
 * @class CommercialFactory
 * @brief Factory class for creating commercial buildings.
 * 
 * The CommercialFactory class is responsible for defining the specific type
 * of building as a commercial building and setting the associated cost and resource requirements.
 */
class CommercialFactory : public BuildingFactory {

protected:
    

    /**
     * @brief Factory method to create a new Commercial building object.
     * 
     * This method is overridden to produce an instance of Commercial.
     * 
     * @return A pointer to a new Commercial building.
     */
    Building* factoryMethod() override;

public:
    /**
     * @brief Gets the resource cost required to construct a commercial building.
     * 
     * @return A map with resource names as keys and their required quantities as values.
     */
    std::map<std::string, int> getResourceCost() override;
    /**
     * @brief Constructs a new CommercialFactory instance.
     * 
     * Initializes the resource and cost values specific to commercial buildings.
     */
    CommercialFactory();

    /**
     * @brief Destructor for the CommercialFactory class.
     */
    ~CommercialFactory();

    /**
     * @brief Gets the cost of constructing a commercial building.
     * 
     * @return An integer representing the cost.
     */
    int getCost() override;
};

#endif // COMMERCIALFACTORY_H
