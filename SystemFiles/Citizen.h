#ifndef CITIZEN_H
#define CITIZEN_H

#include "AtHomeState.h"

class CitizenLocationState;
class CityUnit;

/**
 * @class Citizen
 * @brief Represents a citizen in the city with attributes such as home, job, satisfaction score, and travel functionality.
 */
class Citizen {

private:
    int satisfactionScore;   ///< The satisfaction score of the citizen (ranges from 40 to 70 on creation).
    bool isEmployed;         ///< Whether the citizen is employed.
    CitizenLocationState* citizenLocation;  ///< The current location state of the citizen.
    CityUnit* citizenHome;   ///< Pointer to the citizen's home.
    CityUnit* citizenJob;    ///< Pointer to the citizen's job.
	CityUnit* citizenLeisure; ///<Pointer to the citizen's prevered lesiure location
    int bankBalance;         ///< The bank balance of the citizen (ranges from 20,000 to 100,000 on creation).

public:

    /**
     * @brief Constructor for Citizen class.
     * @param home Pointer to the citizen's home CityUnit.
     * @param job Pointer to the citizen's job CityUnit (can be nullptr if unemployed).
	 * @param leisure Pointer to the citizen's preferred leisure spot (randomly chosen)
     */
	Citizen(CityUnit* home, CityUnit* job, CityUnit* leisure);

	/**
     * @brief Destructor for Citizen class.
     */
	~Citizen();

	/**
     * @brief Getter for citizen's leisure CityUnit*
     */
	CityUnit* getLeisure() const;

	/**
     * @brief Getter for citizen's home CityUnit*
     */
	CityUnit* getHome() const;

	/**
     * @brief Getter for citizen's Job location CityUnit*
     */
	CityUnit* getJob() const;

	/**
     * @brief Getter for citizen's current satisfaction level
     */
	int getSatisfaction() const;

	/**
     * @brief Getter for citizen's current bank account balance
     */	
	int getBalance() const;

	/**
     * @brief Sets citizen's state while ensuring memory safety
     * @param newState state to transistion to allowed values : AtHomeState | AtWorkState | AtLeisureState
     */
	void setState(CitizenLocationState* newState);

	/**
     * @brief Make citizen travel to next location in their natural routine i.e. home => leisure => job
	 * Furthermore, slighlty influences satisfaction based on current state of citizen
     */
	void followRoutine();
};

#endif
