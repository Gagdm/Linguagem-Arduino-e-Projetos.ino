#ifndef INTERRUPTIONS_H
#define INTERRUPTIONS_H

#include "include/constants.h"

//=============================================================================================

class Interruptions {
 //-------------------------------------------------------------------------------------------
    private:
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    /* Variables that will show if some 
            button was pressed */
    volatile bool on_released;
    volatile bool on_pressed;
    volatile bool off_released;
    volatile bool off_pressed;
    volatile bool open_pressed;
    volatile bool timer_pressed;
    volatile bool timer_falling;
    volatile bool something_pressed;

    /* Treat the bounce of each button */
    volatile unsigned long bounceTime_ON;
    volatile unsigned long bounceTime_OFF;
    volatile unsigned long bounceTime_OPEN;
    volatile unsigned long bounceTime_TIMER;

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 //-------------------------------------------------------------------------------------------
    public:
 //------------------------------------------------------------------------------------------- 
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    /* Constructor */
    Interruptions();

    /* Initialize the interruptions in 
             'void setup()' */
    void init_interruptions();

    /* This function is called when the 'DOOR' is 
            pressed/opened or released */
    void door_signal();

    /* This function is called when the 'TIMER' is 
                pressed or released */
    void timer_signal();

    /* This function is called when the 'ON' is 
                pressed or released */
    void on_signal();

    /* This function is called when the 'OFF' is 
                pressed or released */
    void off_signal();

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    /*       functions responsible for allowing change or acess private variables 
                           requires outside the scope of this class                      */
   //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    void set_on_released(bool value);

    void set_off_released(bool value);

    void set_open_pressed(bool value);

    void set_timer_pressed(bool value);

    void set_timer_falling(bool value);

    void set_something_pressed(bool value);

    bool get_on_released();

    bool get_off_released();

    bool get_open_pressed();

    bool get_timer_pressed();

    bool get_timer_falling();

    bool get_something_pressed();

 //-------------------------------------------------------------------------------------------
}

//=============================================================================================

#endif