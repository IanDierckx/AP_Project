#include "../Include/GameLogic/Stopwatch.h"

namespace GameLogic{

    /** Function to get the stopwatch instance.
     * Will return the stopwatch instance if one already exists, if not it will create one.
     * @return The stopwatch instance
     */
    shared_ptr<Stopwatch> Stopwatch::getInstance() {
        if (!instance)
            instance = shared_ptr<Stopwatch>(new Stopwatch);
        return instance;
    }

    /** Function returns when the clock was last started.
     * Function returns when the clock was last started.
     * @return the time when the clock was last started.
     */
    clock_t Stopwatch::getStart_clock() const {
        return start_clock;
    }

    /** Resets the clock.
     * Resets the clock.
     */
    void Stopwatch::reset() {
        this->start_clock = clock();
    }

    /** Returns how much time has passed since the last time the clock was started.
     * Returns how much time has passed since the last time the clock was started.
     * @return how much time has passed
     */
    double Stopwatch::getTimePassed() {
        return static_cast<double>(clock() - start_clock) /CLOCKS_PER_SEC;
    }
}


