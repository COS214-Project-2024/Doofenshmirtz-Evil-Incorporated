/**
 * @file Landmark.h
 * @brief Defines the Landmark class for creating landmark objects.
 * 
 * This file contains the declaration of the Landmark class, which inherits 
 * from the Building class. The Landmark class is responsible for 
 * generating its JSON representation.
 */

#ifndef LANDMARK_H
#define LANDMARK_H

#include "Building.h"

/**
 * @class Landmark
 * @brief Represents a landmark building in the city simulation.
 * 
 * The Landmark class inherits from the Building class and provides 
 * functionality to manage its total and used capacity, collect 
 * resources, and provide utility data specific to landmarks.
 */
class Landmark : public Building {

public:
    /**
     * @brief Constructs a Landmark object.
     * 
     * @param totalCap The total capacity of the landmark.
     * @param usedCap The currently used capacity of the landmark.
     */
    Landmark(int totalCap, int usedCap);

    /**
     * @brief Destroys the Landmark object.
     */
    ~Landmark();

    /**
     * @brief Updates the state of the landmark.
     * 
     * This function is called to perform any necessary updates 
     * on the landmark, such as recalculating resources or utilities.
     */
    void update();

    /**
     * @brief Collects resources from the landmark.
     * 
     * This function overrides the collectResources function in 
     * the Building class and returns a map of resources collected 
     * from the landmark.
     * 
     * @return std::map<std::string, int> A map containing the 
     * collected resources with their corresponding quantities.
     */
    std::map<std::string, int> collectResources() override;

    /**
     * @brief Collects utility data from the landmark.
     * 
     * This function overrides the collectUtilities function in 
     * the Building class and returns a map of utility data 
     * associated with the landmark.
     * 
     * @return std::map<std::string, double> A map containing 
     * the collected utility data with their corresponding values.
     */
    std::map<std::string, double> collectUtilities() override;

    /**
     * @brief Generates a JSON representation of the landmark.
     * 
     * This function creates a JSON object containing relevant 
     * information about the landmark, which can be used for 
     * visualization purposes in the frontend.
     * 
     * @return nlohmann::json A JSON object representing the 
     * landmark and its properties.
     */
    nlohmann::json getJSONrepresentation();
};

#endif
