#include "Residential.h"

Residential::Residential() : Building((rand()%100) + 10){
	this->usedCapacity = this->totalCapacity;
    for (int i = 0; i < this->totalCapacity; i++) {
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
