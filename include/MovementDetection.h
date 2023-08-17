#pragma once
#include <iostream>
#include <opencv2/opencv.hpp>

class MovementDetection
{
	cv::Mat _prevFrame;
	bool _isFirstFrame = true;
public:
	bool processFrames(const cv::Mat& frame);

};