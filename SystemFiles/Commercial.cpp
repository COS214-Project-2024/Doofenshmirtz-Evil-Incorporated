#include "Commercial.h"

Commercial::Commercial(int totalCap, int usedCap, double taxR) : Building(totalCap, usedCap, taxR) {
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
