#include "Commercial.h"

// Note: This currently calls the parent constructor with a set number. Whoever is implementing this, it should be a random number [10,100]
Commercial::Commercial() : Building((rand()%100) + 10)  {
}

Commercial::~Commercial()
{
}

void Commercial::update() {
	double salary = (rand()%1000)+100;
	for ( auto person:resident)
	{
		person->recieveSalary(salary);
	}
}
