#ifndef BETTEREDUCATIONPOLICY_H
#define BETTEREDUCATIONPOLICY_H

#include "ImplementPolicy.h"
#include "CityUnit.h"
class BetterEducationPolicy : public ImplementPolicy {

public:
	BetterEducationPolicy(CityUnit* district,int& balance);

	~BetterEducationPolicy();

	void executeCommand();
};

#endif
