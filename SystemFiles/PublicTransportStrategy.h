/**
 * @file BuildingFactory.h
 * @brief Defines the BuildingFactory class for creating building objects.
 */

#ifndef PUBLICTRANSPORTSTRATEGY_H
#define PUBLICTRANSPORTSTRATEGY_H

#include "CommuteStrategy.h"

/**
 * @class PublicTransportStrategy
 * @brief A concrete implementation of the CommuteStrategy class for public transport-based travel.
 */
class PublicTransportStrategy : public CommuteStrategy {

public:
    /**
     * @brief Constructs a PublicTransportStrategy object.
     */
    PublicTransportStrategy();

    /**
     * @brief Destroys the PublicTransportStrategy object.
     */
    ~PublicTransportStrategy();

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
