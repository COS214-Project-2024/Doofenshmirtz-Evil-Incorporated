#include "Building.h"
#include "Residential.h"
#include <iostream>

Building::Building(int totalCap, int usedCap) : CityUnit(totalCap, usedCap) {
}

Building::~Building()
{
	for (auto citizen : resident) {
        delete citizen;  // Free each dynamically allocated Citizen in the resident vector
    }
    resident.clear();  // Clear the vector to avoid dangling pointers
}

int Building::calculateDistanceTo(CityUnit* destination) {
	return 0;
}

int Building::getRemainingCapacity() {
	int remaining_capacity;

	if (usedCapacity > totalCapacity)
	{
		throw "Value Error: usedCapacity greater that totalCapacity";
		return 1;
	}else{
		remaining_capacity = totalCapacity - usedCapacity;
		return remaining_capacity;
	}
}

int Building::getUsedCapacity() {
	return usedCapacity;
}

int Building::getTotalCapacity() const {
    return totalCapacity;  // Returns the totalCapacity member inherited from CityUnit
}

/**
 * @brief Calculate the employment and resturns a decimal value betwen 0 and 1
 */
double Building::getEmploymentRate() {

    // Check if this building is a Residential type
    Residential* residentialBuilding = dynamic_cast<Residential*>(this);
    if (!residentialBuilding) {
        // If not residential, return 0 as employment rate
        return 0.0;
    }

	// std::cout << "Residence found\n";
    int employed_citizens = 0;
    int total_citizens = resident.size();
	// std::cout << "Residence size: " << total_citizens << "\n";

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
}



int Building::evaluateHappiness() {

	// Check for resident size of 0 which implies it is not a residential building and should be ignored for the happiness stat
	if(resident.size() == 0)
	{
		return 0;
	}

	int totalSatisfaction = 0;

	for (auto citizen:resident)
	{
		totalSatisfaction += citizen->getSatisfaction();
	}

	if (totalSatisfaction < 0)
	{
		throw "Value Error: Satisfaction < 0";
	}
	return totalSatisfaction / resident.size();
}

/**
 * @brief Gets the amount of citezens in the building
 * Counts the items in the resident vector
 */
int Building::countCitizens() {
	return resident.size();
}

void Building::pushBackResident(Citizen *newCitizen)
{
	resident.push_back(newCitizen);
}

void Building::updateEducationMultiplier(float mult)
{

}

void Building::updateWeekMultiplier(float mult)
{
}

void Building::evaluateTrafficConditions()
{
}

std::vector<Citizen*>& Building::getResidents(){
	return resident;
}
