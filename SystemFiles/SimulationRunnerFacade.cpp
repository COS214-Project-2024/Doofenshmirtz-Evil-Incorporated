#include "SimulationRunnerFacade.h"
#include "Government.h"
#include <iostream>

SimulationRunnerFacade::SimulationRunnerFacade()
{
}

void SimulationRunnerFacade::attachGovernment()
{
	government = Government::getGovernment();
}

void SimulationRunnerFacade::runSimulation()
{
	std::cout << "Running the simulation..." << std::endl;

	if (government)
	{
		std::cout << "Government entity attached." << std::endl;
	}
	else
	{
		std::cout << "No government entity attached." << std::endl;
	}
}

SimulationRunnerFacade::~SimulationRunnerFacade()
{
}
