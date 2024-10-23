#include "AtHomeState.h"
#include "Citizen.h"
#include "CityUnit.h"
#include "AtWorkState.h"

AtHomeState::AtHomeState() {

}

AtHomeState::~AtHomeState()
{
}

// Travels from AtHomeState to AtWorkState
void AtHomeState::travel(Citizen *citizen)
{
	// Get distance between citizen home location and citizen work location to set strategy
	int travelDistance = citizen->getHome()->calculateDistanceTo(citizen->getJob());
	this->chooseStrategy(travelDistance);

	// Set state of citizen to AtWorkState
	citizen->setState(new AtWorkState());
}
