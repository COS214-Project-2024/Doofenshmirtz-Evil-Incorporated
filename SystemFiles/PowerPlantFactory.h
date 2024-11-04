/**
 * @file PowerPlantFactory.h
 * @brief Defines the PowerPlantFactory class for creating PowerPlant building objects.
 */

#ifndef POWERPLANTFACTORY_H
#define POWERPLANTFACTORY_H

#include "BuildingFactory.h"
#include "Power.h"
#include <map>
#include <string>

/**
 * @class PowerPlantFactory
 * @brief A factory class responsible for creating Power Plant buildings.
 * 
 * The PowerPlantFactory class derives from BuildingFactory and provides the
 * implementation details for creating a Power Plant building, retrieving its
 * construction cost, and specifying the resources required.
 */
class PowerPlantFactory : public BuildingFactory {
public:
    /**
     * @brief Constructs a PowerPlantFactory with predefined resource requirements.
     * 
     * Initializes the factory with the base cost and resource needs for constructing
     * a Power Plant building.
     */
    PowerPlantFactory();

    /**
     * @brief Destructor for the PowerPlantFactory class.
     */
    ~PowerPlantFactory();

    /**
     * @brief Retrieves the cost of constructing a Power Plant building.
     * 
     * This method overrides the BuildingFactory getCost method and returns the
     * monetary cost for creating a Power Plant structure.
     * @return The cost to construct a Power Plant building.
     */
    int getCost() override;

    /**
     * @brief Provides the resource costs needed to build a Power Plant building.
     * 
     * This method returns a map of resource types and their respective quantities
     * required for the construction of a Power Plant structure.
     * @return A map of resource costs where keys are resource names and values are quantities.
     */
    std::map<std::string, int> getResourceCost() override;

protected:
    /**
     * @brief Factory method that creates a Power Plant building instance.
     * 
     * This method overrides the BuildingFactory factoryMethod to return an
     * instance of the Power Plant building with predefined specifications.
     * @return A pointer to a newly created Power Plant building.
     */
    Building* factoryMethod() override;
};

#endif // POWERPLANTFACTORY_H
