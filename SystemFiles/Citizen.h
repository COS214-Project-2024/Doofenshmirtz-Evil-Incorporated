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
     * @brief updates the citizen'z satisfaction level according to an operator and a value passed in
     */
     void updateSatisfaction(std::string op,int value);

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
     * @brief Getter for citizen's state
     */	
     CitizenLocationState* getCitzenLocationSate();

	/**
     * @brief Sets citizen's state while ensuring memory safety
     * @param newState state to transistion to allowed values : AtHomeState | AtWorkState | AtLeisureState
     */
	void setState(CitizenLocationState* newState);

     /**
      * @brief Attempts to employ the citizen at the given job location.
      *
      * This method sets the `citizenJob` pointer for the citizen if they are currently unemployed. 
      * If the citizen is already employed (i.e., `citizenJob` is not nullptr), the method will do nothing.
      *
      * @param job A pointer to the CityUnit (building) where the citizen will be employed if the operation is successful.
      * @return true if the citizen was unemployed and successfully assigned a job, false if the citizen already had a job.
      */
     bool employCitizen(CityUnit* job);

     bool relaxCitizen(CityUnit* stripclub);

	/**
     * @brief Make citizen travel to next location in their natural routine i.e. home => leisure => job
	 * Furthermore, slighlty influences satisfaction based on current state of citizen
     */
	void followRoutine();

     /**
      * @brief Used in district to collect tax
      * This method subtracts the tax amount from the bank account of the citizen
      */
     void takeTax(double amount);

     /**
 *@param amount A value that is added to the persons bank acount
 * @brief Used in comercial to recieve salary for employed citizens
 *It takes in an amount and adds it to the bank balance
 */
     void recieveSalary(double amount);
};

#endif
