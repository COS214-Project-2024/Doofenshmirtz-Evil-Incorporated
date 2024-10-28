// DemoMain.h

// Main entry point for the simulation demo application that coordinates
// between a WebSocket server and simulation runner. The program waits for
// a start signal from clients before beginning the simulation.
#include "Server.h"
#include "SimulationRunnerFacade.h"
#include "WebSocketNotifier.h"
#include <thread>
#include <atomic>
#include <chrono>

int main()
{
    // Control flags for coordinating between server and simulation
    std::atomic<bool> startFlag(false); // Set to true when simulation should start
    std::atomic<bool> stopFlag(false);  // Set to true to terminate the program

    // Initialize server component
    // The server handles WebSocket connections from clients and
    // responds to commands
    auto server = std::make_shared<Server>();
    server->setStartFlag(&startFlag);
    server->setStopFlag(&stopFlag);

    // Configure WebSocket notification system
    // This allows the simulation to send progress updates to connected clients
    WebSocketNotifier::get_mutable_instance().setServer(server);

    // Launch server in separate thread to handle client connections
    // asynchronously while main thread manages simulation
    std::thread serverThread([&server]()
                             { server->start(); });

    std::cout << "Waiting for start signal..." << std::endl;

    // Initialize simulation system
    SimulationRunnerFacade simulation(&stopFlag);

    // Main control loop: wait for either start or stop signal from server
    while (!startFlag && !stopFlag)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    // Execute simulation if start signal received and stop not triggered
    if (startFlag && !stopFlag)
    {
        std::cout << "Starting simulation..." << std::endl;
        try
        {
            simulation.runSimulation();
        }
        catch (const std::exception &e)
        {
            std::cerr << "Simulation error: " << e.what() << std::endl;
            stopFlag = true;
        }
    }

    // Cleanup phase: ensure server shuts down properly
    server->stop();
    if (serverThread.joinable())
    {
        serverThread.join(); // Wait for server thread to complete
    }

    std::cout << "Program terminated gracefully." << std::endl;
    return 0;
}