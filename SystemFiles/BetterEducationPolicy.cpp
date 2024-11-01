#include "BetterEducationPolicy.h"

BetterEducationPolicy::BetterEducationPolicy(CityUnit* Reciever) {
	this->Reciever = Reciever;
}

BetterEducationPolicy::~BetterEducationPolicy()
{
}

void BetterEducationPolicy::excecuteCommand(int& balance) {

	if(balance >= 100000)
	{
		balance -= 100000;
		this->Reciever->updateEducationMultiplier(1.2);
	}
}
