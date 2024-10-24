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

    int handleCommuteState();
};

#endif
