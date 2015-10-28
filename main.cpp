//
// Created by darinzh on 10/27/2015.
//

#include <iostream>
#include <ctime>
#include <string>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/array.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/enable_shared_from_this.hpp>

using namespace std;
using namespace boost::asio;

using boost::asio::ip::tcp;


std::string make_daytime_string()
{
    using namespace std; // for time_t, time and ctime
    time_t now = time(0);
    return ctime(&now);
}


class tcp_connection
    : public boost::enable_shared_from_this<tcp_connection>
{
    
};


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

