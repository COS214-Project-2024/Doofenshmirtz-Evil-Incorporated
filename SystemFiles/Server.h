/**
 * @file BuildingFactory.h
 * @brief Defines the BuildingFactory class for creating building objects.
 */

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
	Server(int &taxRate) : io_context_(), acceptor_(io_context_), ws_stream_(), running_(false), taxRate_(taxRate) {}
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

	/**
	 * @brief Set the flag that will be triggered by the 'education' command
	 *
	 * @param flag Pointer to atomic boolean that will be set when education command is received
	 */
	void setEducationFlag(std::atomic<bool> *flag);

	/**
	 * @brief Set the flag that will be triggered by the 'shortwork' command
	 *
	 * @param flag Pointer to atomic boolean that will be set when short work command is received
	 */
	void setWorkFlag(std::atomic<bool> *flag);

	/**
	 * @brief Set the flag that will be triggered by the 'tax' command
	 *
	 * @param flag Pointer to atomic boolean that will be set when tax command is received
	 */
	void setTaxFlag(std::atomic<bool> *flag);

private:
	/**
	 * @brief IO context for managing asynchronous operations.
	 * 
	 * This object is used to initiate and manage asynchronous I/O operations 
	 * in a networked environment, serving as the main event loop for 
	 * handling asynchronous tasks.
	 */
	net::io_context io_context_; ///< IO context for managing asynchronous operations.

	/**
	 * @brief Acceptor for handling incoming TCP connections.
	 * 
	 * Used to listen for and accept incoming TCP connection requests.
	 */
	tcp::acceptor acceptor_; ///< Acceptor for incoming TCP connections

	/**
	 * @brief WebSocket stream for communicating with the connected client.
	 * 
	 * A shared pointer to a WebSocket stream object, which facilitates WebSocket
	 * communication over a TCP socket.
	 */
	std::shared_ptr<websocket::stream<tcp::socket>> ws_stream_;  ///< WebSocket stream for the connected client

	/**
	 * @brief Flag indicating if the server is running.
	 * 
	 * An atomic boolean used to track the running state of the server
	 * in a thread-safe manner.
	 */
	std::atomic<bool> running_; ///< Flag indicating if the server is running

	/**
	 * @brief Pointer to an external start flag.
	 * 
	 * Used to check or modify the start status of the server from
	 * an external source.
	 */
	std::atomic<bool> *startFlag_; ///< Pointer to external start flag

	/**
	 * @brief Pointer to an external stop flag.
	 * 
	 * Used to check or modify the stop status of the server from
	 * an external source.
	 */
	std::atomic<bool> *stopFlag_; ///< Pointer to external stop flag

	/**
	 * @brief Mutex for ensuring thread-safe operations.
	 * 
	 * Used to lock critical sections of the code to prevent
	 * data races and ensure thread safety.
	 */
	std::mutex mutex_; ///< Mutex for thread-safe operations

	/**
	 * @brief Pointer to an external education flag.
	 * 
	 * Represents an atomic boolean flag related to education, 
	 * managed from an external source.
	 */
	std::atomic<bool> *EducationFlag_; ///< Pointer to external education flag

	/**
	 * @brief Pointer to an external short work flag.
	 * 
	 * Represents an atomic boolean flag related to short work, 
	 * managed from an external source.
	 */
	std::atomic<bool> *ShortWorkFlag_; ///< Pointer to external Short work flag

	/**
	 * @brief Pointer to an external tax flag.
	 * 
	 * Represents an atomic boolean flag related to tax operations, 
	 * managed from an external source.
	 */
	std::atomic<bool> *TaxFlag_; ///< Pointer to external Tax flag

	/**
	 * @brief Reference to the tax rate.
	 * 
	 * An integer reference representing the current tax rate, 
	 * managed externally.
	 */
	int &taxRate_;
};

#endif