#include <iostream>
#include "timer.h"

int main()
{
    std::cout << "A manual test for timer..." << std::endl;
    Timer t = Timer();
    int counter{0};

    t.setTimeout([&]() {
        std::cout << "2.1 seconds have passed. The timer is now stopped" << std::endl;
        t.stop();
    }, 2100);

    t.setInterval([&]() {
        std::cout << "After 1 more second counter = " << ++counter << std::endl;
    }, 1000);


    while (t.is_active())
    {
    }
    std::cout << "... Test done" << std::endl;
}