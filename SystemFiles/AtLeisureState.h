/**
 * @file AtLeisureState.h
 * @brief Defines the AtLeisureState class.
 */

#ifndef ATLEISURESTATE_H
#define ATLEISURESTATE_H

#include "CitizenLocationState.h"

class CityUnit;

/**
 * @class AtLeisureState
 * @brief Concrete state representing a citizen's location when they are at leisure.
 *
 * This class defines the behavior of a citizen when they are in their leisure state.
 * It inherits from CitizenLocationState and provides specific travel behavior when
 * transitioning from leisure to other locations.
 */
class AtLeisureState : public CitizenLocationState {


public:

    /**
     * @brief Constructor for AtLeisureState.
     */
	AtLeisureState();

	/**
     * @brief Destructor for AtLeisureState.
     */
	~AtLeisureState();

	/**
     * @brief Handles the travel logic for a citizen in the AtLeisureState.
     *
     * Transitions the citizen from the AtLeisureState to the AtHomeState by calculating
     * the travel distance between the leisure and home locations, setting the travel strategy,
     * and changing the state of the citizen.
     *
     * @param citizen The citizen who is attempting to travel.
     */
	void travel(Citizen* citizen);

	/**
      * @brief Returns the name of the current state.
      * 
      * This function returns a string representing the name of the state,
      * specifically "AtLeisureState".
      * 
      * @return A string indicating the name of the state.
      */
	std::string getStateName();
};

#endif
