/**
 * @file PublicTransportStrategy.cpp
 * @brief Implements the PublicTransportStrategy class for PublicTransportStrategy objects.
 */

#include "PublicTransportStrategy.h"

/**
 * @brief Constructs a PublicTransportStrategy object.
 */
PublicTransportStrategy::PublicTransportStrategy() {

}

/**
 * @brief Destroys the PublicTransportStrategy object.
 */
PublicTransportStrategy::~PublicTransportStrategy()
{
}

/**
 * @brief Returns the name of the travel strategy.
 * @return A string representing "PublicTransport".
 */
std::string PublicTransportStrategy::getTravelStrategyName() {
    return "PublicTransportStrategy";
}

/**
 * @brief Handles the state of the commute.
 * 
 * This function is responsible for processing and managing 
 * the current commute state within the system. It may include 
 * logic for evaluating traffic conditions, adjusting routes, 
 * or updating the status of commuters.
 * 
 * @return int The result of the commute state handling, which may 
 * indicate success or failure, or provide a specific status code 
 * relevant to the commute operation.
 */
int PublicTransportStrategy::handleCommuteState()
{
    //my code, no touchy
    return 4;//okay jy mag, maar net as jy mooi vra
}
