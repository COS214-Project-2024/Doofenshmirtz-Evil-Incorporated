#include "Server.h"

Server::Server() : ws_stream(nullptr)
{
}

Server::~Server()
{
}

void Server::handleSession(tcp::socket socket)
{
	try
	{
		// Create the WebSocket stream and store it as a member
		ws_stream = std::make_shared<websocket::stream<tcp::socket>>(std::move(socket));

		ws_stream->accept(); // Accept WebSocket connection

		for (;;)
		{
			beast::flat_buffer buffer;
			ws_stream->read(buffer); // Read a message into the buffer

			// Print the received message to the console
			std::cout << "Received message: " << beast::buffers_to_string(buffer.data()) << std::endl;
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error in session: " << e.what() << std::endl;
	}
}

void Server::start()
{
	try
	{
		// Set up an io_context
		net::io_context io_context;

		// Create a listener
		tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 12345));

		std::cout << "Server is running on port 12345" << std::endl;

		while (true)
		{
			// Accept a new connection
			tcp::socket socket(io_context);
			acceptor.accept(socket);
			std::thread(&Server::handleSession, this, std::move(socket)).detach();
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

void Server::write(nlohmann::json request)
{
	if (ws_stream && ws_stream->is_open())
	{
		// Serialize the JSON and send it via WebSocket
		std::string message = request.dump();
		ws_stream->write(net::buffer(message));
		std::cout << "Sent message: " << message << std::endl;
	}
	else
	{
		std::cerr << "No active WebSocket connection to send message." << std::endl;
	}
}
