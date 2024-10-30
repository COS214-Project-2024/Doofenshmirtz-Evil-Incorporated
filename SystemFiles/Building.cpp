#include "Building.h"

Building::Building(int Capacity) {
	this->totalCapacity = Capacity;
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

/**
 * @brief Calculate the employment and resturns a decimal value betwen 0 and 1
 */
double Building::getEmploymentRate() {
	int employed_citizens = 0;
	int total_citizens = resident.size();

	for (auto res:resident){
		if (res->getJob() != nullptr)
		{
			employed_citizens += 1;
		}
	}

	double employment_rate = (employed_citizens/total_citizens);
	return employment_rate;
}

int Building::evaluateHappiness() {
	int totalSitisfaction = 0;

	for (auto citizen:resident)
	{
		totalSitisfaction += citizen->getSatisfaction();
	}

	if (totalSitisfaction < 0)
	{
		throw "Value Error: Satisfaction < 0";
	}
	return totalSitisfaction/resident.size();
}
/**
 * @brief Gets the amount of citezens in the building
 * Counts the items in the resident vector
 */
int Building::countCitizens() {
	return resident.size();
}

std::vector<Citizen*>& Building::getResidents(){
	return resident;
}
