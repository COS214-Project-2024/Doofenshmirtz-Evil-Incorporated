#include "Waste.h"

Waste::Waste(int totalCap, int usedCap) : Utility(totalCap, usedCap)
{
}

Waste::~Waste()
{
}

void Waste::update() {
    this->usedCapacity += 10;
    if(usedCapacity > totalCapacity)
    {
        usedCapacity = totalCapacity;
    }
}
