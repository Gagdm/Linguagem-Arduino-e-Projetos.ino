#include "interruptions.h"

volatile unsigned long bounceTime_ON = 0;
volatile unsigned long bounceTime_OFF = 0;
volatile unsigned long bounceTime_OPEN = 0;
volatile unsigned long bounceTime_TIMER = 0;

void init_interruptions() {

  attachInterrupt(digitalPinToInterrupt(ON), on_up, RISING);
  attachInterrupt(digitalPinToInterrupt(OFF), off_up, RISING);
  attachInterrupt(digitalPinToInterrupt(TIMER), timer_signal, CHANGE);
  attachInterrupt(digitalPinToInterrupt(OPEN), door_signal, CHANGE);
    
}

/* Se forem de LOW para HIGH, foram apertados */
void on_up() {

  something_pressed = true;

  if(millis() > bounceTime_ON) {
    rising_on = true;
    bounceTime_ON = millis() + BOUNCE_DURATION;
  }

}

void off_up() {

  something_pressed = true;

  if(millis() > bounceTime_OFF) {
    rising_off = true;
    bounceTime_OFF = millis() + BOUNCE_DURATION;
  }

}

/* Se for de HIGH para LOW -> true, LOW para HIGH -> false */

/* apertado = true, n apertado = false */
void door_signal() {

  something_pressed = true;

  if(millis() > bounceTime_OPEN) {
    press_open = !press_open;
    bounceTime_OPEN = millis() + BOUNCE_DURATION;
  }

}

void timer_signal() {

  if(millis() > bounceTime_TIMER) {  
    if(press_timer == false) {
      down_timer = true;
      something_pressed = true;
    }
    press_timer = !press_timer;
    bounceTime_TIMER = millis() + BOUNCE_DURATION;
  }
  
}