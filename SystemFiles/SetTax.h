/**
 * @file SetTax.h
 * @brief Declares the SetTax class, which is responsible for setting the tax rate in a CityUnit.
 */

#ifndef SETTAX_H
#define SETTAX_H

#include "GovernmentCommand.h"
#include "CityUnit.h"

/**
 * @class SetTax
 * @brief Command to set the tax rate for a specific CityUnit.
 *
 * This command encapsulates the action of changing the tax rate for the associated CityUnit,
 * which can influence its financial state and operations.
 */
class SetTax : public GovernmentCommand {
private:
    double taxRate; ///< The new tax rate percentage to be applied.

public:
    /**
     * @brief Constructs a SetTax command with a specified tax rate.
     * @param district Pointer to the CityUnit where the tax rate will be set.
     * @param newTaxRatePercentage The new tax rate percentage to be applied.
     */
    SetTax(CityUnit* district, double newTaxRatePercentage);

    /**
     * @brief Destructor for SetTax.
     */
    ~SetTax();

    /**
     * @brief Executes the command by applying the new tax rate to the CityUnit.
     */
    void executeCommand();
};

#endif
