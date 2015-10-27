//
// Created by Zhenglai Zhang on 10/27/15.
//


#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include "SimpleSyncServer.hpp"

using namespace boost::asio;
using namespace std;


void client_session(socket_ptr sock);

void SimpleSyncServer::start() {
    while (true) {
        socket_ptr sock(new ip::tcp::socket(service));
        acc.accept(*sock);
        boost::thread(boost::bind(client_session, sock));
    }
}

void client_session(socket_ptr sock) {
    while (true) {
        char data[512];
        size_t len = sock->read_some(buffer(data));
        if (len > 0)
            write(*sock, buffer("ok", 2));
    }
}
