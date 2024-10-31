#ifndef SETTAX_H
#define SETTAX_H


#include "GovernmentCommand.h"
#include "CityUnit.h"
class SetTax : public GovernmentCommand {
private:
	CityUnit* reciever;

public:
	SetTax(CityUnit* district);

	~SetTax();

	void excecuteCommand(float newTaxRatePercentage);
};

#endif
