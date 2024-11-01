#ifndef SETTAX_H
#define SETTAX_H


#include "GovernmentCommand.h"
#include "CityUnit.h"
class SetTax : public GovernmentCommand {

public:
	SetTax(CityUnit* district);

	~SetTax();

	void executeCommand(double newTaxRatePercentage);
};

#endif
