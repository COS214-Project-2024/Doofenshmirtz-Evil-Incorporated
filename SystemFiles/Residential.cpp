#include "Residential.h"
#include <iostream>

Residential::Residential(int totalCap, int usedCap, double taxR) : Building(totalCap, usedCap, taxR) {
    for (int i = 0; i < usedCap && i < totalCap; i++) {
        Citizen* newCitizen = new Citizen(this, nullptr, nullptr);
        pushBackResident(newCitizen);
    }
    // Debug output
}

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

void Residential::update() {
	for (auto person:resident)
	{
		person->followRoutine();
	}
}
