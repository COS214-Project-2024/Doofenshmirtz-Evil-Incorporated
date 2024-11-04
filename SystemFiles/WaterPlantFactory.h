/**
 * @file WaterPlantFactory.h
 * @brief Defines the WaterPlantFactory class for creating Water building objects.
 */


#ifndef WATERPLANTFACTORY_H
#define WATERPLANTFACTORY_H

#include "BuildingFactory.h"
#include "Water.h"
#include <map>
#include <string>

/**
 * @class WaterPlantFactory
 * @brief A factory class responsible for creating Water Plant buildings.
 * 
 * The WaterPlantFactory class derives from BuildingFactory and provides the
 * implementation details for creating a Water Plant building, retrieving its
 * construction cost, and specifying the resources required.
 */
class WaterPlantFactory : public BuildingFactory {
public:
    /**
     * @brief Constructs a WaterPlantFactory with predefined resource requirements.
     * 
     * Initializes the factory with the base cost and resource needs for constructing
     * a Water Plant building.
     */
    WaterPlantFactory();

    /**
     * @brief Destructor for the WaterPlantFactory class.
     */
    ~WaterPlantFactory();

    /**
     * @brief Retrieves the cost of constructing a Water Plant building.
     * 
     * This method overrides the BuildingFactory getCost method and returns the
     * monetary cost for creating a Water Plant structure.
     * @return The cost to construct a Water Plant building.
     */
    int getCost() override;

    /**
     * @brief Provides the resource costs needed to build a Water Plant building.
     * 
     * This method returns a map of resource types and their respective quantities
     * required for the construction of a Water Plant structure.
     * @return A map of resource costs where keys are resource names and values are quantities.
     */
    std::map<std::string, int> getResourceCost() override;

protected:
    /**
     * @brief Factory method that creates a Water Plant building instance.
     * 
     * This method overrides the BuildingFactory factoryMethod to return an
     * instance of the Water building with predefined specifications.
     * @return A pointer to a newly created Water building.
     */
    Building* factoryMethod() override;
};

#endif // WATERPLANTFACTORY_H
