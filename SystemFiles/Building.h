#ifndef BUILDING_H
#define BUILDING_H

#include "CityUnit.h"
#include <nlohmann/json.hpp>

class Building : public CityUnit {


public:
	Building(int totalCap, int usedCap);

	virtual ~Building();

	int calculateDistanceTo(CityUnit* destination);

	std::vector<Citizen*>& getResidents();

	int getRemainingCapacity();

	int getUsedCapacity();

	int getTotalCapacity() const;

	double getEmploymentRate();

	virtual void update() = 0;

	virtual int evaluateHappiness();

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

	void evaluateTrafficConditions();

	virtual std::map<std::string, int> collectResources() = 0;

	virtual std::map<std::string, double> collectUtilities() = 0;

	virtual nlohmann::json getJSONrepresentation() = 0;

};

#endif
