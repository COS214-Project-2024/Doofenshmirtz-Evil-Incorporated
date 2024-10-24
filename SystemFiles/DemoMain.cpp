#include "Server.h"
#include "SimulationRunnerFacade.h"
#include "WebSocketNotifier.h"
#include <thread>
#include <atomic>
#include <chrono>

/**
 * @brief Entry point of the application.
 *
 * This function initializes and starts the WebSocket server,
 * sets up the WebSocket notifier, and runs the simulation
 * based on incoming WebSocket messages.
 */
int main()
{
    // 1. Create and start the server in a separate thread.
    Server server;                      // Instantiate the server.
    std::atomic<bool> startFlag(false); // Flag to indicate when to start the simulation.
    std::thread serverThread([&]()
                             { server.start(); }); // Launch server on a new thread.

    // 2. Set the server instance for the WebSocketNotifier.
    WebSocketNotifier::get_mutable_instance().setServer(&server);

    // 3. Initialize the SimulationRunnerFacade to manage simulations.
    SimulationRunnerFacade simulation;

    // 4. Pass the start flag to the server for signaling.
    server.setStartFlag(&startFlag);

    // 5. Poll the start flag until it becomes true (waiting for the "start" message).
    while (!startFlag)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Avoid busy waiting with a small delay.
    }

    // 6. Run the simulation once the start signal is received.
    simulation.runSimulation();

    // 7. Wait for the server to stop (via a potential "stop" message).
    while (serverThread.joinable())
    {
        // Optionally check for a stop condition, if applicable.
        if (!startFlag) // Can be modified based on actual stop signal logic.
        {
            break; // Exit the loop if the server should stop.
        }
    }

    // 8. Join the server thread to ensure it stops gracefully before exiting.
    if (serverThread.joinable())
    {
        serverThread.join(); // Wait for the server thread to finish.
    }

    return 0; // Exit the application.
}
