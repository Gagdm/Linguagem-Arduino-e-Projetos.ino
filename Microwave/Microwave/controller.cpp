#include "controller.h"

void Controller::Controller::block_microwave() {

  if((tecla) || something_pressed == true) {
    forBlocked = millis();
    something_pressed = false;
  }

  if((millis() - forBlocked) > 60000) {
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

}

void Controller::popcorn_menu() {

}

void Controller::confirm_popcorn() {

}

void Controller::confirm_mugcake() {

}

void Controller::confirm_omelet() {

}

void Controller::rice_menu() {

}

void Controller::confirm_rice() {

}

void Controller::confirm_brigadeiro() {

}

void Controller::pizza_menu() {

}

void Controller::confirm_pizza() {

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
    case FAN_MENU: 
      fan_menu(); 
      break;
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
    case POPCORN_MENU: 
      popcorn_menu(); 
      break;
    case CONFIRM_POPCORN: 
      confirm_popcorn(); 
      break;
    case CONFIRM_MUGCAKE: 
      confirm_mugcake(); 
      break;
    case CONFIRM_OMELET: 
      confirm_omelet(); 
      break;
    case RICE_MENU: 
      rice_menu();
      break;
    case CONFIRM_RICE: 
      confirm_rice(); 
      break;
    case CONFIRM_BRIGADEIRO: 
      confirm_brigadeiro(); 
      break;
    case PIZZA_MENU:
      pizza_menu(); 
      break;
    case CONFIRM_PIZZA: 
      confirm_pizza(); 
      break;
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