#ifndef SETTAX_H
#define SETTAX_H


#include "GovernmentCommand.h"
#include "CityUnit.h"
class SetTax : public GovernmentCommand {
private:
	double taxRate;
public:
	SetTax(CityUnit* district,double newTaxRatePercentage);

	~SetTax();

	void executeCommand();
};

#endif
