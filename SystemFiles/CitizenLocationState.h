/**
 * @file CitizenLocationState.h
 * @brief Defines the CitizenLocationState class for creating objects and managing the state of a Citizen.
 */

#ifndef CITIZENLOCATIONSTATE_H
#define CITIZENLOCATIONSTATE_H

class Citizen;
class CommuteStrategy;
class CityUnit;

#include <string>

/**
 * @class CitizenLocationState
 * @brief Abstract class representing a state for a Citizen's location.
 *
 * This class defines the interface for different location states (e.g., AtHomeState, AtWorkState, etc.) of a citizen in the simulation. 
 * The travel function is virtual and must be implemented by derived classes.
 */
class CitizenLocationState {

protected:

	CommuteStrategy* strategy; ///< The strategy for determining commute behavior.

public:

    /**
     * @brief Constructor for CitizenLocationState.
     *
     * Initializes the CitizenLocationState with default values.
     */
	CitizenLocationState();

	/**
     * @brief Chooses a commute strategy based on travel distance.
     *
     * This function selects a commuting strategy for the citizen
     * based on the distance they need to travel.
     *
     * @param travelDistance The distance the citizen needs to travel.
     */
	void chooseStrategy(int travelDistance);
     /**
      * @brief Gets the travel method of the citizen.
      * 
      * This method returns a string that indicates the current method of travel 
      * that the citizen employs to move between locations (home, leisure, job).
      * 
      * @return A string representing the travel method (e.g., "walking", "driving").
      */
     std::string getTravelMethod();

	/**
     * @brief Virtual destructor for CitizenLocationState.
     */
	virtual ~CitizenLocationState();

	/**
     * @brief Pure virtual function to handle travel behavior.
     *
     * This function is overridden by concrete location states to define
     * how a citizen moves between locations.
     *
     * @param citizen The citizen whose travel behavior is being defined.
     */
	virtual void travel(Citizen* citizen) = 0;

	/**
     * @brief Pure virtual function to return a string representing the state name
     *
     * This function is overridden by concrete location states to define
     * what string is returned
     */
	virtual std::string getStateName() = 0;

};

#endif
