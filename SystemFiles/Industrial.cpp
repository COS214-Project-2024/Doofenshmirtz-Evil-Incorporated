#include "Industrial.h"

// Note: This currently calls the parent constructor with a set number. Whoever is implementing this, it should be a random number [10,100]
Industrial::Industrial() : Building((rand()%100) + 10) {
}

Industrial::~Industrial()
{
}

void Industrial::update() {
	// TODO - implement Industrial::update
	throw "Not yet implemented";
}
