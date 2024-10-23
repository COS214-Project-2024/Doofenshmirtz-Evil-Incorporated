#include "AtLeisureState.h"
#include "Citizen.h"
#include "CityUnit.h"

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
	// Get distance between citizen leisure location and citizen home location to set strategy
	int travelDistance = citizen->getLeisure()->calculateDistanceTo(citizen->getHome());
	this->chooseStrategy(travelDistance);

	// Set state of citizen to AtWorkState
	citizen->setState(new AtHomeState());
}

/**
 * @brief Returns "AtLeisureState"
 */
std::string AtLeisureState::getStateName()
{
    return "AtLeisureState";
}
