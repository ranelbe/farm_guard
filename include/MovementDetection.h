#pragma once

#include "macros.h"
#include <iostream>
#include <opencv2/opencv.hpp>

class MovementDetection
{
	cv::Mat _prevFrame;
	bool _isFirstFrame = true;

public:
	bool detectMovement(const cv::Mat& frame);

};