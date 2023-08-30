#include "SnakeDetector.h"

/*This function receives a string which resembles the path to the pre-trained model which can classify if snakes are
 * present in a frame or not.*/
SnakeDetector::SnakeDetector(const std::string& modelPath) {
    net = cv::dnn::readNetFromTensorflow(modelPath);
    net.setPreferableBackend(cv::dnn::DNN_BACKEND_OPENCV);
    net.setPreferableTarget(cv::dnn::DNN_TARGET_CPU);
}

/*This function receives the pre-processed frame, and implements on it more pre-processing so that the frame could be
 * suitable for the classifier. Then the function classifies the frame, using the net.forward function, and computes
 * the probability of snake presence in the frame. Then we compute the confidence of the model of how much it thinks
 * there is a snake in the frame or not. The function returns a boolean value, according to the threshold of
 * confidence, meaning if the confidence is above 95% then return true, false otherwise.*/
bool SnakeDetector::isSnakeDetected(const cv::Mat& frame) {
    cv::Mat blob = cv::dnn::blobFromImage(frame, 1.0, cv::Size(224, 224), cv::Scalar(127.5, 127.5, 127.5), true, false);
    net.setInput(blob);
    cv::Mat prob = net.forward();

    double confidence = prob.at<float>(0, 0);

//    std::cout << "Confidence: " << confidence << std::endl;
    return confidence > 0.95;
}

/*This function runs the snake detector system, and returns the result of the isSnakeDetected function.*/
bool SnakeDetector::runSnakeDetector(const cv::Mat& inputImage) {
    if (inputImage.empty()) {
        std::cerr << "Error: Provided image is empty!" << std::endl;
        return false;
    }
    return isSnakeDetected(inputImage);
}



