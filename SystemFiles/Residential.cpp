#include "Residential.h"
#include <iostream>

Residential::Residential() : Building((rand()%100) + 10){
	this->usedCapacity = this->totalCapacity;
    for (int i = 0; i < this->totalCapacity; i++) {
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
