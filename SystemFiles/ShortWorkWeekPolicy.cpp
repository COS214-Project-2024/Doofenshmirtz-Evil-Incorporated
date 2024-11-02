#include "ShortWorkWeekPolicy.h"

ShortWorkWeekPolicy::ShortWorkWeekPolicy(CityUnit* district,int& balance) :ImplementPolicy(district,balance){
}

ShortWorkWeekPolicy::~ShortWorkWeekPolicy()
{
}

void ShortWorkWeekPolicy::executeCommand() {
	if(balance >= 100000)
	{
		balance -= 100000;
		this->reciever->updateWeekMultiplier(1.2);
	}
}
