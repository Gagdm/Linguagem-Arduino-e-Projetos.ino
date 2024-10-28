#ifndef CLOCK_H
#define CLOCK_H

#include "constantes.h"

class Clock {
    private:

    unsigned long millisClock;

    int clockSeg;
    int clockMin;
    int clockHour;

    unsigned long millisTimer;

    int timerSeg;
    int timerMin;

    bool timer_is_up;
    bool timer_on;
    

    public:

        Clock();

        void microwave_clock();

        void microwave_timer();
};

#endif