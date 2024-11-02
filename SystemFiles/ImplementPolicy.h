/**
 * @file ImplementPolicy.h
 * @brief Declares the ImplementPolicy class, an abstract command for implementing policies in a CityUnit.
 */

#ifndef IMPLEMENTPOLICY_H
#define IMPLEMENTPOLICY_H

#include "GovernmentCommand.h"

/**
 * @class ImplementPolicy
 * @brief Abstract command to implement a policy in a CityUnit.
 *
 * This class serves as a base for specific policy implementation commands,
 * holding a reference to the balance that can be affected by the policy.
 */
class ImplementPolicy : public GovernmentCommand {
protected:
    int& balance; ///< Reference to the balance that may be modified by the policy.

public:
    /**
     * @brief Constructs an ImplementPolicy command.
     * @param district Pointer to the CityUnit where the policy will be implemented.
     * @param balance Reference to the balance to be modified.
     */
    ImplementPolicy(CityUnit* district, int& balance);

    /**
     * @brief Destructor for ImplementPolicy.
     */
    virtual ~ImplementPolicy();

    /**
     * @brief Executes the command to implement the policy.
     * 
     * This method is pure virtual and must be overridden in derived classes.
     */
    virtual void executeCommand() = 0;
};

#endif
