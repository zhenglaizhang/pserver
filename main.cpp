//
// Created by darinzh on 10/27/2015.
//

#include <boost/asio.hpp>
#include <iostream>
#include <memory>

using namespace boost::asio;

int main(int argc, char *argv[]) {
    io_service service;
    ip::tcp::endpoint ep(ip::address::from_string("127.0.0.1"), 2001);
    ip::tcp::socket sock(service);
    sock.connect(ep);
    std::cout << "Exit..." << std::endl;
    return 0;
}

