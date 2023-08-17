#include "Controller.h"

void Controller::run()
{
    while (true) {
        Mat frame = m_camera.captureFrame();

        if (!frame.empty()) {
            // Process the captured frame, e.g., send for detection
            // You can also break the loop or add other logic here
            if (m_movementDetection.processFrame(frame)) {
                cv::putText(frame, "Motion Detected", cv::Point(10, 20), 
                    cv::FONT_HERSHEY_SIMPLEX, 0.75, cv::Scalar(0, 0, 255), 2);
            }
        }

        cv::imshow("Frame", frame);

        // Add a delay or any other necessary logic here

        // Press ESC on keyboard to exit
        if ((waitKey(10) % 256) == 27)
            break;
    }
}