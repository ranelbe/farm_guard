#pragma once

#include "macros.h"
#include <opencv2/opencv.hpp>

class ImageProcess
{

public:
	cv::Mat processImage(const cv::Mat& frame) const;
};