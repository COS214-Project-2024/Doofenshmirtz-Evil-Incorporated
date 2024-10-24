#include "AtWorkState.h"
#include "Citizen.h"
#include "CityUnit.h"
#include "AtLeisureState.h"

/**
 * @brief Constructor for AtWorkState.
 */
AtWorkState::AtWorkState() {

}

/**
 * @brief Destructor for AtWorkState.
 */
AtWorkState::~AtWorkState()
{
}

/**
 * @brief Handles the travel logic for a citizen in the AtWorkState.
 *
 * This method transitions the citizen from the work state to their leisure state.
 * The distance between the citizen's work and leisure location is calculated, 
 * the appropriate travel strategy is chosen, and the citizen's state is updated.
 *
 * @param citizen The citizen attempting to travel.
 */
void AtWorkState::travel(Citizen *citizen)
{
	// Get distance between citizen work location and citizen leisure location to set strategy
	int travelDistance = citizen->getJob()->calculateDistanceTo(citizen->getLeisure());
	this->chooseStrategy(travelDistance);

	// Set state of citizen to AtWorkState
	citizen->setState(new AtLeisureState());
}

/**
 * @brief Returns "AtWorkState"
 */
std::string AtWorkState::getStateName()
{
    return "AtWorkState";
}
