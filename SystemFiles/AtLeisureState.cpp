#include "AtLeisureState.h"
#include "Citizen.h"
#include "CityUnit.h"

AtLeisureState::AtLeisureState() {

}

AtLeisureState::~AtLeisureState()
{
}


// Travels from AtLeisureState to AtHomeState
void AtLeisureState::travel(Citizen *citizen)
{
	// Get distance between citizen leisure location and citizen home location to set strategy
	int travelDistance = citizen->getLeisure()->calculateDistanceTo(citizen->getHome());
	this->chooseStrategy(travelDistance);

	// Set state of citizen to AtWorkState
	citizen->setState(new AtHomeState());
}
