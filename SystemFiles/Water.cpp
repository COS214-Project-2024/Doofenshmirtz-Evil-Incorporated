#include "Water.h"

Water::Water(int totalCap, int usedCap) : Utility(totalCap, usedCap)
{
}

Water::~Water()
{
}

void Water::update() {
    this->usedCapacity += 10;
    if(usedCapacity > totalCapacity)
    {
        usedCapacity = totalCapacity;
    }
}
