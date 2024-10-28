#ifndef SIMULATIONRUNNERFACADE_H
#define SIMULATIONRUNNERFACADE_H

#include "WebSocketNotifier.h"
#include <atomic>

/**
 * @brief Facade class for running and managing simulations
 *
 * @details This class implements the Facade pattern to provide a simplified interface
 * for running simulations. It handles the simulation loop and communicates simulation
 * status through the WebSocketNotifier singleton. The simulation can be stopped
 * externally through an atomic flag.
 *
 * @note This class uses the WebSocketNotifier singleton to communicate simulation
 * status to connected clients
 */
class SimulationRunnerFacade
{

public:
    /**
     * @brief Construct a new SimulationRunnerFacade object
     *
     * @param stopFlag Pointer to atomic boolean that controls simulation execution
     *
     * @details Initializes the facade with a pointer to an external stop flag that
     * can be used to terminate the simulation loop
     *
     * @note The stopFlag must remain valid for the lifetime of the SimulationRunnerFacade
     */
    SimulationRunnerFacade(std::atomic<bool> *stopFlag) : stopFlag_(stopFlag) {}

    /**
     * @brief Run the simulation loop
     *
     * @details Executes the main simulation loop which continues until the stop flag
     * is set. During each iteration, it sends status updates through the WebSocketNotifier
     */
    void runSimulation();

private:
    std::atomic<bool> *stopFlag_; ///< Pointer to external flag controlling simulation execution
};

#endif