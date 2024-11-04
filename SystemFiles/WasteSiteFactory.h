/**
 * @file WasteSiteFactory.h
 * @brief Defines the WasteSiteFactory class for creating Waste building objects.
 */

#ifndef WASTESITEFACTORY_H
#define WASTESITEFACTORY_H

#include "BuildingFactory.h"
#include "Waste.h"
#include <map>
#include <string>

/**
 * @class WasteSiteFactory
 * @brief A factory class responsible for creating Waste Site buildings.
 * 
 * The WasteSiteFactory class derives from BuildingFactory and provides the
 * implementation details for creating a Waste Site building, retrieving its
 * construction cost, and specifying the resources required.
 */
class WasteSiteFactory : public BuildingFactory {
public:
    /**
     * @brief Constructs a WasteSiteFactory with predefined resource requirements.
     * 
     * Initializes the factory with the base cost and resource needs for constructing
     * a Waste Site building.
     */
    WasteSiteFactory();

    /**
     * @brief Destructor for the WasteSiteFactory class.
     */
    ~WasteSiteFactory();

    /**
     * @brief Retrieves the cost of constructing a Waste Site building.
     * 
     * This method overrides the BuildingFactory getCost method and returns the
     * monetary cost for creating a Waste Site structure.
     * @return The cost to construct a Waste Site building.
     */
    int getCost() override;

    /**
     * @brief Provides the resource costs needed to build a Waste Site building.
     * 
     * This method returns a map of resource types and their respective quantities
     * required for the construction of a Waste Site structure.
     * @return A map of resource costs where keys are resource names and values are quantities.
     */
    std::map<std::string, int> getResourceCost() override;

protected:
    /**
     * @brief Factory method that creates a Waste Site building instance.
     * 
     * This method overrides the BuildingFactory factoryMethod to return an
     * instance of the Waste building with predefined specifications.
     * @return A pointer to a newly created Waste building.
     */
    Building* factoryMethod() override;
};

#endif // WASTESITEFACTORY_H
