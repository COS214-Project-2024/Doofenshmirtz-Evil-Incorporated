#include "WebSocketNotifier.h"
#include "SimulationRunnerFacade.h"
#include <iostream>

/**
 * @brief Implementation of the simulation loop
 *
 * @details This method runs the main simulation loop. During each iteration:
 * - Checks if the simulation should continue
 * - Creates a JSON messages
 * - Sends the messages through the WebSocketNotifier
 * - Waits a certain time before the next iteration
 *
 * The simulation continues until the stopFlag_ is set to true.
 *
 * @note This method blocks until the simulation is stopped
 *
 * @see WebSocketNotifier::log() for message transmission details
 */
void SimulationRunnerFacade::runSimulation()
{
	while (!(*stopFlag_))
	{
		nlohmann::json message = {
			{"type", "news"},
			{"data", "Simulation is running..."}};

		WebSocketNotifier::get_mutable_instance().log(message);
		sleep(1);
	}
}