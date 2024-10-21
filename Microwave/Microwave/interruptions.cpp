#include "interruptions.h"


void init_interruptions() {

    attachInterrupt(digitalPinToInterrupt(ON), on_up, RISING);
    attachInterrupt(digitalPinToInterrupt(OFF), off_up, RISING);
    attachInterrupt(digitalPinToInterrupt(CURR), curr_up, RISING);
    attachInterrupt(digitalPinToInterrupt(TIMER), timer_up, RISING);
    attachInterrupt(digitalPinToInterrupt(TIMER), timer_down, FALLING);
    attachInterrupt(digitalPinToInterrupt(TIMER), changed_timer, FALLING);
    attachInterrupt(digitalPinToInterrupt(OPEN), door_signal, CHANGE);

}

/* Se forem de LOW para HIGH, foram apertados */
void on_up() {
    rising_on = true;
}

void off_up() {
    rising_off = true;
}

void curr_up() {
    rising_curr = true;
}

/* Se for de HIGH para LOW -> true, LOW para HIGH -> false */
void timer_up() {
    press_timer = false;
}

void timer_down() {
    press_timer = true;
}

/* apertado = true, n apertado = false */
void door_signal() {
    press_open = !press_open;
}

void changed_timer() {
    down_timer = true;
}