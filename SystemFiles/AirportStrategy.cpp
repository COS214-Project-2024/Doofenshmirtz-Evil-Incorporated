#include "AirportStrategy.h"

/**
 * @brief Constructs an AirportStrategy object.
 */
AirportStrategy::AirportStrategy() {

}

/**
 * @brief Destroys the AirportStrategy object.
 */
AirportStrategy::~AirportStrategy()
{
}

/**
 * @brief Returns the name of the travel strategy.
 * @return A string representing "AirportStrategy".
 */
std::string AirportStrategy::getTravelStrategyName() {
    return "AirportStrategy";
}
