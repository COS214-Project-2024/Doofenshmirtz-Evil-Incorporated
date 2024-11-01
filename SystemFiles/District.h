#ifndef DISTRICT_H
#define DISTRICT_H

#include "CityUnit.h"
#include "ConcreteIterator.h"

class District : public CityUnit {

private:
	std::vector<CityUnit*> containedCityUnit;
	int educationPolicyMultiplier = 1;
	int shortweekPolicyMultiplier = 1;

public:
	District();

	void add(CityUnit* newUnit);

	void remove(CityUnit* unit);

	~District();

	void update();

	void employResidents();

	Iterator* createIterator();

	double getEmploymentRate();

	double payTaxes();

	int evaluateHappiness();

	int countCitizens();

	int calculateDistanceTo(CityUnit* other) override {
        // Placeholder implementation
        return 0;
    }

    int getRemainingCapacity() override {
        // Placeholder implementation
        return 0;
    }

    int getUsedCapacity() override {
        // Placeholder implementation
        return 0;
    }

	void updateEducationMultiplier(float mult);
    void updateWeekMultiplier(float mult);
};

#endif