#include "Industrial.h"

Industrial::Industrial(int totalCap, int usedCap, double taxR) : Building(totalCap, usedCap, taxR) {
}

Industrial::~Industrial()
{
}

void Industrial::update() {
	this->usedCapacity += 10;
}
