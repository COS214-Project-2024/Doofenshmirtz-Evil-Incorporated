#include "Sewage.h"

Sewage::Sewage(int totalCap, int usedCap) : Utility(totalCap, usedCap)
{
}

Sewage::~Sewage()
{
}

void Sewage::update() {
    this->usedCapacity += 10;
    if(usedCapacity > totalCapacity)
    {
        usedCapacity = totalCapacity;
    }
}
