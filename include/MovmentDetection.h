#pragma once
#include <iostream>
#include <opencv2/opencv.hpp>

class MovementDetection
{
	void initializeCamera(int cameraIndex);
	void setCameraResolution(int width, int height);
	cv::VideoCapture _camera;
	
public:
	MovementDetection();
	~MovementDetection();
	
	void processFrames();

};