#ifndef SIMULATIONRUNNERFACADE_H
#define SIMULATIONRUNNERFACADE_H

class Government;

/**
 * @brief Facade class for running simulations.
 *
 * This class provides a simplified interface to run simulations,
 * coordinating interactions with other components, such as the
 * Government and WebSocketNotifier.
 */
class SimulationRunnerFacade
{

public:
    /// Constructor for the SimulationRunnerFacade class.
    SimulationRunnerFacade();
    /// Runs the simulation process.
    void runSimulation();
    /// Destructor for the SimulationRunnerFacade class.
    ~SimulationRunnerFacade();
};

#endif