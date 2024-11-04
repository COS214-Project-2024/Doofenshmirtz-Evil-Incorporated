/**
 * @file Residential.h
 * @brief Defines the Residential class, representing residential buildings in the city simulation.
 */

#ifndef RESIDENTIAL_H
#define RESIDENTIAL_H

#include "Building.h"

/**
 * @class Residential
 * @brief Represents a residential building in the city.
 * 
 * The Residential class is a derived class from the Building base class.
 * It encapsulates the properties and behaviors specific to residential buildings,
 * including capacity management and resource collection.
 */
class Residential : public Building {
public:
    /**
 * @brief Constructs a Residential building and fills it with citizens.
 *
 * Initializes the residential unit with a random capacity between 10 and 109,
 * sets the used capacity to the total capacity, and populates the `resident` vector
 * with dynamically allocated `Citizen` objects.
 */
    Residential(int totalCap, int usedCap);

    /**
 * @brief Destructor for the Residential class.
 *
 * Cleans up dynamically allocated `Citizen` objects stored in the `resident` vector
 * and clears the vector to ensure no dangling pointers remain.
 */
    ~Residential();

    /**
 * @brief Updates the state of each resident in the building.
 *
 * Calls the `followRoutine()` method for each `Citizen` in the `resident` vector
 * to update their state as needed.
 */
    void update();

    /**
     * @brief Collects resources from the residential building.
     * @return A map containing the resources collected from the building.
     */
    std::map<std::string, int> collectResources() override;

    /**
     * @brief Provides a JSON representation of the residential building.
     * @return A JSON object representing the state of the building.
     */
    nlohmann::json getJSONrepresentation();

    /**
     * @brief Collects utility data from the residential building.
     * @return A map containing utility data collected from the building.
     */
    std::map<std::string, double> collectUtilities() override;
};

#endif
