/**
 * @file Citizen.h
 * @brief Defines the Citizen class for managing citizen objects in the city simulation.
 *
 * The Citizen class encapsulates the properties and behaviors of a citizen,
 * including personal attributes, satisfaction, and job-related functionalities.
 */

#ifndef CITIZEN_H
#define CITIZEN_H

#include "AtHomeState.h"

class CitizenLocationState;
class CityUnit;

/**
 * @class Citizen
 * @brief Represents a citizen in the city with attributes such as home, job, satisfaction score, and travel functionality.
 */
class Citizen
{

private:
     int satisfactionScore;                 ///< The satisfaction score of the citizen (ranges from 40 to 70 on creation).
     bool isEmployed;                       ///< Whether the citizen is employed.
     CitizenLocationState *citizenLocation; ///< The current location state of the citizen.
     CityUnit *citizenHome;                 ///< Pointer to the citizen's home.
     CityUnit *citizenJob;                  ///< Pointer to the citizen's job.
     CityUnit *citizenLeisure;              ///< Pointer to the citizen's prevered lesiure location
     int bankBalance;                       ///< The bank balance of the citizen (ranges from 20,000 to 100,000 on creation).
     
     /**
     * @brief Clamps the satisfaction score to ensure it remains within defined limits.
     */
     void clampSatisfaction();

public:
    std::string lastUsedStrategyName;      ///< The name of the last travel strategy used by the citizen.
     /**
      * @brief Constructor for Citizen class.
      * @param home Pointer to the citizen's home CityUnit.
      * @param job Pointer to the citizen's job CityUnit (can be nullptr if unemployed).
      * @param leisure Pointer to the citizen's preferred leisure spot (randomly chosen)
      */
     Citizen(CityUnit *home, CityUnit *job, CityUnit *leisure);

     /**
      * @brief Destructor for Citizen class.
      */
     ~Citizen();

     /**
     * @brief Gets the citizen's leisure location.
     * 
     * @return Pointer to the CityUnit representing the leisure location.
     */
    CityUnit *getLeisure() const;

    /**
     * @brief Updates the citizen's satisfaction level based on the specified operation and value.
     * 
     * @param op A string representing the operation ("increase" or "decrease").
     * @param value The amount to adjust the satisfaction score by.
     */
    void updateSatisfaction(std::string op, int value);

    /**
     * @brief Gets the citizen's home location.
     * 
     * @return Pointer to the CityUnit representing the citizen's home.
     */
    CityUnit *getHome() const;

    /**
     * @brief Gets the citizen's job location.
     * 
     * @return Pointer to the CityUnit representing the citizen's job.
     */
    CityUnit *getJob() const;

    /**
     * @brief Gets the current satisfaction level of the citizen.
     * 
     * @return The satisfaction score as an integer.
     */
    int getSatisfaction() const;

    /**
     * @brief Gets the current bank account balance of the citizen.
     * 
     * @return The bank balance as an integer.
     */
    int getBalance() const;

    /**
     * @brief Gets the current location state of the citizen.
     * 
     * @return Pointer to the current CitizenLocationState.
     */
    CitizenLocationState *getCitzenLocationSate();

    /**
     * @brief Sets the citizen's location state while ensuring memory safety.
     * 
     * @param newState Pointer to the new state to transition to. Allowed values: AtHomeState, AtWorkState, AtLeisureState.
     */
    void setState(CitizenLocationState *newState);

    /**
     * @brief Attempts to employ the citizen at the given job location.
     *
     * This method sets the `citizenJob` pointer if the citizen is currently unemployed.
     * 
     * @param job Pointer to the CityUnit (building) where the citizen will be employed if successful.
     * @return true if the citizen was unemployed and successfully assigned a job; false if the citizen is already employed.
     */
    bool employCitizen(CityUnit *job);

    /**
     * @brief Allows the citizen to relax at a given leisure location.
     * 
     * @param stripclub Pointer to the leisure location where the citizen will relax.
     * @return true if the relaxation action was successful; false otherwise.
     */
    bool relaxCitizen(CityUnit *stripclub);

    /**
     * @brief Makes the citizen travel to the next location in their routine: home → leisure → job.
     *
     * This method also slightly influences the citizen's satisfaction based on their current state.
     */
    void followRoutine();

    /**
     * @brief Subtracts the specified tax amount from the citizen's bank account.
     * 
     * @param amount The tax amount to be deducted from the citizen's balance.
     */
    void takeTax(double amount);

    /**
     * @brief Adds the specified amount to the citizen's bank account.
     * 
     * This method is called to simulate receiving a salary for employed citizens.
     * 
     * @param amount The amount to be added to the bank balance.
     */
    void recieveSalary(double amount);
};

#endif
