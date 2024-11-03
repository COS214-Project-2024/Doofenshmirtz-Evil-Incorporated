/**
 * @file ShortWorkWeekPolicy.cpp
 * @brief Implements the ShortWorkWeekPolicy class for enhancing workweek structure.
 */

#include "ShortWorkWeekPolicy.h"

/**
 * @brief Constructs a ShortWorkWeekPolicy command with a specified balance reference.
 */
ShortWorkWeekPolicy::ShortWorkWeekPolicy(CityUnit* district, int& balance) 
    : ImplementPolicy(district, balance) {
}

/**
 * @brief Destructor for ShortWorkWeekPolicy.
 */
ShortWorkWeekPolicy::~ShortWorkWeekPolicy() {
}

/**
 * @brief Executes the command to enhance the short workweek policy.
 *
 * If the balance is sufficient, the policy deducts a fixed amount from the balance
 * and updates the short week multiplier of the associated CityUnit.
 */
void ShortWorkWeekPolicy::executeCommand() {
    if (balance >= 100000) {
        balance -= 100000;
        this->reciever->updateWeekMultiplier(1.2);
        this->reciever->updateEducationMultiplier(1);
    }
}
