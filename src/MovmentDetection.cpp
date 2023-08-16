#include "MovmentDetection.h"

/*
* ctor - initialize camera
*/
MovementDetection::MovementDetection()
{
    initializeCamera(0);
}

/*
* dtor - release camera
*/
MovementDetection::~MovementDetection()
{
    if (_camera.isOpened()) {
        _camera.release();
    }
    cv::destroyAllWindows();
}

/*
* initialize camera - open camera and set resolution
* @param cameraIndex - camera index
*/
void MovementDetection::initializeCamera(int cameraIndex)
{
    _camera.open(cameraIndex);
    if (!_camera.isOpened()) {
        std::cerr << "Error: Could not open camera" << std::endl;
    }
    //set camera resolution
    setCameraResolution(512, 288);
}

/*
* set camera resolution
* @param width - camera width
* @param height - camera height
*/
void MovementDetection::setCameraResolution(int width, int height)
{
    _camera.set(cv::CAP_PROP_FRAME_WIDTH, width);
    _camera.set(cv::CAP_PROP_FRAME_HEIGHT, height);
}

/*
* process frames - read frames from camera and detect movement
*/
void MovementDetection::processFrames()
{
    
    cv::Mat frame, gray, frameDelta, thresh, prevFrame;
    std::vector<std::vector<cv::Point>> cnts;

    _camera.read(prevFrame);
    cv::cvtColor(prevFrame, prevFrame, cv::COLOR_BGR2GRAY);

    while (_camera.read(frame)) {
        cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
        cv::absdiff(prevFrame, gray, frameDelta);
        cv::threshold(frameDelta, thresh, 65, 255, cv::THRESH_BINARY);
        cv::dilate(thresh, thresh, cv::Mat(), cv::Point(-1, -1), 2);
        cv::findContours(thresh, cnts, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

        for (size_t i = 0; i < cnts.size(); ++i) {
            if (cv::contourArea(cnts[i]) < 250) {
                continue;
            }
            cv::putText(frame, "Motion Detected", cv::Point(10, 20), 
                cv::FONT_HERSHEY_SIMPLEX, 0.75, cv::Scalar(0, 0, 255), 2);
        }
        cv::imshow("Camera", frame);
        
        if (cv::waitKey(1) == 27) {
            break;
        }

        prevFrame = gray.clone(); // update previous frame
    }
}