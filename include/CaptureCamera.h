# pragma once

#include <csignal>
#include <iostream>
#include <unistd.h>
#include <string>
#include "opencv2/opencv.hpp"

using namespace cv;

class CaptureCamera {

    VideoCapture m_cap;

    public:
    CaptureCamera();
    void takePic(char* filename);
};

