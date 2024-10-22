#ifndef SPENDRESOURCES_H
#define SPENDRESOURCES_H

#include "GovernmentCommand.h"
#include <map>
#include <string>

class SpendResources : public GovernmentCommand {


public:
	SpendResources(double employmentRate, std::map<std::string, int> resources, int& balance);

	~SpendResources();

	void excecuteCommand();
};

#endif
