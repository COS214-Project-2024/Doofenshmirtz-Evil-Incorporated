#ifndef IMPLEMENTPOLICY_H
#define IMPLEMENTPOLICY_H

#include "GovernmentCommand.h"

class ImplementPolicy : public GovernmentCommand {


public:
	ImplementPolicy();

	virtual ~ImplementPolicy();

	virtual void excecuteCommand() = 0;
};

#endif
