/**
 * @file GovernmentCommand.cpp
 * @brief Implements the GovernmentCommand class.
 */

#include "GovernmentCommand.h"

/**
 * @brief Constructs a GovernmentCommand with a specified receiver.
 * @param district Pointer to the CityUnit (receiver) on which the command operates.
 * @throws std::invalid_argument if district is null.
 */
GovernmentCommand::GovernmentCommand(CityUnit* district) : receiver(district) {

}

/**
 * @brief Destructor for GovernmentCommand.
 */
GovernmentCommand::~GovernmentCommand() {
}
