/**
 * @file SetTax.cpp
 * @brief Implements the SetTax class, which sets the tax rate for a CityUnit.
 */

#include "SetTax.h"

/**
 * @brief Constructs a SetTax command with the specified tax rate.
 */
SetTax::SetTax(CityUnit* district, double newTaxRatePercentage) : GovernmentCommand(district) {
    this->taxRate = newTaxRatePercentage;
}

/**
 * @brief Destructor for SetTax.
 */
SetTax::~SetTax() {
}

/**
 * @brief Executes the command to set the tax rate for the associated CityUnit.
 */
void SetTax::executeCommand() {
    this->reciever->setTaxRate(taxRate);
}
