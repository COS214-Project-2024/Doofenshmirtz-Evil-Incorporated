#include "GovernmentCommand.h"

GovernmentCommand::GovernmentCommand(CityUnit* district) {
	this->reciever = district;
}

GovernmentCommand::~GovernmentCommand()
{
}
