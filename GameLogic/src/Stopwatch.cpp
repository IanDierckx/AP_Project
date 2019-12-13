#include "../Include/GameLogic/Stopwatch.h"

namespace GameLogic{
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

    double Stopwatch::getTimePassed() {
        return static_cast<double>(clock() - start_clock) /CLOCKS_PER_SEC;
    }
}


