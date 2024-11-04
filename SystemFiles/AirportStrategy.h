/**
 * @file AirportStrategy.h
 * @brief Defines the AirportStrategy class methods.
 */

#ifndef AIRPORTSTRATEGY_H
#define AIRPORTSTRATEGY_H

#include "CommuteStrategy.h"
#include <string>

/**
 * @class AirportStrategy
 * @brief A concrete implementation of the CommuteStrategy class for airport-based travel.
 */
class AirportStrategy : public CommuteStrategy {

public:
    /**
     * @brief Constructs an AirportStrategy object.
     */
    AirportStrategy();

    /**
     * @brief Destroys the AirportStrategy object.
     */
    ~AirportStrategy();

    /**
     * @brief Gets the name of the travel strategy.
     * @return A string representing the name of the travel strategy.
     */
    std::string getTravelStrategyName();

    /**
     * @brief Handles the commute state for the airport strategy.
     * 
     * Manages and returns the specific state value associated with 
     * the airport commuting strategy.
     * 
     * @return An integer representing the commute state.
     */
    int handleCommuteState();
};

#endif
