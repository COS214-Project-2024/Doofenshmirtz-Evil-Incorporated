#include "WebSocketNotifier.h"

WebSocketNotifier::WebSocketNotifier() : myServer(nullptr)
{
	// Constructor, assign null to server
}

void WebSocketNotifier::log(nlohmann::json message)
{
	if (myServer)
	{
		myServer->write(message); // Delegate message to server
	}
	else
	{
		std::cout << "Server not set for WebSocketNotifier" << std::endl; // No server
	}
}

void WebSocketNotifier::setServer(Server *server)
{
	myServer = server; // Sets server
}

WebSocketNotifier *WebSocketNotifier::getInstance()
{
	if (Instance == nullptr) // If no instance
	{
		Instance = new WebSocketNotifier(); // create instance
	}
	return Instance;
}

WebSocketNotifier::~WebSocketNotifier()
{
}
