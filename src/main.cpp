#include <iostream>
#include <opencv2/opencv.hpp>
#include "SnakeDetector.h"

int main() {
    try {
        // Initialize the snake detector
        SnakeDetector detector("C:/Users/User/Desktop/raspberry pi/raspberry-team_4_farm_guard/Resources/fine_tuned_model/frozen_model.pb");

        // Read a single image
        cv::Mat frame = cv::imread("C:/Users/User/Desktop/raspberry pi/raspberry-team_4_farm_guard/Resources/sample_snake_image/trial.JPG");

        if (frame.empty()) {
            std::cerr << "Error loading image!" << std::endl;
            return -1;
        }

        if (detector.isSnakeDetected(frame)) {
            std::cout << "Snake detected in the image!" << std::endl;
        } else {
            std::cout << "No snake detected in the image." << std::endl;
        }

        // Display image for visualization
        cv::imshow("Image", frame);
        cv::waitKey(0);

        return 0;

    } catch (const cv::Exception& e) {
        std::cerr << "OpenCV Exception: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Standard Exception: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Unknown Exception occurred." << std::endl;
    }
    return -1; // Return an error code if an exception was caught
}
