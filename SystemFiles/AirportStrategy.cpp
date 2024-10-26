#include "AirportStrategy.h"

/**
 * @brief Constructs an AirportStrategy object.
 */
AirportStrategy::AirportStrategy() {

}

/**
 * @brief Destroys the AirportStrategy object.
 */
AirportStrategy::~AirportStrategy()
{
}

/**
 * @brief Returns the name of the travel strategy.
 * @return A string representing "AirportStrategy".
 */
std::string AirportStrategy::getTravelStrategyName() {
    return "AirportStrategy";
}

int AirportStrategy::handleCommuteState()
{
    //socket things go here please 
    std::cout << "Socket stuff, here comes the airplane | |  | |\n";
    //my code, no touchy
    return 15;//okay jy mag, maar net as jy mooi vra
}
