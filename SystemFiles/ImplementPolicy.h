#ifndef IMPLEMENTPOLICY_H
#define IMPLEMENTPOLICY_H

#include "GovernmentCommand.h"

class ImplementPolicy : public GovernmentCommand {


public:
	ImplementPolicy(CityUnit* district);

	virtual ~ImplementPolicy();

	virtual void executeCommand(int& balance) = 0;
};

#endif
