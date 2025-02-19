// [Standard:v1]
#include <iostream>
#include "src/v1/core/window/window.h"

int main(int argc, char* argv[]) {
    
    try {

        yashima::v1::Window::Properties props{
            .width = 800,
            .height = 600,
            .title = "Yashima Basic Window"
        };

        yashima::v1::Window window{props};

        while(!window.shouldClose()) {
            window.pollEvents();
        }

        return 0;
    } catch(const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return -1;
    }
}