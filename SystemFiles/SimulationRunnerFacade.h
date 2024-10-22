#ifndef SIMULATIONRUNNERFACADE_H
#define SIMULATIONRUNNERFACADE_H

class Government;

class SimulationRunnerFacade {

private:
	Government* goverment;

public:

    SimulationRunnerFacade();

    void runSimulation();

    ~SimulationRunnerFacade();
};

#endif
