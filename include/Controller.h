#pragma once

#include "macros.h"
#include "CaptureCamera.h"
#include "MovementDetection.h"
#include "ImageProcess.h"
#include "ActivateAlarm.h"

class Controller {
    CaptureCamera _camera;
    MovementDetection _movementDetection;
    ImageProcess _imageProcess;
    ActivateAlarm _activateAlarm;

public:
    void run();

};

