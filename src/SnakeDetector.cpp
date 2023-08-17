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
    for(int i = 0; i < prob.rows; i++)
    {
        for(int j = 0; j < prob.cols; j++)
        {
            std::cout << "Output value at (" << i << ", " << j << "): " << prob.at<float>(i, j) << std::endl;
        }
    }

    double confidence = prob.at<float>(0, 0);
    return confidence > 0.8;  // Assuming 0.5 as threshold
}


