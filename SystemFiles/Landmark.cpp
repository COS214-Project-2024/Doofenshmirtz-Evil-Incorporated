#include "Landmark.h"

// Note: This currently calls the parent constructor with a set number. Whoever is implementing this, it should be a random number [10,100]
Landmark::Landmark() : Building((rand()%100) + 10) {
}

Landmark::~Landmark()
{
}

void Landmark::update() {
	for (auto person:resident){
		person->updateSatisfaction("Visit landmark", 20);
	}
}
