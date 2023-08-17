#include "MovmentDetection.h"

/*
* process frames - read frames from camera and detect movement
*/
bool MovementDetection::processFrames(const cv::Mat& frame)
{
    if (_isFirstFrame) {
		_prevFrame = frame.clone();
		_isFirstFrame = false;
        return false;
	}

    cv::Mat gray, frameDelta, thresh;
    std::vector<std::vector<cv::Point>> cnts;
    
    cv::cvtColor(_prevFrame, _prevFrame, cv::COLOR_BGR2GRAY);
    cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
    cv::absdiff(_prevFrame, gray, frameDelta);
    cv::threshold(frameDelta, thresh, 60, 255, cv::THRESH_BINARY);
    cv::dilate(thresh, thresh, cv::Mat(), cv::Point(-1, -1), 2);
    cv::findContours(thresh, cnts, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    _prevFrame = gray.clone(); // update previous frame

    for (size_t i = 0; i < cnts.size(); ++i) {
        if (cv::contourArea(cnts[i]) < 350) {
            continue;
        }
        /*cv::putText(frame, "Motion Detected", cv::Point(10, 20),
            cv::FONT_HERSHEY_SIMPLEX, 0.75, cv::Scalar(0, 0, 255), 2);*/
        return true;
    }
    //cv::imshow("Camera", frame);

    return false;
}