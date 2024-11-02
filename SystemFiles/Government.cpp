#include "Government.h"

#include <iostream>

Government::Government(int governmentBalance) {
	this->governmentBalance = governmentBalance;
}

Government::~Government() {
	for (auto it = observerList.begin(); it != observerList.end(); it++) {
		delete *it;
	}
	for (auto it = myCommand.begin(); it != myCommand.end(); it++) {
		delete *it;
	}
}

void Government::collectTaxes() {
	for (CityUnit* unit : observerList) {
		unit->payTaxes(TAX_RATE);
		this->governmentBalance += unit->getUsedCapacity() * TAX_RATE;
	}
}

void Government::attach(CityUnit * myObserver) {
	observerList.push_back(myObserver);
}


void Government::detach(CityUnit* myObserver) {
	for (auto it = observerList.begin(); it != observerList.end(); it++) {
		if (*it == myObserver) {
			observerList.erase(it);
			delete myObserver;
			break;
		}
	}
}

void Government::notify() {
	for (CityUnit* unit : observerList) {
		unit->update();
	}
}

void Government::collectResources() {
	for (CityUnit* unit : observerList) {
		std::map<std::string, int> resources = unit->collectResources();
		for (auto it = resources.begin(); it != resources.end(); it++) {
			this->resources[it->first] += it->second;
		}
		
	}
}

int Government::getGovernmentBalance() {
	return this->governmentBalance;
}