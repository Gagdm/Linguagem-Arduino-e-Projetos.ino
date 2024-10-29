#ifndef CLOCK_H
#define CLOCK_H

#include "constantes.h"

class Clock {
    private:

    unsigned long millisClock;

    int clockSeg;
    int clockMin;
    int clockHour;

    int Old_clockMin;
    int Old_clockHour;

    bool start_fixing;
    int input;

    unsigned long forBlink;


    unsigned long millisTimer;

    int timerSeg;
    int timerMin;

    bool timer_is_up;
    bool timer_on;

    

    public:

        
        Clock();

        void microwave_clock();

        void microwave_timer();

        void show_time();

        void fix_clock();

        void set_start_fixing(bool value);

        void set_clockHour();

        int get_input();

};

extern Clock clock;

#endif