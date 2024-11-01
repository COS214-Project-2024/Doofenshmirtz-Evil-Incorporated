#ifndef ALLOCATEBUDGET_H
#define ALLOCATEBUDGET_H

#include "GovernmentCommand.h"

class AllocateBudget : public GovernmentCommand {


public:
	AllocateBudget(CityUnit* district);

	~AllocateBudget();

	void executeCommand();
};

#endif
