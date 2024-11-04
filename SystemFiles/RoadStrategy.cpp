/**
 * @file BuildingFactory.h
 * @brief Defines the BuildingFactory class for creating building objects.
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

int RoadStrategy::handleCommuteState()
{
    //my code, no touchy
    return 8;//okay jy mag, maar net as jy mooi vra
}
