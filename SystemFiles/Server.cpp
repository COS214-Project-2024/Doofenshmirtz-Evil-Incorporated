#include "Server.h"

Server::~Server()
{
	stop();
}

void Server::setStartFlag(std::atomic<bool> *flag) { startFlag_ = flag; }
void Server::setStopFlag(std::atomic<bool> *flag) { stopFlag_ = flag; }
void Server::setEducationFlag(std::atomic<bool> *flag) { EducationFlag_ = flag; }
void Server::setWorkFlag(std::atomic<bool> *flag) { ShortWorkFlag_ = flag; }
void Server::setTaxFlag(std::atomic<bool> *flag)
{
	TaxFlag_ = flag;
}
/**
 * @brief Implementation of client session handling
 *
 * @details This method runs in its own thread and manages the lifecycle of a client
 * connection. It processes incoming messages and responds to commands.
 * The session continues until either a 'stop' command is received or an error occurs.
 *
 * @param socket Connected client socket to be managed
 *
 * @throws May throw exceptions related to WebSocket operations which are caught and logged
 */
void Server::handleSession(tcp::socket socket)
{
	try
	{
		auto ws = std::make_shared<websocket::stream<tcp::socket>>(std::move(socket));
		{
			std::lock_guard<std::mutex> lock(mutex_);
			ws_stream_ = ws;
		}

		ws->accept();
		std::cout << "Client connected" << std::endl;

		while (running_)
		{
			beast::flat_buffer buffer;
			ws->read(buffer);
			std::string message = beast::buffers_to_string(buffer.data());

			if (message == "start" && startFlag_)
			{
				*startFlag_ = true;
			}
			else if (message == "stop" && stopFlag_)
			{
				*stopFlag_ = true;
				break;
			}
			else if (message == "education")
			{
				*EducationFlag_ = true;
				*ShortWorkFlag_ = false;
			}
			else if (message == "shortwork")
			{
				*ShortWorkFlag_ = true;
				*EducationFlag_ = false;
			}
			else if (message.compare(0, 3, "tax") == 0)
			{
				*TaxFlag_ = true;
				std::string rateStr = message.substr(4);
				taxRate_ = std::stoi(rateStr);
			}
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << "Session error: " << e.what() << std::endl;
	}
}

/**
 * @brief Implementation of server start procedure
 *
 * @details Initializes the server on port 12345 and begins accepting connections.
 * Only one client connection is handled at a time. The server continues running
 * until explicitly stopped or an error occurs.
 *
 * @throws May throw exceptions related to socket operations which are caught and logged
 */
void Server::start()
{
	try
	{
		running_ = true;
		acceptor_ = tcp::acceptor(io_context_, tcp::endpoint(tcp::v4(), 12345));
		std::cout << "Server running on port 12345" << std::endl;

		while (running_)
		{
			tcp::socket socket(io_context_);
			acceptor_.accept(socket);
			// Only handle one client
			handleSession(std::move(socket));
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << "Server error: " << e.what() << std::endl;
	}
}

/**
 * @brief Implementation of server stop procedure
 *
 * @details Safely shuts down the server by closing the acceptor and any active
 * WebSocket connections. This method is thread-safe and can be called from any thread.
 *
 * @throws May throw exceptions related to socket operations which are caught and logged
 */
void Server::stop()
{
	running_ = false;
	try
	{
		if (acceptor_.is_open())
		{
			acceptor_.close();
		}

		std::lock_guard<std::mutex> lock(mutex_);
		if (ws_stream_ && ws_stream_->is_open())
		{
			ws_stream_->close(websocket::close_code::normal);
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error stopping server: " << e.what() << std::endl;
	}
}

/**
 * @brief Implementation of JSON message writing to WebSocket
 *
 * @details Sends a JSON message to the connected client in a thread-safe manner.
 * If no client is connected or the connection is closed, the message will not be sent.
 *
 * @param request The JSON object to be sent to the client
 *
 * @throws May throw exceptions related to WebSocket operations which are caught and logged
 */
void Server::write(const nlohmann::json &request)
{
	try
	{
		std::lock_guard<std::mutex> lock(mutex_);
		if (ws_stream_ && ws_stream_->is_open())
		{
			std::string message = request.dump();
			ws_stream_->write(net::buffer(message));
			std::cout << "Sent message: " << message << std::endl;
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error writing to websocket: " << e.what() << std::endl;
	}
}
