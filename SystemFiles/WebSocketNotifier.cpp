/**
 * @file WebSocketNotifier.h
 * @brief Implements the WebSocketNotifier class.
 */

#include "WebSocketNotifier.h"

/**
 * @brief Implementation of JSON message logging
 *
 * @param message The JSON message to be logged/sent through the WebSocket
 *
 * @details Checks if a valid server instance exists and forwards the message
 * to that server's write method. If no server is configured, the message
 * will be silently dropped.
 *
 * @note This implementation maintains the strong exception guarantee - if the
 * server write fails, the WebSocketNotifier remains in its original state
 */
void WebSocketNotifier::log(const nlohmann::json &message)
{
	if (server_)
	{
		server_->write(message);
	}
}

/**
 * @brief Implementation of server configuration
 *
 * @param server Shared pointer to the Server instance to be used for message transmission
 *
 * @details Updates the internal server pointer with the provided instance.
 * The shared_ptr ensures proper memory management of the server instance.
 *
 * @warning This method should not be called while log operations are in progress
 * as it's not thread-safe with respect to logging
 */
void WebSocketNotifier::setServer(std::shared_ptr<Server> server)
{
	server_ = server;
}