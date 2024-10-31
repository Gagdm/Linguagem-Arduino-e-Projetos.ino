#include "controller.h"

void Controller::Controller::block_microwave() {

  if((tecla) || something_pressed == true) {
    forBlocked = millis();
    something_pressed = false;
  }

  if((millis() - forBlocked) > 90000) {
    time_over_blocked = true;
  }

}

void Controller::fix_clock() {

  clock.fix_clock();
  
}

void Controller::choose_timer() {

}

void Controller::timer() {

}

void Controller::fan_menu() {

}

void Controller::fan_on() {

  clock.microwave_timer();

}

void Controller::fan_off() {

}

void Controller::thirty_seconds() {

}

void Controller::choose_time() {

}

void Controller::power_menu() {

}

void Controller::choose_power() {

}

void Controller::cooking() {

}

void Controller::stopped_cooking() {

}

void Controller::easy_menu() {

  if(tecla == 'D') {
    index_easy_menu = (index_easy_menu+1)%10;
  }

}

void Controller::beans_menu() {

}

void Controller::confirm_beans() {

}

void Controller::meat_menu() {

}

void Controller::confirm_meat() {

}

void Controller::chicken_menu() {

}

void Controller::confirm_chicken() {

}

void Controller::thaw_on() {

}

void Controller::thaw_off() {

}

void Controller::list_menu() {

}

void Controller::list_mode() {

  if(tecla == 'D') {
    index_list = (index_list+1)%10;
  }

}

Controller::Controller() {
  forBlocked = millis();
}

void Controller::task_manager() {

  switch(state) {

    /* 
    case TURN_OFF: 
      no action  
    */ 

    case INIT: 
      block_microwave();
      break;
    case INIT_HELP:
      block_microwave(); 
      break;
      
    /*
    case BLOCKED: 
      no action
    */
    
    case FIX_CLOCK: 
      fix_clock(); 
      break;
    case CHOOSE_TIMER: 
      choose_timer(); 
      break;
    case TIMER_E: 
      timer();
      break;

    /*
    case FAN_MENU: 
      no action
    */

    case FAN_ON: 
      fan_on(); 
      break;
    case FAN_OFF: 
      fan_off(); 
      break;

    case THIRTY_SECONDS: 
      thirty_seconds(); 
      break;
    case CHOOSE_TIME: 
      choose_time(); 
      break;

    case POWER_MENU: 
      power_menu(); 
      break;
    case CHOOSE_POWER: 
      choose_power(); 
      break;

    case COOKING: 
      cooking(); 
      break;
    case STOPPED_COOKING: 
      stopped_cooking(); 
      break;

    case EASY_MENU: 
      easy_menu(); 
      break;

    /*
    case POPCORN_MENU: 
      no action
    case CONFIRM_POPCORN: 
      no action
    case CONFIRM_MUGCAKE: 
      no action
    case CONFIRM_OMELET: 
      no action
    case RICE_MENU: 
      no action
    case CONFIRM_RICE: 
      no action
    case CONFIRM_BRIGADEIRO: 
      no action
    case PIZZA_MENU:
      no action
    case CONFIRM_PIZZA: 
      no action
    */

    case BEANS_MENU: 
      beans_menu();
      break;
    case CONFIRM_BEANS: 
      confirm_beans();
      break;
    case MEAT_MENU: 
      meat_menu();
      break;
    case CONFIRM_MEAT: 
      confirm_meat();
      break;
    case CHICKEN_MENU: 
      chicken_menu();
      break;
    case CONFIRM_CHICKEN: 
      confirm_chicken();
      break;
    case THAW_ON: 
      thaw_on(); 
      break;
    case THAW_OFF: 
      thaw_off(); 
      break;
    case LIST_MENU: 
      list_menu(); 
      break;
    case LIST_MODE: 
      list_mode(); 
      break;
      
  }
}