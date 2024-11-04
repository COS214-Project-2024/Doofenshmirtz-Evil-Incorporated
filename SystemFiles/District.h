#ifndef DISTRICT_H
#define DISTRICT_H

#include "CityUnit.h"
#include "ConcreteIterator.h"

class District : public CityUnit {

private:
	std::vector<CityUnit*> containedCityUnit;
	float educationPolicyMultiplier = 1;
	float shortweekPolicyMultiplier = 1;

public:
	District();

	void add(CityUnit* newUnit);

	void remove(CityUnit* unit);

	~District();

	void update();

	void employResidents();
	void partyResidents();

	Iterator* createIterator();

	double getEmploymentRate();

	double payTaxes();

	int evaluateHappiness();

	int countCitizens();

	void setTaxRate(double amount);

	int calculateDistanceTo(CityUnit* other) override;

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

	void evaluateTrafficConditions();

	nlohmann::json getJSONrepresentation();

	std::map<std::string, int> collectResources() override;

	std::map<std::string, double> collectUtilities() override;
};

#endif