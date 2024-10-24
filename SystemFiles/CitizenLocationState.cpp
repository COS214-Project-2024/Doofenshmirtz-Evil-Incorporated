#include "CitizenLocationState.h"

/**
 * @brief Constructor for CitizenLocationState.
 */
CitizenLocationState::CitizenLocationState() {

	this->strategy = nullptr;
}

// Vir Henco : Hierdie function moet die strategy member variable set gebaseer op travelDistance
// Ook: Jy kan die shit opspice soos 'n mexican tortilla as jy wil. Maybe meeste van die tyd gerbuk dit die distance
// maar nou-en-dan kies dit net 'n random strategy of iets soos dit. Sal die simulation bietjie meer uiteenlopend maak
/**
 * @brief Chooses a commute strategy based on travel distance.
 * 
 * @param travelDistance The distance the citizen needs to travel.
 */
void CitizenLocationState::chooseStrategy(int travelDistance)
{
}

/**
 * @brief Destructor for CitizenLocationState.
 */
CitizenLocationState::~CitizenLocationState()
{
	if(strategy != nullptr)
	{
		delete strategy;
	}
	strategy = nullptr;
}


