/**
 * @file ShortWorkWeekPolicy.h
 * @brief Declares the ShortWorkWeekPolicy class for implementing a short workweek policy.
 */

#ifndef SHORTWORKWEEKPOLICY_H
#define SHORTWORKWEEKPOLICY_H

#include "ImplementPolicy.h"
#include "CityUnit.h"

/**
 * @class ShortWorkWeekPolicy
 * @brief Command to implement a short workweek policy in a CityUnit.
 *
 * This policy allows for the enhancement of the workweek structure by deducting a certain amount
 * from the balance and increasing the short week policy multiplier.
 */
class ShortWorkWeekPolicy : public ImplementPolicy {

public:
    /**
     * @brief Constructs a ShortWorkWeekPolicy command.
     * @param district Pointer to the CityUnit where the policy will be implemented.
     * @param balance Reference to the balance to be modified.
     */
    ShortWorkWeekPolicy(CityUnit* district, int& balance);

    /**
     * @brief Destructor for ShortWorkWeekPolicy.
     */
    ~ShortWorkWeekPolicy();

    /**
     * @brief Executes the command to implement the short workweek policy.
     *
     * Deducts a specific amount from the balance and updates the short week multiplier
     * if there are sufficient funds.
     */
    void executeCommand();
};

#endif
