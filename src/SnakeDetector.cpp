#include "SnakeDetector.h"

SnakeDetector::SnakeDetector(const std::string& modelPath) {
    net = cv::dnn::readNetFromTensorflow(modelPath);
    net.setPreferableBackend(cv::dnn::DNN_BACKEND_OPENCV);
    net.setPreferableTarget(cv::dnn::DNN_TARGET_CPU);
}

bool SnakeDetector::isSnakeDetected(const cv::Mat& frame) {
    cv::Mat blob = cv::dnn::blobFromImage(frame, 1.0, cv::Size(224, 224), cv::Scalar(127.5, 127.5, 127.5), true, false);
    net.setInput(blob);
    cv::Mat prob = net.forward();

    double confidence = prob.at<float>(0, 0);

    std::cout << "Confidence: " << confidence << std::endl;
    return confidence > 0.95;
}

bool SnakeDetector::runSnakeDetector(const cv::Mat& inputImage) {
    if (inputImage.empty()) {
        std::cerr << "Error: Provided image is empty!" << std::endl;
        return false;
    }
    return isSnakeDetected(inputImage);
}



