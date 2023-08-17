#include "SnakeDetector.h"
#include <opencv2/opencv.hpp>
#include <opencv2/dnn/dnn.hpp>
#include <iostream>

SnakeDetector::SnakeDetector(const std::string& modelPath) {
    net = cv::dnn::readNetFromTensorflow(modelPath);
}

bool SnakeDetector::detect(const cv::Mat& image) {
    cv::Mat blob = cv::dnn::blobFromImage(image, 1.0, cv::Size(224, 224), cv::Scalar(127.5, 127.5, 127.5), true, false);
    net.setInput(blob);
    cv::Mat detection = net.forward();

    // Assuming the output is a single float representing the confidence of the image being a snake
    float confidence = detection.at<float>(0);

    return confidence > confidenceThreshold;
}
