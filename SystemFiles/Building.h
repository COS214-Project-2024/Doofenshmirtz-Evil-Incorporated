#ifndef BUILDING_H
#define BUILDING_H

#include "CityUnit.h"

class Building : public CityUnit {


public:
	Building(int totalCapacity);

	virtual ~Building();

	int calculateDistanceTo(CityUnit* destination);

	int getRemainingCapacity();

	int getUsedCapacity();

	double getEmploymentRate();

	virtual void update() = 0;

	virtual int payTaxes(int s) = 0;

	int evaluateHappiness();

	int countCitizens();
};

#endif
