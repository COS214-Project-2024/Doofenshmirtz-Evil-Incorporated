#include "District.h"
#include <algorithm>
#include <vector>
#include <iostream>


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
}

void District::update() {
	// TODO - implement District::update
	throw "Not yet implemented";
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

int District::payTaxes(int s) {
	// TODO - implement District::payTaxes
	throw "Not yet implemented";
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

	for (auto unit:containedCityUnit){
		if (unit->getUsedCapacity() > 0)
		{
			totalCitizens+= unit->getUsedCapacity();
		}
	}

	return totalCitizens;
}
