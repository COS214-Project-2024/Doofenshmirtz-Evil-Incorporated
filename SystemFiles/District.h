#ifndef DISTRICT_H
#define DISTRICT_H

#include "CityUnit.h"
#include "ConcreteIterator.h"

class District : public CityUnit {

private:
	std::vector<CityUnit*> containedCityUnit;

public:
	District();

	void add(CityUnit* newUnit);

	void remove(CityUnit* unit);

	~District();

	void update();

	void employResidents();

	Iterator* createIterator();

	double getEmploymentRate();

	double payTaxes(double s);

	int evaluateHappiness();

	int countCitizens();
};

#endif
