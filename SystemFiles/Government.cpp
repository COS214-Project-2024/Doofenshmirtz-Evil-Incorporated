#include "Government.h"

#include <iostream>

Government::Government(int govermentBalance) {
	this->governmentBalance = 0;
}

Government::~Government() {
	for (auto it = observerList.begin(); it != observerList.end(); it++) {
		delete *it;
	}
	for (auto it = myCommand.begin(); it != myCommand.end(); it++) {
		delete *it;
	}
}

Government::Government(Government& government) {
	this->governmentBalance = government.governmentBalance;
	this->resources = government.resources;
	this->myCommand = government.myCommand;
	this->observerList = government.observerList;
}


void Government::operator=(Government &rhs) {
	this->governmentBalance = rhs.governmentBalance;
	this->resources = rhs.resources;
	this->myCommand = rhs.myCommand;
	this->observerList = rhs.observerList;
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
	throw "Not yet implemented";
}

int Government::getGovernmentBalance() {
	return this->governmentBalance;
}