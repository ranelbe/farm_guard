#include <iostream>
#include <opencv2/opencv.hpp>

#include "SnakeDetector.h"

int main() {
    // Initialize the snake detector
    SnakeDetector detector("path_to_model.pb");

    // Read an image
    cv::Mat image = cv::imread("resources/sample_snake_image.jpg");

    if(image.empty()) {
        std::cerr << "Failed to load the image!" << std::endl;
        return -1;
    }

    // Detect snake in the image
    bool hasSnake = detector.detect(image);

    if(hasSnake) {
        std::cout << "Snake detected in the image!" << std::endl;
    } else {
        std::cout << "No snake detected in the image." << std::endl;
    }

    return 0;
}

