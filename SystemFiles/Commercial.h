/**
 * @file Commercial.h
 * @brief Defines the Commercial class for creating commercial building objects.
 */

#ifndef COMMERCIAL_H
#define COMMERCIAL_H

#include "Building.h"

/**
 * @class Commercial
 * @brief Represents a commercial building in the city.
 * 
 * The Commercial class inherits from the Building class and implements 
 * functionalities specific to commercial buildings, such as updating salaries
 * for residents, collecting resources, and providing JSON representation.
 */
class Commercial : public Building {
public:
    /**
     * @brief Constructor for the Commercial class.
     * 
     * Initializes a commercial building with specified total and used capacity.
     * 
     * @param totalCap The total capacity of the commercial building.
     * @param usedCap The currently used capacity of the commercial building.
     */
    Commercial(int totalCap, int usedCap);

    /**
     * @brief Destructor for the Commercial class.
     * 
     * Cleans up resources associated with the Commercial building.
     */
    ~Commercial();

    /**
     * @brief Updates the state of the commercial building.
     * 
     * This method assigns a random salary to each resident of the building.
     */
    void update();

    /**
     * @brief Collects resources from the commercial building.
     * 
     * This method currently does not implement resource collection and returns an empty map.
     * 
     * @return A map of resource names and their quantities (currently empty).
     */
    std::map<std::string, int> collectResources() override;

    /**
     * @brief Collects utility usage data from the commercial building.
     * 
     * This method currently does not implement utility collection and returns an empty map.
     * 
     * @return A map of utility types and their usage (currently empty).
     */
    std::map<std::string, double> collectUtilities() override;

    /**
     * @brief Gets the JSON representation of the commercial building.
     * 
     * Constructs a JSON object that includes the name of the building
     * and its total capacity.
     * 
     * @return A nlohmann::json object representing the commercial building.
     */
    nlohmann::json getJSONrepresentation();
};

#endif
