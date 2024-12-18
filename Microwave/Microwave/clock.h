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

    bool ring;
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

        void set_timerMin_Seg(int Min, int Seg);

        bool get_ring();

        void set_ring(bool value);

        bool get_timer_is_up();

        void set_timer_is_up(bool value);

        bool get_timer_on();

        void set_timerSeg(int value);

        void set_timerMin(int value);

        int get_timerSeg();

        int get_timerMin();

        void set_timer_on(bool value);

        void reset_millisTimer();

        void show_timer();

};

extern Clock clock;

#endif