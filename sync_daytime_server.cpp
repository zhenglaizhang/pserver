//
// Created by darinzh on 10/27/2015.
//

#include <iostream>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/array.hpp>
#include <ctime>

using namespace std;
using namespace boost::asio;

using boost::asio::ip::tcp;


std::string make_daytime_string()
{
    using namespace std; // for time_t time
    time_t now = time(0);
    return ctime(&now);
}

int main(int argc, char *argv[]) {
    try {
        boost::asio::io_service io;
        tcp::acceptor acceptor(io, tcp::endpoint(tcp::v4(), 13));
        while (true) {
            tcp::socket socket(io);
            acceptor.accept(socket);
            string message = make_daytime_string();
            boost::system::error_code ignored_error;
            boost::asio::write(socket, boost::asio::buffer(message), ignored_error);
        }

    } catch (std::exception& e) {
        cerr << "Error: " <<  e.what() << endl;
    }

}

