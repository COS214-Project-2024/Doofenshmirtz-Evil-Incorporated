/**
 * @file BetterEducationPolicy.h
 * @brief Declares the BetterEducationPolicy class for implementing an improved education policy.
 */

#ifndef BETTEREDUCATIONPOLICY_H
#define BETTEREDUCATIONPOLICY_H

#include "ImplementPolicy.h"
#include "CityUnit.h"

/**
 * @class BetterEducationPolicy
 * @brief Command to implement a better education policy in a CityUnit.
 *
 * This policy allows for the enhancement of education by deducting a certain amount
 * from the balance and increasing the education multiplier.
 */
class BetterEducationPolicy : public ImplementPolicy {

public:
    /**
     * @brief Constructs a BetterEducationPolicy command.
     * @param district Pointer to the CityUnit where the policy will be implemented.
     * @param balance Reference to the balance to be modified.
     */
    BetterEducationPolicy(CityUnit* district, int& balance);

    /**
     * @brief Destructor for BetterEducationPolicy.
     */
    ~BetterEducationPolicy();

    /**
     * @brief Executes the command to implement the better education policy.
     *
     * Deducts a specific amount from the balance and updates the education multiplier
     * if there are sufficient funds.
     */
    void executeCommand();
};

#endif
