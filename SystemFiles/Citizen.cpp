#include "Citizen.h"
#include <random>


/**
 * @brief Constructs a Citizen with a given home, job and leisure.
 * Initializes satisfaction score and bank balance randomly.
 */
Citizen::Citizen(CityUnit *home, CityUnit *job, CityUnit* leisure)
{   
    // Satisfaction between 40 and 70
    srand(time(0));
    this->satisfactionScore = 40 + (rand() % 30);

    // Default at home
    this->setState(new AtHomeState());

    // Give citizen a job association if parameter is not a nullptr
    if(job != nullptr)
    {
        this->citizenJob = job;
        this->isEmployed = true;
    }
    else
    {
        this->citizenJob = nullptr;
        this->isEmployed = false;
    }

    // This *should* always be a valid pointer a citizen is only created when there is a residence for them to live in
    this->citizenHome = (home == nullptr) ? nullptr : home;

    // Set leisure location (should also always be valid)
    this->citizenLeisure = (leisure == nullptr) ? nullptr : leisure;

    // Bank balance between 20 000 and 100 000
    this->bankBalance = 20000 + (rand() % 80000);
}

/**
 * @brief Destructor that cleans up Citizen resources.
 */
Citizen::~Citizen()
{
    if(this->citizenLocation != nullptr) { delete this->citizenLocation; }
    this->citizenLocation = nullptr;
    this->citizenHome = nullptr;
    this->citizenJob = nullptr;
}

/**
 * @brief Getter for citizen's leisure location CityUnit*
 */
CityUnit *Citizen::getLeisure() const
{
    return this->citizenLeisure;
}


/**
 * @brief Getter for citizen's current Home CityUnit*
 */
CityUnit *Citizen::getHome() const
{
    return this->citizenHome;
}

/**
 * @brief Getter for citizen's current job CityUnit*
 */
CityUnit *Citizen::getJob() const
{
    return this->citizenJob;
}

/**
 * @brief Make citizen travel to next location in their natural routine i.e. home => leisure => job
 */
void Citizen::followRoutine()
{
    this->citizenLocation->travel(this);
}


/**
 * @brief Traverses citizen state in a memory safe manner
 */
void Citizen::setState(CitizenLocationState *newState)
{
    if(this->citizenLocation != nullptr)
    {
        delete this->citizenLocation;
    }

    this->citizenLocation = newState;
}