#ifndef GOVERNMENTCOMMAND_H
#define GOVERNMENTCOMMAND_H

class GovernmentCommand {


public:
	GovernmentCommand();

	virtual ~GovernmentCommand();

	virtual void excecuteCommand() = 0;
};

#endif
