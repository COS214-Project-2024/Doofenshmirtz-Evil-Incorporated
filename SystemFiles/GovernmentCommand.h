#ifndef GOVERNMENTCOMMAND_H
#define GOVERNMENTCOMMAND_H
#include "CityUnit.h"
class GovernmentCommand {
protected:
	CityUnit* reciever;

public:
	GovernmentCommand(CityUnit* district);

	virtual ~GovernmentCommand();

	virtual void executeCommand() = 0;
};

#endif
