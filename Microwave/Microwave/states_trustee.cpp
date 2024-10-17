#include "states_trustee.h"

int Manager::turn_off() {

  if(rising_on == true) {

    rising_on = false;
    return INIT;

  }
  else {

    rising_off = false;
    rising_curr = false;
    press_timer = false;
    return TURN_OFF;
    
  }
  
}

int Manager::init() {

}

int Manager::init_help() {

}

int Manager::blocked() {

}

int Manager::fix_clock() {

}

int Manager::choose_timer() {

}

int Manager::timer();

int Manager::fan_menu();

int Manager::fan_on();

int Manager::fan_off();

int Manager::thirty_seconds();

int Manager::choose_time();

int Manager::power_menu();

int Manager::choose_power();

int Manager::cooking(); 

int Manager::stopped_cooking();

int Manager::easy_menu();

int Manager::popcorn_menu();

int Manager::confirm_popcorn();

int Manager::confirm_mugcake();

int Manager::confirm_omelet();

int Manager::rice_menu();

int Manager::confirm_rice();

int Manager::confirm_brigadeiro();

int Manager::pizza_menu();
 
int Manager::confirm_pizza();

int Manager::beans_menu();

int Manager::confirm_beans();

int Manager::meat_menu();

int Manager::confirm_meat();

int Manager::chicken_menu();

int Manager::confirm_chicken();

int Manager::thaw_on();

int Manager::thaw_off();

int Manager::list_menu();

int Manager::list_mode();

Manager::Manager() {
    new_state = TURN_OFF;
}

void Manager::state_maneger() {

    switch(state) {
        case TURN_OFF: 
            new_state = turn_off(); 
            break;
        case INIT: 
            new_state = init(); 
            break;
        case INIT_HELP: 
            new_state = init_help(); 
            break;
        case BLOCKED: 
            new_state = blocked(); 
            break;
        case FIX_CLOCK: 
            new_state = fix_clock(); 
            break;
        case CHOOSE_TIMER: 
            new_state = choose_timer(); 
            break;
        case TIMER: 
            new_state = timer();
            break;
        case FAN_MENU: 
            new_state = fan_menu(); 
            break;
        case FAN_ON: 
            new_state = fan_on(); 
            break;
        case FAN_OFF: 
            new_state = fan_off(); 
            break;
        case THIRTY_SECONDS: 
            new_state = thirty_seconds(); 
            break;
        case CHOOSE_TIME: 
            new_state = choose_time(); 
            break;
        case POWER_MENU: 
            new_state = power_menu(); 
            break;
        case CHOOSE_POWER: 
            new_state = choose_power(); 
            break;
        case COOKING: 
            new_state = cooking(); 
            break;
        case STOPPED_COOKING: 
            new_state = stopped_cooking(); 
            break;
        case EASY_MENU: 
            new_state = easy_menu(); 
            break;
        case POPCORN_MENU: 
            new_state = popcorn_menu(); 
            break;
        case CONFIRM_POPCORN: 
            new_state = confirm_popcorn(); 
            break;
        case CONFIRM_MUGCAKE: 
            new_state = confirm_mugcake(); 
            break;
        case CONFIRM_OMELET: 
            new_state = confirm_omelet(); 
            break;
        case RICE_MENU: 
            new_state = rice_menu();
            break;
        case CONFIRM_RICE: 
            new_state = confirm_rice(); 
            break;
        case CONFIRM_BRIGADEIRO: 
            new_state = confirm_brigadeiro(); 
            break;
        case PIZZA_MENU:
            new_state = pizza_menu(); 
            break;
        case CONFIRM_PIZZA: 
            new_state = confirm_pizza(); 
            break;
        case BEANS_MENU: 
            new_state = beans_menu();
            break;
        case CONFIRM_BEANS: 
            new_state = confirm_beans(); 
            break;
        case MEAT_MENU: 
            new_state = meat_menu(); 
            break;
        case CONFIRM_MEAT: 
            new_state = confirm_meat(); 
            break;
        case CHICKEN_MENU: 
            new_state = chicken_menu(); 
            break;
        case CONFIRM_CHICKEN: 
            new_state = confirm_chicken(); 
            break;
        case THAW_ON: 
            new_state = thaw_on(); 
            break;
        case THAW_OFF: 
            new_state = thaw_off(); 
            break;
        case LIST_MENU: 
            new_state = list_menu(); 
            break;
        case LIST_MODE: 
            new_state = list_mode(); 
            break;
        default:
            new_state = TURN_OFF;
    }

    old_state = state;
    state = new_state;

}