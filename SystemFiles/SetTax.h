#ifndef SETTAX_H
#define SETTAX_H


#include "GovernmentCommand.h"
class SetTax : public GovernmentCommand {


public:
	SetTax(float newTaxRatePercentage);

	~SetTax();

	void excecuteCommand();
};

#endif
