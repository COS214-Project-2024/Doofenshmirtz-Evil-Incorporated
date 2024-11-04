/**
 * @file LandmarkFactory.h
 * @brief Defines the LandmarkFactory class for creating Landmark building objects.
 */

#ifndef LANDMARKFACTORY_H
#define LANDMARKFACTORY_H

#include "BuildingFactory.h"
#include "Landmark.h"
#include <map>
#include <string>

/**
 * @class LandmarkFactory
 * @brief A factory class responsible for creating Landmark buildings.
 * 
 * The LandmarkFactory class derives from BuildingFactory and provides the
 * implementation details for creating a Landmark building, retrieving its
 * construction cost, and specifying the resources required.
 */
class LandmarkFactory : public BuildingFactory {
protected:
    /**
     * @brief Factory method that creates a Landmark building instance.
     * 
     * This method overrides the BuildingFactory factoryMethod to return an
     * instance of the Landmark building with predefined specifications.
     * @return A pointer to a newly created Landmark building.
     */
    Building* factoryMethod() override;

public:
    /**
     * @brief Constructs a LandmarkFactory with predefined resource requirements.
     * 
     * Initializes the factory with the base cost and resource needs for constructing
     * a Landmark building.
     */
    LandmarkFactory();

    /**
     * @brief Destructor for the LandmarkFactory class.
     */
    ~LandmarkFactory();

    /**
     * @brief Retrieves the cost of constructing a Landmark building.
     * 
     * This method overrides the BuildingFactory getCost method and returns the
     * monetary cost for creating a Landmark structure.
     * @return The cost to construct a Landmark building.
     */
    int getCost() override;

    /**
     * @brief Provides the resource costs needed to build a Landmark building.
     * 
     * This method returns a map of resource types and their respective quantities
     * required for the construction of a Landmark structure.
     * @return A map of resource costs where keys are resource names and values are quantities.
     */
    std::map<std::string, int> getResourceCost() override;
};

#endif // LANDMARKFACTORY_H
