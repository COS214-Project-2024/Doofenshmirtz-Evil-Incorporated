/**
 * @file IndustrialFactory.h
 * @brief Defines of the IndustrialFactory class for Industrial building creation.
 */

#ifndef INDUSTRIALFACTORY_H
#define INDUSTRIALFACTORY_H

#include "BuildingFactory.h"
#include "Industrial.h"
#include <map>
#include <string>

/**
 * @class IndustrialFactory
 * @brief A factory class responsible for creating Industrial buildings.
 * 
 * The IndustrialFactory class derives from BuildingFactory and provides the
 * implementation details for creating an Industrial building, retrieving its
 * construction cost, and specifying the resources required.
 */
class IndustrialFactory : public BuildingFactory {
protected:
    /**
     * @brief Factory method that creates an Industrial building instance.
     * 
     * This method overrides the BuildingFactory factoryMethod to return an
     * instance of the Industrial building with predefined specifications.
     * @return A pointer to a newly created Industrial building.
     */
    Building* factoryMethod() override;

public:
    /**
     * @brief Constructs an IndustrialFactory with predefined resource requirements.
     * 
     * Initializes the factory with the base cost and resource needs for constructing
     * an Industrial building.
     */
    IndustrialFactory();

    /**
     * @brief Destructor for the IndustrialFactory class.
     */
    ~IndustrialFactory();

    /**
     * @brief Retrieves the cost of constructing an Industrial building.
     * 
     * This method overrides the BuildingFactory getCost method and returns the
     * monetary cost for creating an Industrial structure.
     * @return The cost to construct an Industrial building.
     */
    int getCost() override;

    /**
     * @brief Provides the resource costs needed to build an Industrial building.
     * 
     * This method returns a map of resource types and their respective quantities
     * required for the construction of an Industrial structure.
     * @return A map of resource costs where keys are resource names and values are quantities.
     */
    std::map<std::string, int> getResourceCost() override;
};

#endif // INDUSTRIALFACTORY_H
