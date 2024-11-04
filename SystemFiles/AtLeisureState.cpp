/**
 * @file BuildingFactory.h
 * @brief Defines the BuildingFactory class for creating building objects.
 */

#include "AtLeisureState.h"
#include "Citizen.h"
#include "CityUnit.h"
#include "AtHomeState.h"
#include "CommuteStrategy.h"
/**
 * @brief Constructor for AtLeisureState.
 */
AtLeisureState::AtLeisureState() {

}

/**
 * @brief Destructor for AtLeisureState.
 */
AtLeisureState::~AtLeisureState()
{
}


/**
 * @brief Handles the travel logic for a citizen in the AtLeisureState.
 *
 * This method transitions the citizen from the leisure state to their home state.
 * The distance between the citizen's leisure location and home is calculated, the
 * appropriate travel strategy is chosen, and the citizen's state is updated.
 *
 * @param citizen The citizen attempting to travel.
 */
void AtLeisureState::travel(Citizen *citizen)
{
	// Get distance between citizen home location and citizen work location to set strategy
		int travelDistance = citizen->getHome()->calculateDistanceTo(citizen->getJob());
		this->chooseStrategy(travelDistance);
		int temp = this->strategy->handleCommuteState();
		citizen->updateSatisfaction("+",temp);

		// Set the strategy used to get to this state so that traffic can be evaluated
		citizen->lastUsedStrategyName = this->getTravelMethod();

		// Set state of citizen to AtHomeState
		citizen->setState(new AtHomeState());

}

/**
 * @brief Returns "AtLeisureState"
 */
std::string AtLeisureState::getStateName()
{
    return "AtLeisureState";
}
