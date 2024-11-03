/**
 * @file BetterEducationPolicy.cpp
 * @brief Implements the BetterEducationPolicy class for enhancing education.
 */

#include "BetterEducationPolicy.h"

/**
 * @brief Constructs a BetterEducationPolicy command with a specified balance reference.
 */
BetterEducationPolicy::BetterEducationPolicy(CityUnit* district, int& balance) 
    : ImplementPolicy(district, balance) {
}

/**
 * @brief Destructor for BetterEducationPolicy.
 */
BetterEducationPolicy::~BetterEducationPolicy() {
}

/**
 * @brief Executes the command to enhance education policy.
 *
 * If the balance is sufficient, the policy deducts a fixed amount from the balance
 * and updates the education multiplier of the associated CityUnit.
 */
void BetterEducationPolicy::executeCommand() {
    if (balance >= 100000) {
        balance -= 100000;
        this->reciever->updateEducationMultiplier(1.2);
        this->reciever->updateWeekMultiplier(1);
    }
}
