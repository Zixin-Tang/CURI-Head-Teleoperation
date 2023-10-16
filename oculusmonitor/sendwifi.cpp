#include "head.h"
#include <boost/asio.hpp>
#include <sstream>
#include <iostream>

void sendPanTiltOverWifi(float pan, float tilt) {
    try {
        boost::asio::io_service io_service;
        boost::asio::ip::tcp::socket socket(io_service);
        socket.connect(boost::asio::ip::tcp::endpoint(
            boost::asio::ip::address::from_string("192.168.10.37"), 8080));

        std::stringstream ss;
        ss << "panPosition:" << pan << "tiltPosition:" << tilt;

        boost::asio::write(socket, boost::asio::buffer(ss.str()));

    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}
