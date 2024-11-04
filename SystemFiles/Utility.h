/**
 * @file Utility.h
 * @brief Defines the Utility class, an abstract base class for utility buildings.
 * 
 * The Utility class represents a type of building that provides essential services 
 * to a city, such as power, water, sewage, etc. It extends the Building class 
 * and defines common behaviors and attributes for all utility buildings.
 */

#ifndef UTILITY_H
#define UTILITY_H

#include "Building.h"

/**
 * @class Utility
 * @brief Abstract base class for utility buildings.
 * 
 * This class serves as a base for different types of utility buildings,
 * requiring derived classes to implement specific utility types and 
 * their associated behaviors.
 */
class Utility : public Building {

public:
    /**
     * @brief Constructs a Utility object with the specified capacity.
     * 
     * @param totalCap The total capacity of the utility building.
     * @param usedCap The amount of capacity currently in use.
     */
    Utility(int totalCap, int usedCap);

    /**
     * @brief Virtual destructor for the Utility class.
     */
    virtual ~Utility();

    /**
     * @brief Updates the state of the utility building.
     * 
     * This is a pure virtual function, meaning derived classes must 
     * provide an implementation for this method.
     */
    virtual void update() = 0;

    /**
     * @brief Retrieves the type of utility represented by this building.
     * 
     * @return A string representing the type of utility (e.g., "PowerPlant").
     */
    virtual std::string getUtilityType() const = 0;

    /**
     * @brief Collects resources from the utility building.
     * 
     * This method overrides the collectResources method from the Building class.
     * 
     * @return A map containing the names and quantities of resources collected.
     */
    std::map<std::string, int> collectResources() override;

    /**
     * @brief Collects utility usage data from the utility building.
     * 
     * This method overrides the collectUtilities method from the Building class.
     * 
     * @return A map containing the types of utilities and their respective quantities.
     */
    std::map<std::string, double> collectUtilities() override;

    /**
     * @brief Gets a JSON representation of the utility building.
     * 
     * This method overrides the getJSONrepresentation method from the Building class.
     * 
     * @return A JSON object representing the current state of the utility building.
     */
    nlohmann::json getJSONrepresentation() override;
};

#endif
