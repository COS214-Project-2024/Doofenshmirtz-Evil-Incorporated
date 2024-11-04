/**
 * @file AirportStrategy.cpp
 * @brief Implements the AirportStrategy class methods.
 */

#include "AirportStrategy.h"

/**
 * @brief Constructs an AirportStrategy object.
 */
AirportStrategy::AirportStrategy() {

}

/**
 * @brief Destroys the AirportStrategy object.
 */
AirportStrategy::~AirportStrategy() {

}

/**
 * @brief Returns the name of the travel strategy.
 * @return A string representing "AirportStrategy".
 */
std::string AirportStrategy::getTravelStrategyName() {
    return "AirportStrategy";
}

/**
 * @brief Handles the commute state for the airport strategy.
 * 
 * This function manages the specific state related to commuting in the context of 
 * the airport travel strategy. 
 * 
 * @return An integer value associated with the commute state.
 */
int AirportStrategy::handleCommuteState() {
    // my code, no touchy
    return 15; // okay jy mag, maar net as jy mooi vra
}
