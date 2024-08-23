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

    // ���������ַ������������ʹ��"PP"��"TP"��Ϊ����ָ���ǰ׺
    std::string panCommand = "PP" + std::to_string(panPosition) + "\r\n";
    std::string tiltCommand = "TP" + std::to_string(tiltPosition) + "\r\n";

    // �ڹ�������֮ǰ��ӡpanPosition��ֵ
    std::cout << "Pan: " << panPosition << " Tilt: " << tiltPosition << std::endl;

    // ����ƽ������
    DWORD bytesWritten;
    if (!WriteFile(hSerial, panCommand.c_str(), panCommand.size(), &bytesWritten, NULL)) {
        std::cerr << "Failed to send pan command." << std::endl;
        return false;
    }

    // ���͸�������
    if (!WriteFile(hSerial, tiltCommand.c_str(), tiltCommand.size(), &bytesWritten, NULL)) {
        std::cerr << "Failed to send tilt command." << std::endl;
        return false;
    }

    return true;
}

