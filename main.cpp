#include <iostream>
#include "Stopwatch.h"

//Initialize pointer to zero so that it can be initialized in first call to getInstance
Stopwatch *Stopwatch::instance = 0;


int main() {
    //Initialise stopwatch
    Stopwatch *watch = Stopwatch::getInstance();

    int n = 0;
    while (n<=5) {
        if (watch->getTimePassed() == 2)  {
            std::cout << "#" << std::endl;
            n++;
            watch->reset();
        }
    }

    return 0;
}