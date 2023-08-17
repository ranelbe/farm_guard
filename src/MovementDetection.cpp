#include "MovementDetection.h"

/*
* process frames - read frames from camera and detect movement
*/
bool MovementDetection::detectMovement(const cv::Mat& frame)
{
    if (_isFirstFrame) {
		_prevFrame = frame.clone();
        cv::cvtColor(_prevFrame, _prevFrame, cv::COLOR_BGR2GRAY);
		_isFirstFrame = false;
        return false;
	}

    cv::Mat gray, frameDelta, thresh;
    std::vector<std::vector<cv::Point>> cnts;
    
    cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
    cv::absdiff(_prevFrame, gray, frameDelta);
    cv::threshold(frameDelta, thresh, 65, 255, cv::THRESH_BINARY);
    cv::dilate(thresh, thresh, cv::Mat(), cv::Point(-1, -1), 2);
    cv::findContours(thresh, cnts, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    _prevFrame = gray.clone(); // update previous frame

    for (size_t i = 0; i < cnts.size(); ++i) {
        if (cv::contourArea(cnts[i]) < 350) {
            continue;
        }
        return true;
    }

    return false;
}