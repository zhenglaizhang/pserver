//
// Created by Zhenglai Zhang on 10/27/15.
//

#ifndef CXX_SIMPLESYNCSERVER_HPP
#define CXX_SIMPLESYNCSERVER_HPP

#include <boost/asio.hpp>

using namespace boost::asio;

typedef boost::shared_ptr<ip::tcp::socket> socket_ptr;

class SimpleSyncServer {
public:

    // default ipv4:2001?

    SimpleSyncServer(const ip::tcp::endpoint &ep) :
            ep(ep), acc(service, ep) { }

    void start();

private:
    io_service service;
    ip::tcp::endpoint ep;
    ip::tcp::acceptor acc;
};


#endif //CXX_SIMPLESYNCSERVER_HPP
