#include "Residential.h"

Residential::Residential() : Building((rand()%100) + 10){
	this->usedCapacity = this->totalCapacity;
	for(int i =0 ;i<this->totalCapacity;i++){
		Citizen* newCitizen = new Citizen(this, nullptr,nullptr);
		resident.push_back(newCitizen);
	}
}

Residential::~Residential()
{
	for (auto person : resident) {
        delete person;  // Free each dynamically allocated Citizen
    }
    resident.clear();  // Clear the vector to remove dangling pointers
}

void Residential::update() {
	for (auto person:resident)
	{
		person->followRoutine();
	}
}
