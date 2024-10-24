#include "WebSocketNotifier.h"

/**
 * @brief Log a message by sending it to the WebSocket server.
 *
 * This function delegates the message to the server's write function
 * if the server instance has been set. If not, it outputs an error
 * message to the console.
 *
 * @param message The JSON object to be sent to the server.
 */
void WebSocketNotifier::log(nlohmann::json message)
{
	if (myServer)
	{
		myServer->write(message); // Delegate message to server
	}
	else
	{
		std::cout << "Server not set for WebSocketNotifier" << std::endl;
	}
}

/**
 * @brief Set the server instance for this notifier.
 *
 * This function allows the WebSocketNotifier to reference a specific
 * Server instance to which it can send log messages.
 *
 * @param server Pointer to the Server instance to set.
 */
void WebSocketNotifier::setServer(Server *server)
{
	myServer = server;
}