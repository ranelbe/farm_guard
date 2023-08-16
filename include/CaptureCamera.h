# pragma once

#include "macros.h"

class CaptureCamera {

    VideoCapture m_cap;

    public:
    CaptureCamera();
    void captureFrame();
};

