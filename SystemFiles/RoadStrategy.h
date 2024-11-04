/**
 * @file RoadStrategy.h
 * @brief Defines the RoadStrategy class for RoadStrategy objects.
 */


#ifndef ROADSTRATEGY_H
#define ROADSTRATEGY_H

#include "CommuteStrategy.h"

/**
 * @class RoadStrategy
 * @brief A concrete implementation of the CommuteStrategy class for road-based travel.
 */
class RoadStrategy : public CommuteStrategy {

public:
    /**
     * @brief Constructs a RoadStrategy object.
     */
    RoadStrategy();

    /**
     * @brief Destroys the RoadStrategy object.
     */
    ~RoadStrategy();

    /**
     * @brief Gets the name of the travel strategy.
     * @return A string representing the name of the travel strategy.
     */
    std::string getTravelStrategyName();

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
    int handleCommuteState();
};

#endif
