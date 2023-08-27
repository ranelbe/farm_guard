#include "ImageProcess.h"


/*This function receives a frame and prepares it to the model, by resizing it to the required height and width.*/
cv::Mat ImageProcess::processImage(const cv::Mat& frame) const
{
	cv::Mat resizedFrame;
    cv::resize(frame, resizedFrame, cv::Size(FRAME_SIZE, FRAME_SIZE));

    return resizedFrame;
}
