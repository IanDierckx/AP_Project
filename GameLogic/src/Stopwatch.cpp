#include "../Include/GameLogic/Stopwatch.h"


Stopwatch *Stopwatch::getInstance() {
    if (!instance)
        instance = new Stopwatch;
    return instance;
}

clock_t Stopwatch::getStart_clock() const {
    return start_clock;
}

void Stopwatch::reset() {
    this->start_clock = clock();
}

clock_t Stopwatch::getTimePassed() {
    return (clock() - start_clock) /CLOCKS_PER_SEC;
}

