#pragma once

#include <iostream>
#include <opencv2/opencv.hpp>

class SnakeDetector {
public:
    SnakeDetector(const std::string& modelPath);
    bool isSnakeDetected(const cv::Mat& frame);

private:
    cv::dnn::Net net;
};

