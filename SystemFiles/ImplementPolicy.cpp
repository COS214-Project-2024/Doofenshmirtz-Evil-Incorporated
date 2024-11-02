/**
 * @file ImplementPolicy.cpp
 * @brief Implements the ImplementPolicy class, an abstract command for implementing policies.
 */

#include "ImplementPolicy.h"

/**
 * @brief Constructs an ImplementPolicy command with a specified balance reference.
 */
ImplementPolicy::ImplementPolicy(CityUnit* district, int& balance) 
    : GovernmentCommand(district), balance(balance) {
}

/**
 * @brief Destructor for ImplementPolicy.
 */
ImplementPolicy::~ImplementPolicy() {
}
