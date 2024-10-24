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

    int handleCommuteState();

};

#endif
