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
}


/**
 * @brief Chooses a commute strategy based on travel distance.
 * 
 * @param travelDistance The distance the citizen needs to travel.
 */
void CitizenLocationState::chooseStrategy(int travelDistance)
{
	//clear old strategy
	if(this->strategy != nullptr)
	{
		delete this->strategy;
	}
	//for random aspect to make simulation more simulation-y
	srand(time(0));
	int chance = rand() % 100;

	//choose random strategy
	if(chance <= 12)
	{
		if(chance <= 3)
		{
			this->strategy = new RoadStrategy();
			return;
		}
		if(chance <= 6)
		{
			this->strategy = new PublicTransportStrategy();
			return;
		}
		if(chance <= 9)
		{
			this->strategy = new RailwayStrategy();
			return;
		}
		if(chance <= 12)
		{
			this->strategy = new AirportStrategy();
			return;
		}
	}
	//If not random
	//The distances migh have to change based on how the computeDistance function is implemented
	else
	{
		if(travelDistance <= 5)
		{
			this->strategy = new RoadStrategy();
			return;
		}
		if(travelDistance <= 10)
		{
			this->strategy = new PublicTransportStrategy();
			return;
		}
		if(travelDistance <= 15)
		{
			this->strategy = new RailwayStrategy();
			return;
		}
		if(travelDistance <= 30)
		{
			this->strategy = new AirportStrategy();
			return;
		}
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


