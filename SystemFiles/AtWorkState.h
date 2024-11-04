/**
 * @file BuildingFactory.h
 * @brief Defines the BuildingFactory class for creating building objects.
 */

#ifndef ATWORKSTATE_H
#define ATWORKSTATE_H

#include "CitizenLocationState.h"

class CityUnit;

/**
 * @class AtWorkState
 * @brief Concrete state representing a citizen's location when they are at work.
 *
 * This class defines the behavior of a citizen when they are in their work state.
 * It inherits from CitizenLocationState and provides specific travel behavior when
 * transitioning from work to other locations.
 */
class AtWorkState : public CitizenLocationState {


public:

	/**
     * @brief Constructor for AtWorkState.
     */
	AtWorkState();

	/**
     * @brief Destructor for AtWorkState.
     */
	~AtWorkState();

	/**
     * @brief Handles the travel logic for a citizen in the AtWorkState.
     *
     * Transitions the citizen from the AtWorkState to the AtLeisureState by calculating
     * the travel distance between the work and leisure locations, setting the travel strategy,
     * and changing the state of the citizen.
     *
     * @param citizen The citizen who is attempting to travel.
     */
	void travel(Citizen* citizen);

	/**
     * @brief Returns "AtWorkState"
     */
	std::string getStateName();
};

#endif
