#include "ShortWorkWeekPolicy.h"

ShortWorkWeekPolicy::ShortWorkWeekPolicy(CityUnit* district) :ImplementPolicy(district){
}

ShortWorkWeekPolicy::~ShortWorkWeekPolicy()
{
}

void ShortWorkWeekPolicy::executeCommand(int& balance) {
	if(balance >= 100000)
	{
		balance -= 100000;
		this->Reciever->updateEducationMultiplier(1.2);
	}
}
