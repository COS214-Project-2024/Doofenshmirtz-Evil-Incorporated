#include "Residential.h"

Residential::Residential(int totalCap, int usedCap, double taxR) : Building(totalCap, usedCap, taxR) {
    for (int i = 0; i < usedCap && i < totalCap; i++) {
        Citizen* newCitizen = new Citizen(this, nullptr, nullptr);
        this->pushBackResident(newCitizen);
    }
}

Residential::~Residential()
{
	for (auto person : resident) {
        delete person;  // Free each dynamically allocated Citizen
    }
}

void Residential::update() {
	for (auto person:resident)
	{
		person->followRoutine();
	}
}
