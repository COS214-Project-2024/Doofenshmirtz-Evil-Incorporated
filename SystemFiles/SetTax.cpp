#include "SetTax.h"

SetTax::SetTax(CityUnit* district,double newTaxRatePercentage) : GovernmentCommand(district)
{
	this->taxRate = newTaxRatePercentage;
}

SetTax::~SetTax()
{
}

void SetTax::executeCommand() {
	this->reciever->setTaxRate(taxRate);
}
