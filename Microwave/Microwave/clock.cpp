#include "clock.h"


Clock::Clock() {

    millisClock = millis();

    clockSeg = 0;
    clockMin = 0;
    clockHour = 12;

    millisTimer = millis();

    timerSeg = 0;
    timerMin = 0;

    timer_is_up = false;
    timer_on = false;

}

void Clock::microwave_clock() {

    if((millis() - millisClock) > 1000) {
        clockSeg++;
        millisClock = millis();
    }

    if(clockSeg == 60) {
        clockMin++;
        clockSeg = 0;
    }

    if(clockMin == 60) {
        clockHour++;
        clockMin = 0;
    }

    if(clockHour == 24) {
        clockHour = 0;
    }

}

void Clock::microwave_timer() {

    if(timerMin == 0 && timerSeg == 0) {
        timer_is_up = true;
    }
    
    if(timerSeg == -1 && timerMin > 0) {
        timerSeg = 59;
        timerMin--;
    }

    if((millis() - millisTimer) > 1000) {
        timerSeg--;
        millisTimer = millis();
    }

}