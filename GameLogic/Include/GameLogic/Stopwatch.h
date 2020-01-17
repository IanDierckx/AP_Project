#ifndef AP_PROJECT_STOPWATCH_H
#define AP_PROJECT_STOPWATCH_H

#include <ctime>
#include <memory>

using namespace std;

namespace GameLogic{
    /** Stopwatch class to make sure the game runs at the same speed on every pc.
     * Stopwatch class to make sure the game runs at the same speed on every pc. Uses the singleton patterns.
     */
    class Stopwatch {
        static shared_ptr<Stopwatch> instance;
        clock_t start_clock;

        /** Private constructor so that no objects can be created.
         * Private constructor so that no objects can be created.
         */
        Stopwatch() {
            start_clock = clock();
        }

    public:

        /** Function to get the stopwatch instance.
         * Will return the stopwatch instance if one already exists, if not it will create one.
         * @return The stopwatch instance
         */
        static shared_ptr<Stopwatch> getInstance();

        /** Function returns when the clock was last started.
         * Function returns when the clock was last started.
         * @return the time when the clock was last started.
         */
        clock_t getStart_clock() const;

        /** Resets the clock.
         * Resets the clock.
         */
        void reset();

        /** Returns how much time has passed since the last time the clock was started.
         * Returns how much time has passed since the last time the clock was started.
         * @return how much time has passed
         */
        double getTimePassed();
    };
}



#endif //AP_PROJECT_STOPWATCH_H
