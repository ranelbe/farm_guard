#include <iostream>
#include <opencv2/opencv.hpp>
#include "SnakeDetector.h"

int main() {
    try {
        SnakeDetector detector("C:/Users/User/Desktop/raspberry pi/raspberry-team_4_farm_guard/Resources/fine_tuned_model/frozen_model.pb");

        // Read a single image
        cv::Mat frame = cv::imread("C:/Users/User/Desktop/raspberry pi/raspberry-team_4_farm_guard/Resources/sample_snake_image/123.jpg");

        detector.runSnakeDetector(frame);

        return 0;

    } catch (const cv::Exception& e) {
        std::cerr << "OpenCV Exception: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Standard Exception: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Unknown Exception occurred." << std::endl;
    }
    return -1;
}
