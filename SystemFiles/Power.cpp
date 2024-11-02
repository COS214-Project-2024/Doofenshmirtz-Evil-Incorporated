#include "Power.h"

Power::Power(int totalCap, int usedCap) : Utility(totalCap, usedCap)
{
}

Power::~Power()
{
}

void Power::update() {
    this->usedCapacity += 10;
    if(usedCapacity > totalCapacity)
    {
        usedCapacity = totalCapacity;
    }
}
