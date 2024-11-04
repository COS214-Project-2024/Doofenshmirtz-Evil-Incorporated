/**
 * @file Waste.h
 * @brief Defines the Waste class, representing a waste management utility building.
 * 
 * The Waste class extends the Utility class and is responsible for managing waste 
 * resources within the city. It provides methods to update the state of the waste 
 * site, collect waste resources, and retrieve utility-related data in JSON format.
 */

#ifndef WASTE_H
#define WASTE_H

#include "Utility.h"

/**
 * @class Waste
 * @brief Represents a waste management utility building.
 * 
 * This class inherits from the Utility class and implements the functionality 
 * specific to waste management, including methods to update the waste site's 
 * status and collect relevant resources.
 */
class Waste : public Utility {

public:
    /**
     * @brief Constructs a Waste object with the specified total and used capacity.
     * 
     * @param totalCap The total capacity of the waste management site.
     * @param usedCap The amount of capacity currently in use.
     */
    Waste(int totalCap, int usedCap);

    /**
     * @brief Destructor for the Waste class.
     */
    ~Waste();

    /**
     * @brief Updates the state of the waste management site.
     * 
     * This method provides the logic for updating the waste site's 
     * operational status, such as processing waste.
     */
    void update();

    /**
     * @brief Retrieves the type of utility represented by this waste management site.
     * 
     * @return A string indicating the type of utility, which is "WasteSite".
     */
    std::string getUtilityType() const override {
        return "WasteSite";
    }

    /**
     * @brief Collects resources from the waste management site.
     * 
     * This method overrides the collectResources method from the Utility class.
     * 
     * @return A map containing the names and quantities of waste resources collected.
     */
    std::map<std::string, int> collectResources() override;

    /**
     * @brief Collects utility usage data from the waste management site.
     * 
     * This method overrides the collectUtilities method from the Utility class.
     * 
     * @return A map containing the types of utilities and their respective quantities related to waste management.
     */
    std::map<std::string, double> collectUtilities() override;

    /**
     * @brief Gets a JSON representation of the waste management site.
     * 
     * This method overrides the getJSONrepresentation method from the Utility class.
     * 
     * @return A JSON object representing the current state of the waste management site.
     */
    nlohmann::json getJSONrepresentation() override;
};

#endif
