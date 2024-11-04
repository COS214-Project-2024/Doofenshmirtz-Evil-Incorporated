/**
 * @file Building.cpp
 * @brief Implements the Building class for representing and managing buildings in the city.
 */

#include "Building.h"
#include "Residential.h"
#include <iostream>

/**
 * @brief Constructs a Building object with specified total and used capacity.
 * 
 * @param totalCap The total capacity of the building.
 * @param usedCap The current used capacity of the building.
 */
Building::Building(int totalCap, int usedCap) : CityUnit(totalCap, usedCap) {
}

/**
 * @brief Destroys the Building object and frees resident resources.
 */
Building::~Building() {
    for (auto citizen : resident) {
        delete citizen;  // Free each dynamically allocated Citizen in the resident vector
    }
    resident.clear();  // Clear the vector to avoid dangling pointers
}

/**
 * @brief Calculates the distance to another CityUnit.
 * 
 * Currently returns 0 as a placeholder. The actual distance calculation 
 * implementation can be defined as needed.
 * 
 * @param destination A pointer to the CityUnit destination.
 * @return An integer representing the calculated distance.
 */
int Building::calculateDistanceTo(CityUnit* destination) {
    return 0;
}

/**
 * @brief Gets the remaining capacity of the building.
 * 
 * @return The remaining capacity as an integer.
 * @throws "Value Error: usedCapacity greater that totalCapacity" 
 * if usedCapacity exceeds totalCapacity.
 */
int Building::getRemainingCapacity() {
    int remaining_capacity;

    if (usedCapacity > totalCapacity) {
        throw "Value Error: usedCapacity greater that totalCapacity";
        return 1;  // This line will not be executed due to the throw above
    } else {
        remaining_capacity = totalCapacity - usedCapacity;
        return remaining_capacity;
    }
}

/**
 * @brief Gets the currently used capacity of the building.
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
 * @brief Calculates the employment rate in the building.
 * 
 * This function checks the residents and computes the rate of employed citizens.
 * Returns a decimal value between 0 and 1.
 * 
 * @return The employment rate as a double.
 */
double Building::getEmploymentRate() {
    /*
    // Uncomment to enable employment rate calculation
    Building* residentialBuilding = dynamic_cast<Residential*>(this);
    if (!residentialBuilding) {
        // If not residential, return 0 as employment rate
        return 0.0;
    }

    std::cout << "Residence found\n";
    int employed_citizens = 0;
    int total_citizens = resident.size();
    std::cout << "Residence size: " << total_citizens << "\n";

    if (total_citizens == 0) {
        return 0.0;
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
    */
    return 0.5;  // Placeholder value
}

/**
 * @brief Evaluates the happiness of residents in the building.
 * 
 * Calculates the average satisfaction of the residents and returns it.
 * 
 * @return The average satisfaction as an integer.
 * @throws "Value Error: Satisfaction < 0" if total satisfaction is negative.
 */
int Building::evaluateHappiness() {
    // Check for resident size of 0 which implies it is not a residential building and should be ignored for the happiness stat
    if (resident.size() == 0) {
        return 0;
    }

    int totalSatisfaction = 0;

    for (auto citizen : resident) {
        totalSatisfaction += citizen->getSatisfaction();
    }

    if (totalSatisfaction < 0) {
        throw "Value Error: Satisfaction < 0";
    }
    return totalSatisfaction / resident.size();
}

/**
 * @brief Counts the number of citizens in the building.
 * 
 * @return The number of citizens as an integer.
 */
int Building::countCitizens() {
    return resident.size();
}

/**
 * @brief Adds a new resident to the building.
 * 
 * @param newCitizen A pointer to the Citizen object to be added.
 */
void Building::pushBackResident(Citizen *newCitizen) {
    resident.push_back(newCitizen);
}

/**
 * @brief Updates the education multiplier for the building.
 * 
 * @param mult The multiplier value to be applied.
 */
void Building::updateEducationMultiplier(float mult) {
    // Implementation can be added as needed
}

/**
 * @brief Updates the week multiplier for the building.
 * 
 * @param mult The multiplier value to be applied.
 */
void Building::updateWeekMultiplier(float mult) {
    // Implementation can be added as needed
}

/**
 * @brief Evaluates traffic conditions related to the building.
 * 
 * Implementation for evaluating traffic conditions can be defined as needed.
 */
void Building::evaluateTrafficConditions() {
    // Implementation can be added as needed
}

/**
 * @brief Gets the residents of the building.
 * 
 * @return A reference to the vector of residents.
 */
std::vector<Citizen*>& Building::getResidents() {
    return resident;
}
