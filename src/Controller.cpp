#include "Controller.h"
#include "SnakeDetector.h"
#include <Windows.h>

void Controller::run()
{
    SnakeDetector detector("C:/Users/Ranel/Desktop/raspberry pi old/Resources/fine_tuned_model/frozen_model.pb");

    while (true) {
        cv::Mat frame = m_camera.captureFrame();
        //cv::Mat processedImage;

        if (!frame.empty()) {

            // Process the captured frame, e.g., send for detection
            // You can also break the loop or add other logic here
            if (m_movementDetection.detectMovement(frame)) {
                cv::putText(frame, "Motion Detected", cv::Point(10, 20), 
                    cv::FONT_HERSHEY_SIMPLEX, 0.75, cv::Scalar(0, 0, 255), 2);

                //Sleep(3000);
                //cv::Mat frame2 = cv::imread("C:/Users/Ranel/Desktop/raspberry pi old/Resources/sample_snake_image/face.png");
                
                detector.runSnakeDetector(frame);

                //cv::imshow("Captured", frame);

         
                // Add a delay or any other necessary logic here
            }
        }

        cv::imshow("Frame", frame);

        // Press ESC on keyboard to exit
        if ((cv::waitKey(WAIT_DELAY) % 256) == ESC_KEY)
            break;
    }
}