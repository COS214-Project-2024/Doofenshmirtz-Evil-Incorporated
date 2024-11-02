/**
 * @file GovernmentCommand.h
 * @brief Declares the base class for government commands on city units.
 */

#ifndef GOVERNMENTCOMMAND_H
#define GOVERNMENTCOMMAND_H

#include "CityUnit.h"

/**
 * @class GovernmentCommand
 * @brief Base class for commands that can be executed on a CityUnit.
 *
 * This abstract class defines an interface for commands that can be used to
 * implement various government policies within a city unit (e.g., a district).
 */
class GovernmentCommand {
protected:
    CityUnit* reciever;  ///< Pointer to the CityUnit that the command affects.

public:
    /**
     * @brief Constructor for GovernmentCommand.
     * @param district Pointer to the CityUnit (receiver) on which the command operates.
     * @throws std::invalid_argument if district is null.
     */
    GovernmentCommand(CityUnit* district);

    /**
     * @brief Virtual destructor for GovernmentCommand.
     */
    virtual ~GovernmentCommand();

    /**
     * @brief Executes the command. Must be overridden by derived classes.
     */
    virtual void executeCommand() = 0;
};

#endif
