#include "Citizen.h"
#include <random>
#include <ctime>
#include "Commercial.h"
/**
 * @brief Constructs a Citizen with a given home, job and leisure.
 * Initializes satisfaction score and bank balance randomly.
 */
Citizen::Citizen(CityUnit *home, CityUnit *job, CityUnit *leisure)
{
    // Satisfaction between 40 and 70
    srand(time(0));
    this->satisfactionScore = 40 + (rand() % 30);

    // Default state at home
    this->citizenLocation = nullptr;
    this->setState(new AtHomeState());

    // Give citizen a job association if parameter is not a nullptr
    if (job != nullptr)
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

    this->lastUsedStrategyName = "none";
}

/**
 * @brief Clamping the satisfaction between 0 and 100
 */
void Citizen::clampSatisfaction()
{
    satisfactionScore = std::max(0, std::min(100, satisfactionScore));
}

/**
 * @brief Destructor that cleans up Citizen resources.
 */
Citizen::~Citizen()
{
    if (this->citizenLocation != nullptr)
    {
        delete this->citizenLocation;
    }
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
 * @brief updates the citizen'z satisfaction level according to an operator and a value passed in
 */
void Citizen::updateSatisfaction(std::string op, int value)
{
    if (op == "+")
    {
        this->satisfactionScore += value;
    }
    else
    {
        this->satisfactionScore -= value;
    }
    clampSatisfaction();
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
 * @brief Getter for citizen's current satisfaction level
 */
int Citizen::getSatisfaction() const
{
    return this->satisfactionScore;
}

/**
 * @brief Getter for citizen's current bank account balance
 */
int Citizen::getBalance() const
{
    return this->bankBalance;
}

/**
 * @brief Getter for citizen's state
 */
CitizenLocationState *Citizen::getCitzenLocationSate()
{
    return this->citizenLocation;
}

/**
 * @brief Make citizen travel to next location in their natural routine i.e. home => leisure => job
 * FFurthermore, slighlty influences satisfaction based on current state of citizen
 */
void Citizen::followRoutine()
{
    srand(time(0));
    this->citizenLocation->travel(this);

    // Check for leisure state and increase satisfaction by [0-20]
    if (this->citizenLocation->getStateName() == "AtLeisureState")
    {
        this->satisfactionScore += (rand() % 20);
    }

    // Checks for work state and decrease satisfaction by [0-10]
    if (this->citizenLocation->getStateName() == "AtWorkState")
    {
        this->satisfactionScore -= (rand() % 10);
    }

    // Checks for home state and either increase or decreases satisfaction by [0-10]
    if (this->citizenLocation->getStateName() == "AtHomeState")
    {
        int satisfactionInfluence = rand() % 10;

        (satisfactionInfluence % 2 == 0) ? this->satisfactionScore += satisfactionInfluence : this->satisfactionScore -= satisfactionInfluence;
    }
    clampSatisfaction();
}

/**
 * @brief Traverses citizen state in a memory safe manner
 */
void Citizen::setState(CitizenLocationState *newState)
{

    if (newState == this->citizenLocation)
    {
        return;
    }

    if (this->citizenLocation != nullptr)
    {
        delete this->citizenLocation;
    }

    this->citizenLocation = newState;
}

/**
 * @brief Attempts to employ the citizen at the given job location.
 *
 * This method sets the `citizenJob` pointer for the citizen if they are currently unemployed.
 * If the citizen is already employed (i.e., `citizenJob` is not nullptr), the method will do nothing.
 *
 * @param job A pointer to the CityUnit (building) where the citizen will be employed if the operation is successful.
 * @return true if the citizen was unemployed and successfully assigned a job, false if the citizen already had a job.
 */
bool Citizen::employCitizen(CityUnit *job)
{

    if (!this->isEmployed && job != nullptr)
    {
        this->isEmployed = true;
        this->citizenJob = job;
        job->setUsedCapacity(job->getUsedCapacity()+1);
        return true;
    }

    return false;
}

bool Citizen::relaxCitizen(CityUnit *stripclub)
{
    if (this->getLeisure() == nullptr)
    {
        this->citizenLeisure = stripclub;
        return true;
    }
    return false;
}

/**
 * @brief Used in district to collect tax
 * This method subtracts the tax amount from the bank account of the citizen
 * Influences Happiness based on amount
 */
void Citizen::takeTax(double amount)
{   
    double ratioOfCitizenBalanceTaken = amount / bankBalance;

    this->bankBalance -= amount;

    // For every 10 percent above 30% tax rate ==> decrease satisfaction by 10
    if(ratioOfCitizenBalanceTaken >= 0.3)
    {
        int satisfactionDecrease = (ratioOfCitizenBalanceTaken * 100) - 30;

        if(this->satisfactionScore - satisfactionDecrease < 0)
        {
            this->satisfactionScore = 0;
        }
        else
        {
            this->satisfactionScore -= satisfactionDecrease;
        }

    }




}

/**
 *@brief Used in comercial to recieve salary for employed citizens
 *It takes in an amount and adds it to the bank balance
 */
void Citizen::recieveSalary(double amount)
{
    this->bankBalance += amount;
}