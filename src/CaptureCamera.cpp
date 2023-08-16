#include "CaptureCamera.h"

CaptureCamera::CaptureCamera() {
    m_cap.open(0);
    if (!m_cap.isOpened()) {
        std::cout << "Camera not opened" << std::endl;
        exit(0);
    }
}

void CaptureCamera::takePic(char *filename) {

    Mat frame;
    m_cap >> frame;
    if (frame.empty()) {
        std::cout << "No frame captured" << std::endl;
        return;
    }
    // send the frame to detect a movement

    imshow("image captured: ", frame);

    m_cap.release();
    destroyAllWindows();
}