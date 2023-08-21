#include "Controller.h"

Controller::Controller() : _snakeDetector("/Users/yaakovhaimoff/Desktop/school/year_3/semester2/excellents/bootcamp/raspberryPi/Resources/fine_tuned_model/frozen_model.pb")
{}

void Controller::run()
{

    while (true) {
        cv::Mat frame = _camera.captureFrame();
        cv::Mat processedImage;

        if (!frame.empty()) {

            // Process the captured frame, e.g., send for detection
            // You can also break the loop or add other logic here
            if (_movementDetection.detectMovement(frame)) {
                cv::putText(frame, "Motion Detected", cv::Point(10, 20), 
                    cv::FONT_HERSHEY_SIMPLEX, 0.75, cv::Scalar(0, 0, 255), 2);
                if(_snakeDetector.runSnakeDetector(frame))
                    _activateAlarm.SendingSMSWithTwilio();
            }
        }

        cv::imshow("Frame", frame);

        // Press ESC on keyboard to exit
        if ((cv::waitKey(WAIT_DELAY) % 256) == ESC_KEY)
            break;
    }
}