#ifndef ALLOCATEBUDGET_H
#define ALLOCATEBUDGET_H

#include "GovernmentCommand.h"

class AllocateBudget : public GovernmentCommand {


public:
	AllocateBudget();

	~AllocateBudget();

	void excecuteCommand();
};

#endif
