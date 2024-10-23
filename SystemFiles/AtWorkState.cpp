#include "AtWorkState.h"
#include "Citizen.h"
#include "CityUnit.h"
#include "AtLeisureState.h"

AtWorkState::AtWorkState() {

}

AtWorkState::~AtWorkState()
{
}

// Travels from AtWorkState to AtLeisureState
void AtWorkState::travel(Citizen *citizen)
{
	// Get distance between citizen work location and citizen leisure location to set strategy
	int travelDistance = citizen->getJob()->calculateDistanceTo(citizen->getLeisure());
	this->chooseStrategy(travelDistance);

	// Set state of citizen to AtWorkState
	citizen->setState(new AtLeisureState());
}

