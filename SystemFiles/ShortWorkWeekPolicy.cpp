#include "ShortWorkWeekPolicy.h"

ShortWorkWeekPolicy::ShortWorkWeekPolicy(CityUnit* Reciever) {
	this->Reciever = Reciever;
}

ShortWorkWeekPolicy::~ShortWorkWeekPolicy()
{
}

void ShortWorkWeekPolicy::excecuteCommand(int& balance) {
	if(balance >= 100000)
	{
		balance -= 100000;
		this->Reciever->updateEducationMultiplier(1.2);
	}
}
