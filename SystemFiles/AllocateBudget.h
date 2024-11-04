/**
 * @file AllocateBudget.h
 * @brief Defines the AllocateBudget class for executing budget allocation commands.
 */

#ifndef ALLOCATEBUDGET_H
#define ALLOCATEBUDGET_H

#include "GovernmentCommand.h"

/**
 * @class AllocateBudget
 * @brief A class that represents a command for allocating budgets to a CityUnit.
 * 
 * This class inherits from GovernmentCommand and provides functionality
 * for executing budget allocation operations on a specified district.
 */
class AllocateBudget : public GovernmentCommand {
public:
    /**
     * @brief Constructs an AllocateBudget object.
     * 
     * @param district A pointer to the CityUnit object representing the district 
     * on which the budget allocation command will operate.
     */
    AllocateBudget(CityUnit* district);

    /**
     * @brief Destroys the AllocateBudget object.
     */
    ~AllocateBudget();

    /**
     * @brief Executes the budget allocation command.
     * 
     * This function implements the logic for executing the budget 
     * allocation process.
     */
    void executeCommand();
};

#endif // ALLOCATEBUDGET_H
