#include "SetTax.h"

SetTax::SetTax(CityUnit* district) : GovernmentCommand(district)
{
}

SetTax::~SetTax()
{
}

void SetTax::executeCommand(double newTaxRatePercentage) {
	this->reciever->setTaxRate(newTaxRatePercentage);
}
