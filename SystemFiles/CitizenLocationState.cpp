/**
 * @file BuildingFactory.h
 * @brief Defines the BuildingFactory class for creating building objects.
 */

#include "CitizenLocationState.h"
#include <random>
#include "RoadStrategy.h"
#include "PublicTransportStrategy.h"
#include "RailwayStrategy.h"
#include "AirportStrategy.h"

/**
 * @brief Constructor for CitizenLocationState.
 */
CitizenLocationState::CitizenLocationState() {

	this->strategy = nullptr;
	srand(time(0));  
}


/**
 * @brief Chooses a commute strategy based on travel distance.
 * 
 * @param travelDistance The distance the citizen needs to travel.
 */
void CitizenLocationState::chooseStrategy(int travelDistance)
{
	// Clear old strategy
	if (this->strategy != nullptr)
	{
		delete this->strategy;
	}

	// For random aspect to make simulation more simulation-y
	
	int chance = rand() % 100;

	// Choose random strategy with a 12% chance
	if (chance < 12)
	{
		// Evenly distribute chances across 4 strategies
		int randomChoice = chance % 4;
		switch (randomChoice)
		{
			case 0:
				this->strategy = new RoadStrategy();
				break;
			case 1:
				this->strategy = new PublicTransportStrategy();
				break;
			case 2:
				this->strategy = new RailwayStrategy();
				break;
			case 3:
				this->strategy = new AirportStrategy();
				break;
		}
		return;
	}

	// If not random, choose based on travel distance
	if (travelDistance <= 5)
	{
		this->strategy = new RoadStrategy();
	}
	else if (travelDistance <= 10)
	{
		this->strategy = new PublicTransportStrategy();
	}
	else if (travelDistance <= 15)
	{
		this->strategy = new RailwayStrategy();
	}
	else if (travelDistance <= 30)
	{
		this->strategy = new AirportStrategy();
	}
}


std::string CitizenLocationState::getTravelMethod()
{
    if(this->strategy)
	{
		return this->strategy->getTravelStrategyName();
	}
	else
	{
		return "none";
	}
}

/**
 * @brief Destructor for CitizenLocationState.
 */
CitizenLocationState::~CitizenLocationState()
{
	if(strategy != nullptr)
	{
		delete strategy;
	}
	strategy = nullptr;
}


