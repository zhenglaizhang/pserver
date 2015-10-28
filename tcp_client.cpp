//
// Created by darinzh on 10/27/2015.
//

#include <iostream>
#include <boost/asio.hpp>
#include <boost/thread.hpp>

using namespace std;
using namespace boost::asio;

using boost::asio::ip::tcp;

int main(int argc, char *argv[]) {
    try {
        if (argc != 2) {
            cerr << "Usage: client <host>" << endl;
            return 1;
        }

        boost::asio::io_service io;
        tcp::resolver resolver(io);
        tcp::resolver::query query(argv[1], "daytime"); // daytime service maps to port 13
        tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);
        tcp::socket socket(io);
        boost::asio::connect(socket, endpoint_iterator);

        while (true) {
            boost::array<char, 128> buf;
            boost::system::error_code error;
            size_t len = socket.read_some(boost::asio::buffer(buf), error);
            if (error == boost::asio::error::eof)
                break;      // end of stream, connection closed cleanly by peer
            else if (error)
                throw boost::system::system_error(error);
            cout.write(buf.data(), len);
        }

    } catch (std::exception& e) {
        cerr << e.what() << endl;
    }

}

