#include "District.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include "Residential.h"
#include "Commercial.h"

District::District() {
}

void District::add(CityUnit* newUnit) {
	containedCityUnit.push_back(newUnit);
}

void District::remove(CityUnit* unit) {
	CityUnit* itemToRemove = unit;

	auto it = std::find(containedCityUnit.begin(),containedCityUnit.end(),itemToRemove);

	if (it != containedCityUnit.end())
	{
		containedCityUnit.erase(it);
	}else{
		throw "Item to remove not found";
	}
}

District::~District()
{
	for (auto unit : containedCityUnit) {
        delete unit;  // Free each dynamically allocated CityUnit
    }
    containedCityUnit.clear();  // Clear the vector to avoid dangling pointers
}

void District::update() {
	for (auto unit:containedCityUnit){
		unit->update();
	}
	this->employResidents();
}

void District::employResidents(){
    // Step 1: Collect available commercial units with open employment slots
    std::vector<Commercial*> availableCommercialUnits;
    for (auto unit : containedCityUnit) {
        if (Commercial* commercialUnit = dynamic_cast<Commercial*>(unit)) {
            if (commercialUnit->getEmploymentRate() < 1) {
                availableCommercialUnits.push_back(commercialUnit);
            }
        }
    }

    // Step 2: Iterate over all residential units and employ residents if they don't have a job
    for (auto unit : containedCityUnit) {
        if (Residential* residentialUnit = dynamic_cast<Residential*>(unit)) {
            for (auto person : resident) {
                if (person->getJob() == nullptr) {
                    // Step 3: Try to employ the person in an available commercial unit
                    for (auto commercialUnit : availableCommercialUnits) {
                        if (commercialUnit->getEmploymentRate() < 1) {
                            person->employCitizen(commercialUnit);
                            break;  // Exit loop after employment to avoid extra iterations
                        }
                    }
                }
            }
        }
    }
}


Iterator* District::createIterator() {
	Iterator* it = new ConcreteIterator();
	return it;
}

double District::getEmploymentRate() {
	int buildingsInUnit = containedCityUnit.size();
	double totalEmploymentRate = 0;
	for (auto unit:containedCityUnit)
	{
		totalEmploymentRate += unit->getEmploymentRate();
	}
	double districtEmploymentRate = totalEmploymentRate/buildingsInUnit;

	if ((districtEmploymentRate < 0) || (districtEmploymentRate > 1))
	{
		throw "Value Error, distrcitEmploymentRate less than 0 or greater than 1";
	}else{
		return districtEmploymentRate;
	}

}
double District::payTaxes(double s) {

	double totalTax = 0;
	for (auto unit : containedCityUnit) {
			if (Residential* residentialUnit = dynamic_cast<Residential*>(unit)) {
				for (auto person : resident) {
						double tax = person->getBalance()*s;
						totalTax += tax;
						person->takeTax(tax);
					}
				}
        }
}

int District::evaluateHappiness() {
	int totalHappiness = 0;
	for (auto unit:containedCityUnit)
	{
		totalHappiness += unit->evaluateHappiness();
	}

	if (totalHappiness<0)
	{
		throw "Negative happiness";
	}
	return totalHappiness/containedCityUnit.size();
}

int District::countCitizens() {
		int totalCitizens = 0;

		for (auto unit : containedCityUnit) {
			if (Residential* residentialUnit = dynamic_cast<Residential*>(unit)) {
				for (auto person : resident) {
						totalCitizens += 1;
					}
				}
        }

		return totalCitizens;
}
