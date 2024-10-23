#ifndef SERVER_H
#define SERVER_H

#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <nlohmann/json.hpp>
#include <iostream>

namespace beast = boost::beast;
namespace http = beast::http;
namespace websocket = beast::websocket;
namespace net = boost::asio;
using tcp = net::ip::tcp;

class Server
{

public:
	Server();

	~Server();

	void start();

	void handleSession(tcp::socket socket);

	void write(nlohmann::json request);

private:
	std::shared_ptr<websocket::stream<tcp::socket>> ws_stream;
};

#endif
