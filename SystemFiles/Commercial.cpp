#include "Commercial.h"
#include "WebSocketNotifier.h"

/**
 * @class Commercial
 * @brief Represents a commercial building in the city simulation.
 * 
 * The Commercial class inherits from Building and manages resources,
 * salary payments to residents, and notifications for front-end updates.
 */

/**
 * @brief Constructs a Commercial object.
 * 
 * Initializes a Commercial building with specified total and used capacities.
 * Sends an update message to the front end via WebSocketNotifier.
 * 
 * @param totalCap The total capacity of the commercial building.
 * @param usedCap The current used capacity of the commercial building.
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
 * Cleans up resources used by the Commercial object.
 */
Commercial::~Commercial() {
}

/**
 * @brief Updates the salaries of residents in the commercial building.
 * 
 * Randomly assigns a salary between 100 and 1100 to each resident.
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
 * Currently, this implementation returns an empty resource map.
 * 
 * @return A map containing resources collected from the building.
 */
std::map<std::string, int> Commercial::collectResources() {
    return std::map<std::string, int>();
}

/**
 * @brief Collects utilities from the commercial building.
 * 
 * Currently, this implementation returns an empty utilities map.
 * 
 * @return A map containing utilities collected from the building.
 */
std::map<std::string, double> Commercial::collectUtilities() {
    return std::map<std::string, double>();
}

/**
 * @brief Gets the JSON representation of the commercial building.
 * 
 * @return A JSON object representing the commercial building's name and value.
 */
nlohmann::json Commercial::getJSONrepresentation() {
    nlohmann::json building = {
        {"name", "Commercial"},
        {"value", this->totalCapacity}
    };    

    return building;
}
