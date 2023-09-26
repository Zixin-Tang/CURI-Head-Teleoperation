#include <iostream>
#include "OVR_CAPI.h"

void head_position() {
    ovrResult result = ovr_Initialize(nullptr);
    if (OVR_FAILURE(result)) {
        std::cerr << "Failed to initialize the Oculus SDK\n";
        return -1;
    }

    ovrSession session;
    ovrGraphicsLuid luid;
    result = ovr_Create(&session, &luid);
    if (OVR_FAILURE(result)) {
        std::cerr << "Failed to create an Oculus session\n";
        ovr_Shutdown();
        return -1;
    }

    while (true) {
        ovrTrackingState trackingState = ovr_GetTrackingState(session, ovr_GetTimeInSeconds(), ovrTrue);
        ovrPoseStatef headPose = trackingState.HeadPose;

        std::cout << "Position: "
            << headPose.ThePose.Position.x << ", "
            << headPose.ThePose.Position.y << ", "
            << headPose.ThePose.Position.z << "\n";

        std::cout << "Orientation: "
            << headPose.ThePose.Orientation.w << ", "
            << headPose.ThePose.Orientation.x << ", "
            << headPose.ThePose.Orientation.y << ", "
            << headPose.ThePose.Orientation.z << "\n";

        std::cout << "Linear Velocity: "
            << headPose.LinearVelocity.x << ", "
            << headPose.LinearVelocity.y << ", "
            << headPose.LinearVelocity.z << "\n";

        // You might want to add a sleep here to avoid spamming the console
    }

    ovr_Destroy(session);
    ovr_Shutdown();

    return 0;
}
