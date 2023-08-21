#include "Controller.h"

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
