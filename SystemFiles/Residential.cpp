#include "Residential.h"

// Note: This currently calls the parent constructor with a set number. Whoever is implementing this, it should be a random number [10,100]
Residential::Residential() : Building((rand()%100) + 10){
	this->usedCapacity = this->totalCapacity;
	for(int i =0 ;i<this->totalCapacity;i++){
		Citizen* newCitizen = new Citizen(this, nullptr,nullptr);
		resident.push_back(newCitizen);
	}
}

Residential::~Residential()
{
}

void Residential::update() {
	// TODO - implement Residential::update
	throw "Not yet implemented";
}
