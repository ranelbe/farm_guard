#pragma once

#include "CaptureCamera.h"
#include "MovementDetection.h"

class Controller {
    CaptureCamera m_camera;
    MovementDetection m_movementDetection;

public:
    void run();

};

