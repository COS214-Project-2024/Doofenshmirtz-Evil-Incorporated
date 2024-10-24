#ifndef RAILWAYSTRATEGY_H
#define RAILWAYSTRATEGY_H

#include "CommuteStrategy.h"

/**
 * @class RailwayStrategy
 * @brief A concrete implementation of the CommuteStrategy class for railway-based transportation.
 */
class RailwayStrategy : public CommuteStrategy {

public:
    /**
     * @brief Constructs a RailwayStrategy object.
     */
    RailwayStrategy();

    /**
     * @brief Destroys the RailwayStrategy object.
     */
    ~RailwayStrategy();

    /**
     * @brief Gets the name of the travel strategy.
     * @return A string representing the name of the travel strategy.
     */
    std::string getTravelStrategyName();
};

#endif
