#include "CaptureCamera.h"
#include <iostream>

using namespace std;

int main ()
{
    //Input your desired filepath in place of the filepath denoted here
    char filename[] = "/home/yakovhaimoff/Documents/image1.jpg";
    CaptureCamera camera;
    camera.takePic(filename);
    cout<<"Image successful.."<<endl;

    return 0;
}