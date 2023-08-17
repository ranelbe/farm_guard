#ifndef SNAKE_DETECTOR_H
#define SNAKE_DETECTOR_H

#include <opencv2/opencv.hpp>
#include <opencv2/dnn/dnn.hpp>
#include <iostream>

class SnakeDetector {
public:
    // Constructor to load the model
    SnakeDetector(const std::string& modelPath);

    // Detect if an image contains a snake
    bool detect(const cv::Mat& image);

private:
    cv::dnn::Net net;
    const float confidenceThreshold = 0.5f;
};

#endif //SNAKE_DETECTOR_H
