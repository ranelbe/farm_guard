#pragma once

#include "macros.h"

class SnakeDetector {
public:
    SnakeDetector(const std::string& modelPath);

    bool runSnakeDetector(const cv::Mat& inputImage);
    bool isSnakeDetected(const cv::Mat& frame);

private:
    cv::dnn::Net net;
};

