#ifndef WEBSOCKETNOTIFIER_H
#define WEBSOCKETNOTIFIER_H

#include "Server.h"
#include <iostream>

class WebSocketNotifier
{

public:
	static WebSocketNotifier *getInstance();
	void log(nlohmann::json message);
	void setServer(Server *server);

protected:
	WebSocketNotifier();
	~WebSocketNotifier();

private:
	Server *myServer;
	static WebSocketNotifier *Instance;
};

#endif
