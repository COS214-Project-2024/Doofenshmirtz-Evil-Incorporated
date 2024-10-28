#ifndef SERVER_H
#define SERVER_H

#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/asio.hpp>
#include <memory>
#include <atomic>
#include <nlohmann/json.hpp>
#include <iostream>
#include "WebSocketNotifier.h"

namespace beast = boost::beast;
namespace websocket = beast::websocket;
namespace net = boost::asio;
using tcp = net::ip::tcp;

/**
 * @brief WebSocket server class that handles client connections and message processing
 *
 * @details This class implements a WebSocket server that can handle a single client
 * connection. It supports starting and stopping the server, handling client sessions,
 * and sending/receiving messages. The server runs on a specified port and can process
 * commands from the client.
 *
 * @note This class inherits from enable_shared_from_this to safely create shared
 * pointers to this instance when needed
 */
class Server : public std::enable_shared_from_this<Server>
{
public:
	/**
	 * @brief Construct a new Server object
	 *
	 * @details Initializes the server with default values. The server starts in a
	 * non-running state and must be explicitly started using the start() method
	 */
	Server() : io_context_(), acceptor_(io_context_), ws_stream_(), running_(false) {}
	/**
	 * @brief Destroy the Server object
	 *
	 * @details Ensures proper cleanup by calling stop() to close any open connections
	 * and free resources
	 */
	virtual ~Server();
	/**
	 * @brief Start the WebSocket server
	 *
	 * @details Initializes the server on port 12345 and begins accepting client
	 * connections. The server will run until explicitly stopped or an error occurs
	 */
	void start();
	/**
	 * @brief Stop the WebSocket server
	 *
	 * @details Closes any active connections, stops accepting new connections,
	 * and performs cleanup of resources
	 */
	void stop();
	/**
	 * @brief Handle an individual client session
	 *
	 * @param socket TCP socket for the connected client
	 *
	 * @details Manages the WebSocket connection with a client, processes incoming
	 * messages, and handles 'start' and 'stop' commands
	 */
	void handleSession(tcp::socket socket);
	/**
	 * @brief Send a JSON message to the connected client
	 *
	 * @param request JSON object to be sent to the client
	 *
	 * @details Thread-safe method to send JSON messages to the connected client.
	 * If no client is connected or an error occurs, the message will not be sent
	 */
	virtual void write(const nlohmann::json &request);
	/**
	 * @brief Set the flag that will be triggered by the 'start' command
	 *
	 * @param flag Pointer to atomic boolean that will be set when start command is received
	 */
	void setStartFlag(std::atomic<bool> *flag);
	/**
	 * @brief Set the flag that will be triggered by the 'stop' command
	 *
	 * @param flag Pointer to atomic boolean that will be set when stop command is received
	 */
	void setStopFlag(std::atomic<bool> *flag);

private:
	net::io_context io_context_;								///< IO context for asynchronous operations
	tcp::acceptor acceptor_;									///< Acceptor for incoming TCP connections
	std::shared_ptr<websocket::stream<tcp::socket>> ws_stream_; ///< WebSocket stream for the connected client
	std::atomic<bool> running_;									///< Flag indicating if the server is running
	std::atomic<bool> *startFlag_;								///< Pointer to external start flag
	std::atomic<bool> *stopFlag_;								///< Pointer to external stop flag
	std::mutex mutex_;											///< Mutex for thread-safe operations
};

#endif