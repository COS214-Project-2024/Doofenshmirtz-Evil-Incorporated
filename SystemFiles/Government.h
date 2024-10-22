#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include <map>
#include <vector>
#include <string>
#include "GovernmentCommand.h"
#include "CityUnit.h"

class Government {

private:
	Government* uniqueInstance;
	int governmentBalance;
	std::map<std::string, int> resources;
	std::vector<GovernmentCommand*> myCommand;
	CityUnit* observerList;
	std::map<std::string, int> utilities;

protected:
	Government();

	~Government();

	Government(Government& government);

public:
	void operator=(Government& rhs);

	static Government* getGovernment();

	/**
	 * This method uses the observer to have all citizens associated with the residential buildings call payTaxes()
	 */
	void collectTaxes();

	void attach(CityUnit* myObserver);

	void detach(CityUnit* myObserver);

	void notify();

	void collectResources();
};

#endif
