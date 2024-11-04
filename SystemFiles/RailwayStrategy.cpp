/**
 * @file BuildingFactory.h
 * @brief Defines the BuildingFactory class for creating building objects.
 */

#include "RailwayStrategy.h"

/**
 * @brief Constructs a RailwayStrategy object.
 */
RailwayStrategy::RailwayStrategy() {

}

/**
 * @brief Destroys the RailwayStrategy object.
 */
RailwayStrategy::~RailwayStrategy()
{
}

/**
 * @brief Returns the name of the travel strategy.
 * @return A string representing "RailwayStrategy".
 */
std::string RailwayStrategy::getTravelStrategyName() {
    return "RailwayStrategy";
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
int RailwayStrategy::handleCommuteState()
{
    //socket things go here please 
    //my code, no touchy
    return 10;//okay jy mag, maar net as jy mooi vra
}
