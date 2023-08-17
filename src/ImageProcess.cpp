#include "ImageProcess.h"

cv::Mat ImageProcess::processImage(const cv::Mat& frame) const
{
	cv::Mat resizedFrame;
    cv::resize(frame, resizedFrame, cv::Size(FRAME_SIZE, FRAME_SIZE));

    // add more image processing here as needed

    return resizedFrame;
}
