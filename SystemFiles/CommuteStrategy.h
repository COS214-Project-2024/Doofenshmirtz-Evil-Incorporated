/**
 * @file CommuteStrategy.h
 * @brief Defines the CommuteStrategy class for implementing commuting strategies.
 */

#ifndef COMMUTESTRATEGY_H
#define COMMUTESTRATEGY_H

#include <string>
#include <iostream>

/**
 * @class CommuteStrategy
 * @brief Abstract base class for different commuting strategies.
 * 
 * This class provides an interface for implementing various commuting 
 * strategies that citizens can use to travel within the city. 
 * Subclasses must define specific behaviors for commuting.
 */
class CommuteStrategy {
public:
    /**
     * @brief Constructor for the CommuteStrategy class.
     * 
     * Initializes a new instance of the CommuteStrategy class.
     */
    CommuteStrategy();

    /**
     * @brief Destructor for the CommuteStrategy class.
     * 
     * Cleans up any resources allocated for the CommuteStrategy.
     */
    virtual ~CommuteStrategy();

    /**
     * @brief Handles the commute state.
     * 
     * This pure virtual function must be overridden in derived classes 
     * to implement specific behavior for handling the commute state.
     * 
     * @return An integer representing the result of handling the commute state.
     */
    virtual int handleCommuteState() = 0;

    /**
     * @brief Retrieves the name of the travel strategy.
     * 
     * This pure virtual function must be overridden in derived classes 
     * to provide the name of the specific travel strategy being used.
     * 
     * @return A string representing the name of the travel strategy.
     */
    virtual std::string getTravelStrategyName() = 0;
};

#endif
