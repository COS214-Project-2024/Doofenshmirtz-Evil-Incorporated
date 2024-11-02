#ifndef INDUSTRIAL_H
#define INDUSTRIAL_H

#include "Building.h"
#include <map>
#include <string>

/**
 * @class Industrial
 * @brief Derived class representing an industrial building in the city simulation.
 * 
 * The Industrial class extends the Building base class, adding functionality
 * specific to industrial buildings, such as resource collection and updates to
 * capacity over time.
 */
class Industrial : public Building {
public:
    /**
     * @brief Constructs an Industrial building with specified capacity and tax rate.
     * @param totalCap The total storage capacity for resources.
     * @param usedCap The initial amount of used capacity.
     * @param taxR The tax rate applicable to the industrial building.
     */
    Industrial(int totalCap, int usedCap);

    /**
     * @brief Destructor for the Industrial class.
     */
    ~Industrial();

    /**
     * @brief Collects resources produced by the industrial building.
     * 
     * Gathers all produced resources based on the current used capacity and 
     * resets the used capacity after collection.
     * @return A map of resources with types as keys and quantities as values.
     */
    std::map<std::string, int> collectResources() override;

    /**
     * @brief Updates the building's used capacity.
     * 
     * Increases the used capacity by a fixed amount. If the used capacity exceeds
     * the total capacity, it is capped at the total capacity.
     */
    virtual void update() override;
};

#endif // INDUSTRIAL_H
