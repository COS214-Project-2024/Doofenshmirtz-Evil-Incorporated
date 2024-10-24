#include "SimulationRunnerFacade.h"
#include "Government.h"
#include "WebSocketNotifier.h"
#include <iostream>
#include <nlohmann/json.hpp>

/**
 * @brief Constructor for the SimulationRunnerFacade class.
 *
 * This constructor initializes the facade. No additional setup is needed
 * for this class at the moment.
 */
SimulationRunnerFacade::SimulationRunnerFacade()
{
	// No initialization needed in the constructor.
}

/**
 * @brief Runs the simulation and sends updates via WebSocket.
 *
 * This method executes the main simulation loop (currently simplified to a
 * single iteration) and constructs a JSON message to notify observers
 * of changes in the simulation state. The message is logged through the
 * WebSocketNotifier.
 */
void SimulationRunnerFacade::runSimulation()
{
	std::cout << "Running the simulation..." << std::endl;

	// Create a JSON message
	nlohmann::json message = {
		{"type", "valueUpdate"},
		{"data", {{"id", "money"}, {"value", "10"}}}};

	// Log the message through the WebSocketNotifier instance.
	WebSocketNotifier::get_mutable_instance().log(message);
}

/**
 * @brief Destructor for the SimulationRunnerFacade class.
 *
 * This destructor performs any necessary cleanup when the facade is destroyed.
 */
SimulationRunnerFacade::~SimulationRunnerFacade()
{
	// No cleanup needed in the destructor.
}