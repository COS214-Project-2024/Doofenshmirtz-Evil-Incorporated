#include "Industrial.h"
#include "WebSocketNotifier.h"

/**
 * @class Industrial
 * @brief Represents an industrial building in the city simulation.
 * 
 * The Industrial class inherits from Building and includes functionality specific
 * to industrial buildings, such as resource collection and capacity management.
 */

/**
 * @brief Constructs an Industrial building with a specified capacity and tax rate.
 * @param totalCap The total capacity of the industrial building.
 * @param usedCap The initial used capacity.
 * @param taxR The tax rate applied to the industrial building.
 */
Industrial::Industrial(int totalCap, int usedCap) : Building(totalCap, usedCap) {
    // Front end update
    nlohmann::json message = {
	{"type", "valueUpdate"},
	{"data", 	{
					{"id", "industrial"},
					{"value", "1++"}
				}
				}};
	WebSocketNotifier::get_mutable_instance().log(message);
}

/**
 * @brief Destructor for the Industrial class.
 */
Industrial::~Industrial()
{
}

/**
 * @brief Collects resources produced by the industrial building.
 * 
 * This method collects all resources based on the used capacity and resets the used
 * capacity to zero after collection.
 * @return A map containing the types and quantities of resources collected.
 */
std::map<std::string, int> Industrial::collectResources()
{
    std::map<std::string, int> resources;
    resources["Wood"] = usedCapacity;
    resources["Steel"] = usedCapacity;
    resources["Concrete"] = usedCapacity;
    resources["Bricks"] = usedCapacity;
    this->usedCapacity = 0;
    return resources;
}

/**
 * @brief Updates the industrial building's used capacity.
 * 
 * Increases the used capacity by a fixed amount and ensures it does not exceed
 * the total capacity.
 */
void Industrial::update() {
    this->usedCapacity += 10;
    if(usedCapacity > totalCapacity)
    {
        usedCapacity = totalCapacity;
    }
}
