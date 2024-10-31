#ifndef RESIDENTIALFACTORY_H
#define RESIDENTIALFACTORY_H

#include "BuildingFactory.h"
#include "Residential.h"
#include <map>
#include <string>

/**
 * @class ResidentialFactory
 * @brief A factory class responsible for creating Residential buildings.
 * 
 * The ResidentialFactory class derives from BuildingFactory and provides the
 * implementation details for creating a Residential building, retrieving its
 * construction cost, and specifying the resources required.
 */
class ResidentialFactory : public BuildingFactory {
protected:
    /**
     * @brief Factory method that creates a Residential building instance.
     * 
     * This method overrides the BuildingFactory factoryMethod to return an
     * instance of the Residential building with predefined specifications.
     * @return A pointer to a newly created Residential building.
     */
    Building* factoryMethod() override;

public:
    /**
     * @brief Constructs a ResidentialFactory with predefined resource requirements.
     * 
     * Initializes the factory with the base cost and resource needs for constructing
     * a Residential building.
     */
    ResidentialFactory();

    /**
     * @brief Destructor for the ResidentialFactory class.
     */
    ~ResidentialFactory();

    /**
     * @brief Retrieves the cost of constructing a Residential building.
     * 
     * This method overrides the BuildingFactory getCost method and returns the
     * monetary cost for creating a Residential structure.
     * @return The cost to construct a Residential building.
     */
    int getCost() override;

    /**
     * @brief Provides the resource costs needed to build a Residential building.
     * 
     * This method returns a map of resource types and their respective quantities
     * required for the construction of a Residential structure.
     * @return A map of resource costs where keys are resource names and values are quantities.
     */
    std::map<std::string, int> getResourceCost() override;
};

#endif // RESIDENTIALFACTORY_H
