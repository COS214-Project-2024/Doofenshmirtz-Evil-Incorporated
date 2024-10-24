#include "PublicTransportStrategy.h"

/**
 * @brief Constructs a PublicTransportStrategy object.
 */
PublicTransportStrategy::PublicTransportStrategy() {

}

/**
 * @brief Destroys the PublicTransportStrategy object.
 */
PublicTransportStrategy::~PublicTransportStrategy()
{
}

/**
 * @brief Returns the name of the travel strategy.
 * @return A string representing "PublicTransport".
 */
std::string PublicTransportStrategy::getTravelStrategyName() {
    return "PublicTransport";
}
