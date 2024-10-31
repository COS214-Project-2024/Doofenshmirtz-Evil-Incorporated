#include "SetTax.h"

SetTax::SetTax(CityUnit* district) {
	this->reciever = district;
}

SetTax::~SetTax()
{
}

void SetTax::excecuteCommand(float newTaxRatePercentage) {
	this->reciever->setTaxRate(newTaxRatePercentage);
}
