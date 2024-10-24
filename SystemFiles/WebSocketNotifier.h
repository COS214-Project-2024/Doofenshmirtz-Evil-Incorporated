#ifndef WEBSOCKETNOTIFIER_H
#define WEBSOCKETNOTIFIER_H
#include "Server.h"
#include <boost/serialization/singleton.hpp>
#include <nlohmann/json.hpp>

/**
 * @brief Singleton class for logging messages via WebSocket.
 *
 * This class serves as a notifier that sends log messages
 * to the connected WebSocket server. It is designed as a
 * singleton to ensure a single instance is used throughout
 * the application.
 */
class WebSocketNotifier : public boost::serialization::singleton<WebSocketNotifier>
{
public:
	/// Sends a JSON message to the WebSocket server.
	/// @param message The JSON object containing the message to log.
	void log(nlohmann::json message);
	/// Sets the server instance for this notifier.
	/// @param server Pointer to the Server instance to send messages.
	void setServer(Server *server);

private:
	Server *myServer; ///< Pointer to the WebSocket server instance.
};

#endif