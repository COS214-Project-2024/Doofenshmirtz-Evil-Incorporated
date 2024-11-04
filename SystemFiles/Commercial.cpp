/**
 * @file Commercial.cpp
 * @brief Implements the Commercial class for creating commercial building objects.
 */

#include "Commercial.h"
#include "WebSocketNotifier.h"

/**
 * @brief Constructor for the Commercial class.
 * 
 * Initializes a Commercial building with specified total and used capacity.
 * It also sends an update message through the WebSocketNotifier to notify 
 * the front end of the change in value.
 * 
 * @param totalCap The total capacity of the commercial building.
 * @param usedCap The currently used capacity of the commercial building.
 */
Commercial::Commercial(int totalCap, int usedCap) : Building(totalCap, usedCap) {
    // Front end update
    nlohmann::json message = {
        {"type", "valueUpdate"},
        {"data", {
            {"id", "commercial"},
            {"value", "1++"}
        }}
    };
    WebSocketNotifier::get_mutable_instance().log(message);
}

/**
 * @brief Destructor for the Commercial class.
 * 
 * Cleans up resources associated with the Commercial building.
 */
Commercial::~Commercial() {}

/**
 * @brief Updates the salary of each resident in the commercial building.
 * 
 * This method randomly assigns a salary between 100 and 1099 to each resident,
 * simulating salary distribution in a commercial context.
 */
void Commercial::update() {
    double salary = (rand() % 1000) + 100;
    for (auto person : resident) {
        person->recieveSalary(salary);
    }
}

/**
 * @brief Collects resources from the commercial building.
 * 
 * This method is currently not implemented and returns an empty map.
 * 
 * @return A map of resource names and their quantities (currently empty).
 */
std::map<std::string, int> Commercial::collectResources() {
    return std::map<std::string, int>();
}

/**
 * @brief Collects utility usage data from the commercial building.
 * 
 * This method is currently not implemented and returns an empty map.
 * 
 * @return A map of utility types and their usage (currently empty).
 */
std::map<std::string, double> Commercial::collectUtilities() {
    return std::map<std::string, double>();
}

/**
 * @brief Gets the JSON representation of the commercial building.
 * 
 * This method constructs a JSON object that includes the name of the building
 * and its total capacity.
 * 
 * @return A nlohmann::json object representing the commercial building.
 */
nlohmann::json Commercial::getJSONrepresentation() {
    nlohmann::json building = {
        {"name", "Commercial"},
        {"value", this->totalCapacity}
    };    

    return building;
}
