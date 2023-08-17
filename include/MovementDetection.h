#pragma once

#include "macros.h"
#include <iostream>
#include <opencv2/opencv.hpp>

class MovementDetection
{
	cv::Mat m_prevFrame;
	bool m_isFirstFrame = true;

public:
	bool detectMovement(const cv::Mat& frame);

};