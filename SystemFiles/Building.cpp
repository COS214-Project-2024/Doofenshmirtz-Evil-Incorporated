/**
 * @file Building.cpp
 * @brief Implements the Building class, which represents a building within a city unit.
 */

#include "Building.h"
#include "Residential.h"
#include <iostream>
#include <random>

/**
 * @brief Constructs a Building object.
 * 
 * Initializes a Building with specified total and used capacities.
 * @param totalCap The total capacity of the building.
 * @param usedCap The current used capacity of the building.
 */
Building::Building(int totalCap, int usedCap) : CityUnit(totalCap, usedCap) {
}

/**
 * @brief Destructor for the Building class.
 * 
 * Cleans up dynamically allocated citizens in the resident vector and clears the vector.
 */
Building::~Building() {
    for (auto citizen : resident) {
        delete citizen;  // Free each dynamically allocated Citizen in the resident vector
    }
    resident.clear();  // Clear the vector to avoid dangling pointers
}

/**
 * @brief Calculates the distance to a specified destination CityUnit.
 * 
 * @param destination A pointer to the destination CityUnit.
 * @return An integer representing the distance to the destination.
 */
int Building::calculateDistanceTo(CityUnit* destination) {
    // Static engine and distribution to initialize only once
    static std::mt19937 randomEngine(static_cast<unsigned>(std::time(nullptr)));
    static std::uniform_int_distribution<int> dist(0, 35); // Range [0, 35]
    
    return dist(randomEngine); // Generate a random number in the range
}


/**
 * @brief Gets the remaining capacity of the building.
 * 
 * @return The remaining capacity as an integer.
 * @throws const char* If usedCapacity is greater than totalCapacity.
 */
int Building::getRemainingCapacity() {
    int remaining_capacity;

    if (usedCapacity > totalCapacity) {
        throw "Value Error: usedCapacity greater than totalCapacity";
    } else {
        remaining_capacity = totalCapacity - usedCapacity;
        return remaining_capacity;
    }
}

/**
 * @brief Gets the used capacity of the building.
 * 
 * @return The used capacity as an integer.
 */
int Building::getUsedCapacity() {
    return usedCapacity;
}

/**
 * @brief Gets the total capacity of the building.
 * 
 * @return The total capacity as an integer.
 */
int Building::getTotalCapacity() const {
    return totalCapacity;  // Returns the totalCapacity member inherited from CityUnit
}

/**
 * @brief Calculates the employment rate of citizens in the building.
 * 
 * @return A decimal value between 0 and 1 representing the employment rate.
 */
double Building::getEmploymentRate() {

    // Check if this building is a Residential type
    Residential* residentialBuilding = dynamic_cast<Residential*>(this);
    if (!residentialBuilding) {
        // If not residential, return 0 as employment rate
        return 0.0;
    }

    int employed_citizens = 0;
    int total_citizens = resident.size();

    if (total_citizens == 0) {
        return 0.0; // Return 0 if there are no citizens
    }

    // Count employed citizens only if they have a job
    for (auto res : resident) {
        if (res->getJob() != nullptr) {
            employed_citizens += 1;
        }
    }

    // Calculate employment rate as a double
    double employment_rate = static_cast<double>(employed_citizens) / total_citizens;
    return employment_rate;
}

/**
 * @brief Evaluates the happiness level of residents in the building.
 * 
 * @return The average happiness level of residents.
 * @throws const char* If the total satisfaction is negative.
 */
int Building::evaluateHappiness() {
    // Check for resident size of 0 which implies it is not a residential building and should be ignored for the happiness stat
    if (resident.size() == 0) {
        return 0; // No residents to evaluate
    }

    int totalSatisfaction = 0;

    for (auto citizen : resident) {
        totalSatisfaction += citizen->getSatisfaction();
    }

    if (totalSatisfaction < 0) {
        throw "Value Error: Satisfaction < 0";
    }
    return totalSatisfaction / resident.size(); // Return average satisfaction
}

/**
 * @brief Counts the number of citizens in the building.
 * 
 * @return The total number of citizens as an integer.
 */
int Building::countCitizens() {
    return resident.size();
}

/**
 * @brief Adds a new Citizen to the building.
 * @param newCitizen A pointer to the Citizen to be added.
 */
void Building::pushBackResident(Citizen *newCitizen) {
    resident.push_back(newCitizen);
}

/**
 * @brief Updates the education multiplier for the building.
 * @param mult The new education multiplier to be applied.
 */
void Building::updateEducationMultiplier(float mult) {
    // Placeholder for future implementation
}

/**
 * @brief Updates the week multiplier for the building.
 * @param mult The new week multiplier to be applied.
 */
void Building::updateWeekMultiplier(float mult) {
    // Placeholder for future implementation
}

/**
 * @brief Evaluates traffic conditions related to the building.
 */
void Building::evaluateTrafficConditions() {
    // Placeholder for future implementation
}

/**
 * @brief Gets a reference to the vector of residents in the building.
 * 
 * @return A vector of pointers to Citizen objects representing the residents.
 */
std::vector<Citizen*>& Building::getResidents() {
    return resident;
}
