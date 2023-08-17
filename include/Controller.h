#pragma once

#include "macros.h"
#include "CaptureCamera.h"
#include "MovementDetection.h"
#include "ImageProcess.h"
#include "ActivateAlarm.h"

class Controller {
    CaptureCamera m_camera;
    MovementDetection m_movementDetection;
    ImageProcess m_imageProcess;
    ActivateAlarm m_activateAlarm;

public:
    void run();

};

