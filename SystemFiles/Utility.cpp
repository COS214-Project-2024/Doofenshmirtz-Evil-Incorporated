#include "Utility.h"

// Note: This currently calls the parent constructor with a set number. Whoever is implementing this, it should be a random number [10,100]
Utility::Utility(int totalCap, int usedCap) : Building(totalCap, usedCap) {
}

Utility::~Utility()
{
}
