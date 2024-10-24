#ifndef CITYUNIT_H
#define CITYUNIT_H

#include <vector>
#include "Citizen.h"
#include "Iterator.h"

class CityUnit {

protected:
	int totalCapacity;
	int usedCapacity;
	std::vector<Citizen*> resident;

public:
	CityUnit();

	virtual void add(CityUnit* newUnit) = 0;

	virtual void remove(CityUnit* unit) = 0;

	virtual ~CityUnit();

	virtual int calculateDistanceTo(CityUnit* destination) = 0;

	virtual int getRemainingCapacity() = 0;

	virtual int getUsedCapacity() = 0;

	virtual void update() = 0;

	virtual Iterator* createIterator() = 0;

	virtual double getEmploymentRate() = 0;

	/**
	 * Checks if the building type is residential. If it is then loop through the associated citizens and decrement their balance.
	 */
	virtual int payTaxes(int amount) = 0;

	virtual int evaluateHappiness() = 0;

	virtual int countCitizens() = 0;
};

#endif
