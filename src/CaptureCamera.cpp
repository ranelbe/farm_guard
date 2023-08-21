#include "CaptureCamera.h"

/*
 * Constructor for CaptureCamera
 * Open camera with cameraIndex
 * If camera is not opened, print error message
 * Set camera resolution
 */
CaptureCamera::CaptureCamera() {
    _cap.open(cameraIndex);
    if (!_cap.isOpened()) {
        std::cerr << "Error: Could not open camera" << std::endl;
    }
    //set camera resolution
    setCameraResolution(CAMERA_WIDTH, CAMERA_HEIGHT);
}

/*
* set camera resolution
* @param width - camera width
* @param height - camera height
*/
void CaptureCamera::setCameraResolution(int width, int height)
{
    _cap.set(cv::CAP_PROP_FRAME_WIDTH, width);
    _cap.set(cv::CAP_PROP_FRAME_HEIGHT, height);
}

/*
 * Capture frame from camera and return it
 * @return frame - captured frame
 * If frame is empty, print error message
 */
cv::Mat CaptureCamera::captureFrame() {
    cv::Mat frame;
    _cap >> frame;
    if (frame.empty()) {
        std::cerr << "Error: Could not capture frame" << std::endl;
        return frame;
    }
    return frame;
}

/*
 * Destructor for CaptureCamera
 * If camera is opened, release it
 * Destroys all windows
 */
CaptureCamera::~CaptureCamera()
{
    if (_cap.isOpened()) {
        _cap.release();
    }
    cv::destroyAllWindows();
}