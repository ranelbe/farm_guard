#include "Controller.h"

void Controller::run()
{
    while (true) {
        Mat frame = m_camera.captureFrame();

        if (!frame.empty()) {
            // Process the captured frame, e.g., send for detection
            // You can also break the loop or add other logic here
        }

        // Add a delay or any other necessary logic here

        // Press ESC on keyboard to exit
        if ((waitKey(10) % 256) == 27)
            break;
    }
}