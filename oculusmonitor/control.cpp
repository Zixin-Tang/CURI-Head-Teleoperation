#include <iostream>

#include <fstream>
#include <sstream>
#include "OVR_CAPI.h"

#define M_PI 3.141592653589793

// Function to send pan and tilt commands
void sendPanTiltCommand(std::ofstream& serialPort, int panPosition, int tiltPosition) {
    // Create the command strings
    std::stringstream ss;
    ss << "PP" << panPosition << "\r\n";
    std::string panCommand = ss.str();

    ss.str("");
    ss.clear();
    ss << "TP" << tiltPosition << "\r\n";
    std::string tiltCommand = ss.str();




    // Send the pan and tilt commands to the serial port
    serialPort << panCommand;
    serialPort << tiltCommand;
}

int main() {
    // Initialize the Oculus SDK
    ovrResult result = ovr_Initialize(nullptr);
    if (OVR_FAILURE(result)) {
        std::cerr << "Failed to initialize the Oculus SDK\n";
        return -1;
    }

    // Create an Oculus session
    ovrSession session;
    ovrGraphicsLuid luid;
    result = ovr_Create(&session, &luid);
    if (OVR_FAILURE(result)) {
        std::cerr << "Failed to create an Oculus session\n";
        ovr_Shutdown();
        return -1;
    }

    // Open the serial port
    std::ofstream serialPort;
    serialPort.open("COM5");
    if (!serialPort.is_open()) {
        std::cerr << "Failed to open the serial port\n";
        ovr_Destroy(session);
        ovr_Shutdown();
        return -1;
    }

    while (true) {
        // Get the tracking state
        ovrTrackingState trackingState = ovr_GetTrackingState(session, ovr_GetTimeInSeconds(), ovrTrue);
        ovrPoseStatef headPose = trackingState.HeadPose;

        // Get the orientation quaternion
        float w = headPose.ThePose.Orientation.w;
        float x = headPose.ThePose.Orientation.x;
        float y = headPose.ThePose.Orientation.y;
        float z = headPose.ThePose.Orientation.z;

        // Convert the quaternion to pan and tilt positions
        float pan = atan2(2.0f * (y * z + w * x), w * w - x * x - y * y + z * z);
        float tilt = asin(-2.0f * (x * z - w * y));

        // Convert pan and tilt angles to positions
        int panPosition = static_cast<int>(pan / (0.013 * M_PI / 180.0));
        int tiltPosition = static_cast<int>(tilt / (0.013 * M_PI / 180.0));

        // Send the pan and tilt positions to the gimbal
        sendPanTiltCommand(serialPort, panPosition, tiltPosition);
    }

    // Destroy the Oculus session and shutdown the SDK
    ovr_Destroy(session);
    ovr_Shutdown();

    return 0;
}
