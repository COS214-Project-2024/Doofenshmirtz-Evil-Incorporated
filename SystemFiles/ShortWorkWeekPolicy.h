#ifndef SHORTWORKWEEKPOLICY_H
#define SHORTWORKWEEKPOLICY_H

#include "ImplementPolicy.h"
#include "CityUnit.h"
class ShortWorkWeekPolicy : public ImplementPolicy {

public:
	ShortWorkWeekPolicy(CityUnit* district,int& balance);

	~ShortWorkWeekPolicy();

	void executeCommand();
};

#endif
