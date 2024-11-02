#include "ImplementPolicy.h"

ImplementPolicy::ImplementPolicy(CityUnit* district,int& balance) : GovernmentCommand(district),balance(balance){
	
}

ImplementPolicy::~ImplementPolicy()
{
}
