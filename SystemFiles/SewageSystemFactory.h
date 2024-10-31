#ifndef SEWAGESYSTEMFACTORY_H
#define SEWAGESYSTEMFACTORY_H

#include "BuildingFactory.h"
#include "Sewage.h"
#include <map>
#include <string>

/**
 * @class SewageSystemFactory
 * @brief A factory class responsible for creating Sewage System buildings.
 * 
 * The SewageSystemFactory class derives from BuildingFactory and provides the
 * implementation details for creating a Sewage System building, retrieving its
 * construction cost, and specifying the resources required.
 */
class SewageSystemFactory : public BuildingFactory {
public:
    /**
     * @brief Constructs a SewageSystemFactory with predefined resource requirements.
     * 
     * Initializes the factory with the base cost and resource needs for constructing
     * a Sewage System building.
     */
    SewageSystemFactory();

    /**
     * @brief Destructor for the SewageSystemFactory class.
     */
    ~SewageSystemFactory();

    /**
     * @brief Retrieves the cost of constructing a Sewage System building.
     * 
     * This method overrides the BuildingFactory getCost method and returns the
     * monetary cost for creating a Sewage System structure.
     * @return The cost to construct a Sewage System building.
     */
    int getCost() override;

    /**
     * @brief Provides the resource costs needed to build a Sewage System building.
     * 
     * This method returns a map of resource types and their respective quantities
     * required for the construction of a Sewage System structure.
     * @return A map of resource costs where keys are resource names and values are quantities.
     */
    std::map<std::string, int> getResourceCost() override;

protected:
    /**
     * @brief Factory method that creates a Sewage System building instance.
     * 
     * This method overrides the BuildingFactory factoryMethod to return an
     * instance of the Sewage building with predefined specifications.
     * @return A pointer to a newly created Sewage building.
     */
    Building* factoryMethod() override;
};

#endif // SEWAGESYSTEMFACTORY_H
