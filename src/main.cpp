#include "Controller.h"

/*The main function runs the controller and handles all exceptions, either it is an open CV exception, a standard one
 * or an unknown exception.*/
int main() {

    try {

        Controller controller;
        controller.run();

        return 0;

    } catch (const cv::Exception& e) {
        std::cerr << "OpenCV Exception: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Standard Exception: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Unknown Exception occurred." << std::endl;
    }
    return -1;
}
