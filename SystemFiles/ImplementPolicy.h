#ifndef IMPLEMENTPOLICY_H
#define IMPLEMENTPOLICY_H

#include "GovernmentCommand.h"

class ImplementPolicy : public GovernmentCommand {
protected:
	int& balance;

public:
	ImplementPolicy(CityUnit* district,int& balance);

	virtual ~ImplementPolicy();

	virtual void executeCommand() = 0;
};

#endif
