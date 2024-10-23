#ifndef SIMULATIONRUNNERFACADE_H
#define SIMULATIONRUNNERFACADE_H

class Government;

class SimulationRunnerFacade
{

private:
    Government *government;

public:
    SimulationRunnerFacade();
    void attachGovernment();
    void runSimulation();
    ~SimulationRunnerFacade();
};

#endif
