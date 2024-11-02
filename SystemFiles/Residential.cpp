#include "Residential.h"
#include "WebSocketNotifier.h"
#include <iostream>


/**
 * @brief Constructs a Residential building and fills it with citizens.
 *
 * Initializes the residential unit with a random capacity between 10 and 109,
 * sets the used capacity to the total capacity, and populates the `resident` vector
 * with dynamically allocated `Citizen` objects.
 */
Residential::Residential(int totalCap, int usedCap) : Building(totalCap, usedCap) {
    for (int i = 0; i < usedCap && i < totalCap; i++) {
        Citizen* newCitizen = new Citizen(this, nullptr, nullptr);
        pushBackResident(newCitizen);
    }
    // Front end update
    nlohmann::json message = {
	{"type", "valueUpdate"},
	{"data", 	{
					{"id", "residential"},
					{"value", "1++"}
				}
				}};
	WebSocketNotifier::get_mutable_instance().log(message);

    std::string citizensCreated = (std::to_string(totalCap) + "++");
    message = {
	{"type", "valueUpdate"},
	{"data", 	{
					{"id", "citizens"},
					{"value", citizensCreated}
				}
				}};
	WebSocketNotifier::get_mutable_instance().log(message);
}


/**
 * @brief Destructor for the Residential class.
 *
 * Cleans up dynamically allocated `Citizen` objects stored in the `resident` vector
 * and clears the vector to ensure no dangling pointers remain.
 */
Residential::~Residential()
{
	for (auto person : resident) {
        if (person) {
            delete person;  // Safely delete each dynamically allocated Citizen
            person = nullptr;  // Prevent dangling pointers
        }
    }
    resident.clear();
}


/**
 * @brief Updates the state of each resident in the building.
 *
 * Calls the `followRoutine()` method for each `Citizen` in the `resident` vector
 * to update their state as needed.
 */
void Residential::update() {
	for (auto person:resident)
	{
		person->followRoutine();
	}
}