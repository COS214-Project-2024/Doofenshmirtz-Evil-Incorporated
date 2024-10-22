#ifndef WEBSOCKETNOTIFIER_H
#define WEBSOCKETNOTIFIER_H

#include "Server.h"

class WebSocketNotifier {

private:
	Server* myServer;

public:
	WebSocketNotifier();

	void log(nlohmann::json message);

	void setServer(Server* server);

	static WebSocketNotifier* getInstance();

	~WebSocketNotifier();
};

#endif
