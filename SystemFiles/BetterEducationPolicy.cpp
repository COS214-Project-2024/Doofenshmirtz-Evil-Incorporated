#include "BetterEducationPolicy.h"

BetterEducationPolicy::BetterEducationPolicy(CityUnit* district) :ImplementPolicy(district){
}

BetterEducationPolicy::~BetterEducationPolicy()
{
}

void BetterEducationPolicy::executeCommand(int& balance) {

	if(balance >= 100000)
	{
		balance -= 100000;
		this->Reciever->updateEducationMultiplier(1.2);
	}
}
