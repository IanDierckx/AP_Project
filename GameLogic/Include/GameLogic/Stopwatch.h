#ifndef AP_PROJECT_STOPWATCH_H
#define AP_PROJECT_STOPWATCH_H

#include <ctime>

namespace GameLogic{
    //Stopwatch class to make sure the game runs at the same speed on every pc
    class Stopwatch {
        static Stopwatch *instance;
        clock_t start_clock;

        // Private constructor so that no objects can be created.
        Stopwatch() {
            start_clock = clock();
        }

    public:
        static Stopwatch *getInstance();

        clock_t getStart_clock() const;

        void reset();

        double getTimePassed();
    };
}



#endif //AP_PROJECT_STOPWATCH_H
