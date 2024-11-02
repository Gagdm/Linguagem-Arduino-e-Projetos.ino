#include "interruptions.h"

//=============================================================================================
/* Initialize private variables */
Interruptions::Interruptions() {

  on_released = false;
  on_pressed = false;
  off_released = false;
  off_pressed = false;
  open_pressed = false;
  timer_pressed = false;
  timer_falling = false;
  something_pressed = false;
    
  bounceTime_ON = 0;
  bounceTime_OFF = 0;
  bounceTime_OPEN = 0;
  bounceTime_TIMER = 0;

}

//=============================================================================================
/* Called in 'void_setup()' to define the interruptions */
void Interruptions::init_interruptions() {

  attachInterrupt(digitalPinToInterrupt(ON), on_signal, CHANGE);
  attachInterrupt(digitalPinToInterrupt(OFF), off_signal, CHANGE);
  attachInterrupt(digitalPinToInterrupt(TIMER), timer_signal, CHANGE);
  attachInterrupt(digitalPinToInterrupt(OPEN), door_signal, CHANGE);

}

//=============================================================================================
void Interruptions::door_signal() {
  /* treats the bounce for avoid problems in the code logic */
  if(millis() > bounceTime_OPEN) {  

    /* If 'DOOR' go from HIGH to LOW, something_pressed 
                    will be set as true */
    if(open_pressed == false) {
      something_pressed = true;
    }

    /* Change the value of open_pressed each function call */
    open_pressed = !open_pressed;

    /* The actions of this scope will only be done again 
                after the bounce duration */
    bounceTime_OPEN = millis() + BOUNCE_DURATION;

  }

}

//=============================================================================================
void Interruptions::timer_signal() {
  /* treats the bounce for avoid problems in the code logic */
  if(millis() > bounceTime_TIMER) {  

    /* If 'TIMER' go from HIGH to LOW, timer_falling 
       and something_pressed will be set as true */
    if(timer_pressed == false) {
      timer_falling = true;
      something_pressed = true;
    }

    /* Change the value of timer_pressed each function call */
    timer_pressed = !timer_pressed;

    /* The actions of this scope will only be done again 
                after the bounce duration */
    bounceTime_TIMER = millis() + BOUNCE_DURATION;

  }

}

//=============================================================================================
void Interruptions::on_signal() {
  /* treats the bounce for avoid problems in the code logic */
  if(millis() > bounceTime_ON) {  

    /* If 'ON' go from LOW to HIGH, on_released will be set as true, 
      else means that 'ON' go from HIGH to LOW, so something_pressed 
                        will be set as true */
    if(on_pressed == true) {
      on_released = true;
    }
    else {
      something_pressed = true;
    }

    /* Change the value of on_pressed each function call */
    on_pressed = !on_pressed;

    /* The actions of this scope will only be done again 
                after the bounce duration */
    bounceTime_ON = millis() + BOUNCE_DURATION;

  }

}

//=============================================================================================
void Interruptions::off_signal() {
  /* treats the bounce for avoid problems in the code logic */
  if(millis() > bounceTime_OFF) {  

    /* If 'OFF' go from LOW to HIGH, off_released will be set as true, 
      else means that 'OFF' go from HIGH to LOW, so something_pressed 
                         will be set as true */
    if(off_pressed == true) {
      off_released = true;
    }
    else {
      something_pressed = true;
    }

    /* Change the value of on_pressed each function call */
    off_pressed = !off_pressed;

    /* The actions of this scope will only be done again 
                after the bounce duration */
    bounceTime_OFF = millis() + BOUNCE_DURATION;

  }

}

//=============================================================================================
 //-------------------------------------------------------------------------------------------
void Interruptions::set_on_released(bool value) { on_released = value; }

 //-------------------------------------------------------------------------------------------
void Interruptions::set_off_released(bool value) { off_released = value; }

 //-------------------------------------------------------------------------------------------
void Interruptions::set_open_pressed(bool value) { open_pressed = value; }

 //-------------------------------------------------------------------------------------------
void Interruptions::set_timer_pressed(bool value) { timer_pressed = value; }

 //-------------------------------------------------------------------------------------------
void Interruptions::set_timer_falling(bool value) { timer_falling = value; }

 //-------------------------------------------------------------------------------------------
void Interruptions::set_something_pressed(bool value) { something_pressed = value; }

 //-------------------------------------------------------------------------------------------
bool Interruptions::get_on_released() { return on_released; }

 //-------------------------------------------------------------------------------------------
bool Interruptions::get_off_released() { return off_released; }

 //-------------------------------------------------------------------------------------------
bool Interruptions::get_open_pressed() { return open_pressed; }

 //-------------------------------------------------------------------------------------------
bool Interruptions::get_timer_pressed() { return timer_pressed; }

 //-------------------------------------------------------------------------------------------
bool Interruptions::get_timer_falling() { return timer_falling; }

 //-------------------------------------------------------------------------------------------
bool Interruptions::get_something_pressed() { return something_pressed; }

 //-------------------------------------------------------------------------------------------
//=============================================================================================