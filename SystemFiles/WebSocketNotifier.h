#ifndef WEBSOCKETNOTIFIER_H
#define WEBSOCKETNOTIFIER_H

#include <boost/serialization/singleton.hpp>
#include <nlohmann/json.hpp>
#include <memory>
#include "Server.h"

class Server;
/**
 * @brief Singleton class for logging messages through WebSocket
 *
 * @details This class implements the Singleton pattern using boost::serialization::singleton
 * to provide a global point of access for sending messages through a WebSocket server.
 * It acts as a bridge between various parts of the application and the WebSocket server,
 * allowing components to send messages without direct coupling to the server.
 *
 * @note This class is thread-safe as long as setServer is not called while log
 * operations are in progress
 *
 * Usage example:
 * @code
 * WebSocketNotifier::get_mutable_instance().log({"type": "status", "data": "message"});
 * @endcode
 */
class WebSocketNotifier : public boost::serialization::singleton<WebSocketNotifier>
{
public:
	/**
	 * @brief Log a JSON message through the WebSocket server
	 *
	 * @param message JSON object to be sent through the WebSocket
	 *
	 * @details If a server has been set, this method will forward the message
	 * to the server's write method. If no server is set, the message will be silently
	 * dropped.
	 *
	 * @note This method is thread-safe with respect to message sending, but not
	 * with respect to server configuration changes
	 *
	 * @see Server::write() for details on message transmission
	 */
	void log(const nlohmann::json &message);

	/**
	 * @brief Set the WebSocket server instance
	 *
	 * @param server Shared pointer to the Server instance that will handle message transmission
	 *
	 * @details Updates the internal server pointer to the provided instance. This allows
	 * the notifier to be configured with different server instances at runtime.
	 *
	 * @warning This method is not thread-safe with respect to concurrent log operations.
	 * Ensure proper synchronization when changing the server while the system is active.
	 */
	void setServer(std::shared_ptr<Server> server);

private:
	std::shared_ptr<Server> server_; ///< Shared pointer to the WebSocket server instance
};

#endif