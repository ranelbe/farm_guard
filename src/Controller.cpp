#include "Controller.h"

void Controller::run()
{
    while (true) {
        cv::Mat frame = m_camera.captureFrame();
        cv::Mat processedImage;

        if (!frame.empty()) {

            // Process the captured frame, e.g., send for detection
            // You can also break the loop or add other logic here
            if (m_movementDetection.detectMovement(frame)) {
                cv::putText(frame, "Motion Detected", cv::Point(10, 20), 
                    cv::FONT_HERSHEY_SIMPLEX, 0.75, cv::Scalar(0, 0, 255), 2);
                processedImage = m_imageProcess.processImage(frame);

                cv::imshow("Processed Image", processedImage);

                // Add a delay or any other necessary logic here
            }
        }

        cv::imshow("Frame", frame);

        // Press ESC on keyboard to exit
        if ((cv::waitKey(WAIT_DELAY) % 256) == ESC_KEY)
            break;
    }
}