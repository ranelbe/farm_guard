# pragma once

#include "macros.h"

class CaptureCamera {

    cv::VideoCapture _cap{};
    void setCameraResolution(int width, int height);

    public:
        CaptureCamera();
        ~CaptureCamera();
        cv::Mat captureFrame();
};

