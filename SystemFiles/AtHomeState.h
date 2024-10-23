#ifndef ATHOMESTATE_H
#define ATHOMESTATE_H

#include "CitizenLocationState.h"

class CityUnit;

/**
 * @class AtHomeState
 * @brief Concrete state representing a citizen's location when they are at home.
 *
 * This class defines the behavior of a citizen when they are in their home state.
 * It inherits from CitizenLocationState and provides a specific implementation for 
 * the travel function.
 */
class AtHomeState : public CitizenLocationState {


public:

	/**
     * @brief Constructor for AtHomeState.
     */
	AtHomeState();

	/**
     * @brief Destructor for AtHomeState.
     */
	~AtHomeState();

	/**
     * @brief Handles the travel logic for a citizen in the AtHomeState.
     *
     * Transitions the citizen from the AtHomeState to the AtWorkState, if the 
     * citizen has a job. If the citizen is unemployed, they remain in the 
     * AtHomeState.
     *
     * @param citizen The citizen who is attempting to travel.
     */
	void travel(Citizen* citizen);

	/**
     * @brief Returns "AtHomeState"
     */
	std::string getStateName();
};

#endif
