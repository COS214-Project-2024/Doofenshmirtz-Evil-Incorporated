#ifndef SERVER_H
#define SERVER_H

#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <nlohmann/json.hpp>
#include <atomic>
#include <iostream>

/**
 * @brief Class representing a WebSocket server.
 *
 * This class handles incoming WebSocket connections, reads messages,
 * and allows sending JSON messages to connected clients.
 */
namespace beast = boost::beast;
namespace http = beast::http;
namespace websocket = beast::websocket;
namespace net = boost::asio;
using tcp = net::ip::tcp;

class Server
{
public:
	/// Constructor for the Server class.
	Server();
	/// Destructor for the Server class.
	virtual ~Server();
	/// Starts the server and begins accepting connections.
	void start();
	/// Handles a session with a connected client.
	/// @param socket The TCP socket associated with the client connection.
	void handleSession(tcp::socket socket);
	/// Sends a JSON message to the connected client.
	/// @param request The JSON object to be sent.
	virtual void write(nlohmann::json request);
	/// Sets the start flag for session management.
	/// @param flag Pointer to an atomic boolean that signals when to start runSimulation
	void setStartFlag(std::atomic<bool> *flag);

private:
	std::shared_ptr<websocket::stream<tcp::socket>> ws_stream; ///< WebSocket stream connection.
	std::atomic<bool> *startFlag;							   ///< Pointer to a shared flag indicating start status.
};

#endif