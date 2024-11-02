#ifndef BUILDING_H
#define BUILDING_H

#include "CityUnit.h"

class Building : public CityUnit {


public:
	Building(int totalCap, int usedCap);

	virtual ~Building();

	int calculateDistanceTo(CityUnit* destination);

	std::vector<Citizen*>& getResidents();

	int getRemainingCapacity();

	int getUsedCapacity();

	double getEmploymentRate();

	virtual void update() = 0;

	int evaluateHappiness();

	int countCitizens();

	/**
	 *@brief Dummy implementations to endure concrete buildings works as expected
	 */

	void add(CityUnit* newUnit){};
	void remove(CityUnit* unit){};
	void employResidents(){};
	void partyResidents(){};
	Iterator* createIterator(){
		return nullptr;
	};
	void setTaxRate(double amount){
	};
	double payTaxes(){
		return 0;
	};

	void pushBackResident(Citizen* newCitizen);

	 void updateEducationMultiplier(float mult);
     void updateWeekMultiplier(float mult);
};

#endif
