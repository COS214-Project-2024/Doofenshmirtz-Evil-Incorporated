#include "BetterEducationPolicy.h"

BetterEducationPolicy::BetterEducationPolicy(CityUnit* district,int& balance) :ImplementPolicy(district,balance){
}

BetterEducationPolicy::~BetterEducationPolicy()
{
}

void BetterEducationPolicy::executeCommand() {

	if(balance >= 100000)
	{
		balance -= 100000;
		this->reciever->updateEducationMultiplier(1.2);
	}
}
