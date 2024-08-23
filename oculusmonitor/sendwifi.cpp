#include <boost/asio.hpp>
#include "head.h"

#include <sstream>
#include <iostream>

#include <fstream>


// Function to send pan and tilt commands
bool sendPanTiltCommand(HANDLE hSerial, int panPosition, int tiltPosition) {
    if (hSerial == INVALID_HANDLE_VALUE) {
        std::cerr << "Invalid serial port handle." << std::endl;
        return false;
    }

    // 构造命令字符串，这里假设使用"PP"和"TP"作为控制指令的前缀
    std::string panCommand = "PP" + std::to_string(panPosition) + "\r\n";
    std::string tiltCommand = "TP" + std::to_string(tiltPosition) + "\r\n";

    // 在构造命令之前打印panPosition的值
    std::cout << "Pan: " << panPosition << " Tilt: " << tiltPosition << std::endl;

    // 发送平移命令
    DWORD bytesWritten;
    if (!WriteFile(hSerial, panCommand.c_str(), panCommand.size(), &bytesWritten, NULL)) {
        std::cerr << "Failed to send pan command." << std::endl;
        return false;
    }

    // 发送俯仰命令
    if (!WriteFile(hSerial, tiltCommand.c_str(), tiltCommand.size(), &bytesWritten, NULL)) {
        std::cerr << "Failed to send tilt command." << std::endl;
        return false;
    }

    return true;
}

