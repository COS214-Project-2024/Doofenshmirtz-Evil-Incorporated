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
        if (unit != nullptr) {
            delete unit;  // Ensure each unit is only deleted once
            unit = nullptr;  // Avoid dangling pointers
        }
    }
    containedCityUnit.clear();
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
	if (containedCityUnit.empty()) {
        return 0.0; // Avoid division by zero if no units are present
    }

    double totalEmploymentRate = 0.0;
    for (const auto& unit : containedCityUnit) {
        totalEmploymentRate += unit->getEmploymentRate();
    }

    // Return average employment rate
    return totalEmploymentRate / containedCityUnit.size();

}
double District::payTaxes(double rate) {

	double totalTax = 0.0;
    for (auto unit : containedCityUnit) {
        if (Residential* residentialUnit = dynamic_cast<Residential*>(unit)) {
            for (auto person : residentialUnit->getResidents()) {  // Ensure `getResidents()` is correct
                double tax = person->getBalance() * rate;
                totalTax += tax;
                person->takeTax(tax);  // Deduct tax from citizen’s balance
            }
        }
    }
    return totalTax;
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
            // Count citizens in each Residential unit's residents list
            totalCitizens += residentialUnit->getResidents().size();
        }
    }

    return totalCitizens;

		return totalCitizens;
}
