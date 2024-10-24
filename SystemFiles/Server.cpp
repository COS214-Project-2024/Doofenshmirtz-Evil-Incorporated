#include "Server.h"

Server::Server()
{
	// No initialization needed for the constructor.
}

Server::~Server()
{
	// No cleanup needed for the destructor.
}

void Server::setStartFlag(std::atomic<bool> *flag)
{
	startFlag = flag; // Set the shared start flag pointer.
}

/**
 * @brief Handle a WebSocket session with a client.
 *
 * This function is called for each incoming WebSocket connection.
 * It reads messages from the client and prints them to standard output.
 * The session continues until the WebSocket connection is closed.
 *
 * @param socket The TCP socket for the client connection.
 */
void Server::handleSession(tcp::socket socket)
{
	try
	{
		// Create a shared pointer for the WebSocket stream.
		auto local_ws_stream = std::make_shared<websocket::stream<tcp::socket>>(std::move(socket));
		ws_stream = local_ws_stream; /// Assign to the instance's ws_stream for sending messages.
		local_ws_stream->accept();	 // Accept WebSocket connection

		for (;;)
		{
			beast::flat_buffer buffer;	   // Buffer to hold incoming messages.
			local_ws_stream->read(buffer); // Read a message into the buffer.
			std::cout << "Received message: " << beast::buffers_to_string(buffer.data()) << std::endl;
			// Check for the "start" command to set the start flag.
			if (beast::buffers_to_string(buffer.data()) == "start")
			{
				*startFlag = true; // Signal to start the process.
			}
		}
	}
	catch (const std::exception &e)
	{
		// Catch and log any exceptions that occur during the session.
		std::cerr << "Error in session: " << e.what() << std::endl;
	}
}

/**
 * @brief Start the server and accept incoming connections.
 *
 * This function initializes the server and begins accepting
 * incoming WebSocket connections. For each connection,
 * a new thread is spawned to handle the WebSocket session.
 */
void Server::start()
{
	try
	{
		net::io_context io_context;											 // Create the I/O context for asynchronous operations.
		tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 12345)); // Set up the acceptor on port 12345.
		std::cout << "Server is running on port 12345" << std::endl;

		while (true)
		{
			tcp::socket socket(io_context);										   // Create a socket to accept new connections.
			acceptor.accept(socket);											   // Wait for a connection.
			std::thread(&Server::handleSession, this, std::move(socket)).detach(); // Spawn a new thread to handle the session with the connected client.
		}
	}
	catch (const std::exception &e)
	{
		// Log any exceptions that occur while starting the server.
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

/**
 * @brief Write a JSON message to the WebSocket stream.
 *
 * This function sends the provided JSON request as a message
 * over the WebSocket connection. If the WebSocket connection
 * is not active, it logs an error message.
 *
 * @param request The JSON object to be sent.
 */
void Server::write(nlohmann::json request)
{
	// Check if there is an active WebSocket connection before sending the message.
	if (ws_stream && ws_stream->is_open())
	{
		std::string message = request.dump();	// Serialize the JSON object to a string.
		ws_stream->write(net::buffer(message)); // Send the message over the WebSocket.
		std::cout << "Sent message: " << message << std::endl;
	}
	else
	{
		// Log an error if there is no active WebSocket connection.
		std::cerr << "No active WebSocket connection to send message." << std::endl;
	}
}