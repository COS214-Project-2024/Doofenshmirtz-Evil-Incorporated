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
	// TODO - implement Government::collectResources
	throw "Need CityUnit first";
}

int Government::getGovernmentBalance() {
	return this->governmentBalance;
}