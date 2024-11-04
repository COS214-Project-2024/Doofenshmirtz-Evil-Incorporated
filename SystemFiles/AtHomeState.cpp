/**
 * @file AtHomeState.cpp
 * @brief Implements the AtHomeState class.
 */

#include "AtHomeState.h"
#include "Citizen.h"
#include "CityUnit.h"
#include "AtWorkState.h"
#include "CommuteStrategy.h"

/**
 * @brief Constructor for AtHomeState.
 */
AtHomeState::AtHomeState() {

}

/**
 * @brief Destructor for AtHomeState.
 */
AtHomeState::~AtHomeState()
{
}


/**
 * @brief Handles the travel logic for a citizen in the AtHomeState.
 *
 * This method transitions a citizen from their home to their workplace,
 * provided they are employed (i.e., they have a job). The method calculates 
 * the travel distance between the citizen's home and their job, chooses a 
 * strategy based on the distance, and transitions them to the AtWorkState.
 *
 * @param citizen The citizen attempting to travel from home.
 * @note If the citizen is unemployed (i.e., they don't have a job), they 
 *       remain in the AtHomeState, and no travel occurs.
 */
void AtHomeState::travel(Citizen *citizen)
{	
	// Check if citizen is employed before attempting a transistion
	if(citizen->getJob() != nullptr)
	{
		// Get distance between citizen home location and citizen work location to set strategy
		int travelDistance = citizen->getHome()->calculateDistanceTo(citizen->getJob());
		this->chooseStrategy(travelDistance);
		int temp = this->strategy->handleCommuteState();
		citizen->updateSatisfaction("+",temp);

		// Set the strategy used to get to this state so that traffic can be evaluated
		citizen->lastUsedStrategyName = this->getTravelMethod();

		// Set state of citizen to AtWorkState
		citizen->setState(new AtWorkState());

	}

}

/**
 * @brief Returns "AtHomeState"
 */
std::string AtHomeState::getStateName()
{
    return "AtHomeState";
}
