/**
 * @file RoadStrategy.cpp
 * @brief Implements the RoadStrategy class for RoadStrategy objects.
 */


#include "RoadStrategy.h"

/**
 * @brief Constructs a RoadStrategy object.
 */
RoadStrategy::RoadStrategy() {

}

/**
 * @brief Destroys the RoadStrategy object.
 */
RoadStrategy::~RoadStrategy()
{
}

/**
 * @brief Returns the name of the travel strategy.
 * @return A string representing "RoadStrategy".
 */
std::string RoadStrategy::getTravelStrategyName() {
    return "RoadStrategy";
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
int RoadStrategy::handleCommuteState()
{
    //my code, no touchy
    return 8;//okay jy mag, maar net as jy mooi vra
}
