#include "../include/MCP3008.h"
#include <thread>
#include <iostream>
#include <chrono>

int main() {

    using namespace MCP3008Lib;

    MCP3008 adc;
    adc.connect();

    while(true) {

        for(int i = 0; i < 8; ++i) {
            std::cout << "CH" << i << ": " << adc.read(i) << std::endl;
        }

        std::cout << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));

    }

    return 0;

}