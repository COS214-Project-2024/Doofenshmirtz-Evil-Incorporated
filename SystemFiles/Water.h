/**
 * @file Water.h
 * @brief Defines the Water class, representing a water utility building.
 * 
 * The Water class extends the Utility class and is responsible for managing 
 * water resources within the city. It provides methods to update the state of 
 * the water plant, collect water resources, and retrieve utility-related data 
 * in JSON format.
 */

#ifndef WATER_H
#define WATER_H

#include "Utility.h"

/**
 * @class Water
 * @brief Represents a water utility building.
 * 
 * This class inherits from the Utility class and implements the functionality 
 * specific to water resource management, including methods to update the 
 * water plant's status and collect relevant resources.
 */
class Water : public Utility {

public:
    /**
     * @brief Constructs a Water object with the specified total and used capacity.
     * 
     * @param totalCap The total capacity of the water utility plant.
     * @param usedCap The amount of capacity currently in use.
     */
    Water(int totalCap, int usedCap);

    /**
     * @brief Destructor for the Water class.
     */
    ~Water();

    /**
     * @brief Updates the state of the water utility plant.
     * 
     * This method provides the logic for updating the water plant's 
     * operational status, such as processing and distributing water.
     */
    void update();

    /**
     * @brief Retrieves the type of utility represented by this water utility plant.
     * 
     * @return A string indicating the type of utility, which is "WaterPlant".
     */
    std::string getUtilityType() const override {
        return "WaterPlant";
    }

    /**
     * @brief Collects resources from the water utility plant.
     * 
     * This method overrides the collectResources method from the Utility class.
     * 
     * @return A map containing the names and quantities of water resources collected.
     */
    std::map<std::string, int> collectResources() override;

    /**
     * @brief Collects utility usage data from the water utility plant.
     * 
     * This method overrides the collectUtilities method from the Utility class.
     * 
     * @return A map containing the types of utilities and their respective quantities related to water management.
     */
    std::map<std::string, double> collectUtilities() override;

    /**
     * @brief Gets a JSON representation of the water utility plant.
     * 
     * This method overrides the getJSONrepresentation method from the Utility class.
     * 
     * @return A JSON object representing the current state of the water utility plant.
     */
    nlohmann::json getJSONrepresentation() override;
};

#endif
