/**
 * @file Power.cpp
 * @brief Implements the Power class for Power building objects.
 */

#ifndef POWER_H
#define POWER_H

#include "Utility.h"

/**
 * @class Power
 * @brief Represents a power plant utility in the city simulation.
 * 
 * The Power class inherits from the Utility class and provides 
 * functionality to manage its total and used capacity, collect 
 * resources, and provide utility data specific to power plants.
 */
class Power : public Utility {

public:
    /**
     * @brief Constructs a Power object.
     * 
     * @param totalCap The total capacity of the power plant.
     * @param usedCap The currently used capacity of the power plant.
     */
    Power(int totalCap, int usedCap);

    /**
     * @brief Destroys the Power object.
     */
    ~Power();

    /**
     * @brief Updates the state of the power plant.
     * 
     * This function is called to perform any necessary updates 
     * on the power plant, such as recalculating resources or utilities.
     */
    void update();

    /**
     * @brief Gets the type of utility.
     * 
     * This function overrides the getUtilityType function in 
     * the Utility class and returns the type of this utility.
     * 
     * @return std::string The type of the utility as a string ("PowerPlant").
     */
    std::string getUtilityType() const override {
        return "PowerPlant";
    }

    /**
     * @brief Collects resources from the power plant.
     * 
     * This function overrides the collectResources function in 
     * the Utility class and returns a map of resources collected 
     * from the power plant.
     * 
     * @return std::map<std::string, int> A map containing the 
     * collected resources with their corresponding quantities.
     */
    std::map<std::string, int> collectResources() override;

    /**
     * @brief Collects utility data from the power plant.
     * 
     * This function overrides the collectUtilities function in 
     * the Utility class and returns a map of utility data 
     * associated with the power plant.
     * 
     * @return std::map<std::string, double> A map containing 
     * the collected utility data with their corresponding values.
     */
    std::map<std::string, double> collectUtilities() override;

    /**
     * @brief Generates a JSON representation of the power plant.
     * 
     * This function creates a JSON object containing relevant 
     * information about the power plant, which can be used for 
     * visualization purposes in the frontend.
     * 
     * @return nlohmann::json A JSON object representing the 
     * power plant and its properties.
     */
    nlohmann::json getJSONrepresentation() override;
};

#endif
