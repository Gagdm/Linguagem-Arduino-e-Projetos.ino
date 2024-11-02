#include "states_trustee.h"
#include "interface.h"

int Manager::turn_off() {

  if(rising_on == true) return INIT;
  else return TURN_OFF;
    
}

int Manager::init() {

    if(rising_off == true) return TURN_OFF;
    else if(rising_on == true) return THIRTY_SECONDS;
    else if(tecla == 'A') return EASY_MENU;
    else if(tecla == 'B') return FAN_MENU;
    else if(tecla == 'D') return INIT_HELP;
    else if((tecla >= '0') && (tecla <= '9')) return CHOOSE_TIME;
    else if(tecla == '*' || (time_over_blocked == true)) {
      block = true;
      return BLOCKED;
    }
    else if((three_seconds == NO_PRESSED_FOR_THREE)) {
        three_seconds = NO_PRESS;
        return CHOOSE_TIMER;
    }
    else if(three_seconds == PRESSED_FOR_THREE) {
        clock.set_start_fixing(true);
        three_seconds = NO_PRESS;
        return FIX_CLOCK;
    }
    else return INIT;
    

}

int Manager::init_help() {

    if(rising_off == true) return INIT;
    else if(rising_on == true) return THIRTY_SECONDS;
    else if(tecla == 'A') return EASY_MENU;
    else if(tecla == 'B') return FAN_MENU;
    else if((tecla >= '0') && (tecla <= '9')) return CHOOSE_TIME;
    else if(tecla == '*' || (time_over_blocked == true))  {
      block = true;
      return BLOCKED;
    }
    else if((three_seconds == NO_PRESSED_FOR_THREE)) {
        three_seconds = NO_PRESS;
        return CHOOSE_TIMER;
    }
    else if(three_seconds == PRESSED_FOR_THREE) {
        clock.set_start_fixing(true);
        three_seconds = NO_PRESS;
        return FIX_CLOCK;
    }
    else return INIT_HELP;

}

int Manager::blocked() {

    if((tecla == '*') || (press_open == true)) {
      time_over_blocked = false;
      block = false;
      return INIT;
    }
    else return BLOCKED;

}

int Manager::fix_clock() {

    if(rising_off == true) {
      clock.set_clockHour();
      return INIT;
    }
    else if(rising_on == true) return INIT;
    else return FIX_CLOCK;

}

int Manager::choose_timer() {

    if(rising_on == true) return TIMER;
    else if(rising_off == true) return INIT;
    else return CHOOSE_TIMER;

}

int Manager::timer() {

    if(rising_on == true || test == false) return INIT;
    else if(rising_off == true) return CHOOSE_TIMER;
    else return TIMER;

}

int Manager::fan_menu() {

    if(rising_on == true) {
      clock.set_timerMin_Seg(1, 30);
      clock.reset_millisTimer();
      return FAN_ON;
    }
    else if(rising_off == true) return INIT;
    else return FAN_MENU;

}

int Manager::fan_on() {

    if(clock.get_time_is_up() == true) return INIT;
    if((rising_off == true) || (press_open == true)) return FAN_OFF;
    else return FAN_ON;

}

int Manager::fan_off() {

    if((rising_on == true) && (press_open == false)) return FAN_ON;
    else if(rising_off == true) return INIT;
    else return FAN_OFF;

}

int Manager::thirty_seconds() {

    if(rising_on == true) return COOKING;
    else if(rising_off == true) return INIT;
    else if(tecla == 'C') return POWER_MENU;
    else return THIRTY_SECONDS;

}

int Manager::choose_time() {

    if(rising_on == true) return COOKING;
    else if(rising_off == true) return INIT;
    else if(tecla == 'C') return POWER_MENU;
    else return CHOOSE_TIME;

}

int Manager::power_menu() {

    if(rising_on == true) return CHOOSE_POWER;
    else if(rising_off == true) return CHOOSE_TIME;
    else return POWER_MENU;

}

int Manager::choose_power() {

    if(rising_off == true) return POWER_MENU;
    else if(tecla >= '0' && tecla <= '9') return CHOOSE_TIME;
    else return CHOOSE_POWER;

}

int Manager::cooking() {

    //if(test == false) return INIT;
    if((rising_off == true) && (press_open == true)) return STOPPED_COOKING;
    else return COOKING;

}

int Manager::stopped_cooking() {

    if(rising_off == true) return INIT;
    else if((rising_on == true) && (press_open == false)) return COOKING;
    else return STOPPED_COOKING;

}

int Manager::easy_menu() {

    if(rising_off == true) return INIT;
    else if((rising_on == true) && (index_easy_menu == 0)) return POPCORN_MENU;
    else if((rising_on == true) && (index_easy_menu == 1)) return CONFIRM_MUGCAKE;
    else if((rising_on == true) && (index_easy_menu == 2)) return CONFIRM_OMELET;
    else if((rising_on == true) && (index_easy_menu == 3)) return RICE_MENU;
    else if((rising_on == true) && (index_easy_menu == 4)) return CONFIRM_BRIGADEIRO;
    else if((rising_on == true) && (index_easy_menu == 5)) return PIZZA_MENU;
    else if((rising_on == true) && (index_easy_menu == 6)) return BEANS_MENU;
    else if((rising_on == true) && (index_easy_menu == 7)) return MEAT_MENU;
    else if((rising_on == true) && (index_easy_menu == 8)) return CHICKEN_MENU;
    else if((rising_on == true) && (index_easy_menu == 9)) return LIST_MENU;
    else return EASY_MENU;

}

int Manager::popcorn_menu() {

    if(rising_off == true) return EASY_MENU;
    else if(tecla == '1') {
      interface.set_chosen(1);
      return CONFIRM_POPCORN;
    }
    else if (tecla == '2') {
      interface.set_chosen(2);
      return CONFIRM_POPCORN;
    }
    else return POPCORN_MENU;

}

int Manager::confirm_popcorn() {

    if(rising_on == true) return COOKING;
    else if(rising_off == true) return POPCORN_MENU;
    else return CONFIRM_POPCORN;

}

int Manager::confirm_mugcake() {

    if(rising_on == true) return COOKING;
    else if(rising_off == true) return EASY_MENU;
    else return CONFIRM_MUGCAKE;

}

int Manager::confirm_omelet() {

    if(rising_on == true) return COOKING;
    else if(rising_off == true) return EASY_MENU;
    else return CONFIRM_OMELET;

}

int Manager::rice_menu() {

    if(rising_on == true) return CONFIRM_RICE;
    else if(rising_off == true) return EASY_MENU;
    else if(tecla == '1') {
      interface.set_chosen(1);
      return CONFIRM_RICE;
    }
    else if(tecla == '2') {
      interface.set_chosen(2);
      return CONFIRM_RICE;
    }
    else return RICE_MENU;

}

int Manager::confirm_rice() {

    if(rising_on == true) return COOKING;
    else if(rising_off == true) return RICE_MENU;
    else return CONFIRM_RICE;

}

int Manager::confirm_brigadeiro() {

    if(rising_on == true) return COOKING;
    else if(rising_off == true) return EASY_MENU;
    else return CONFIRM_BRIGADEIRO;

}

int Manager::pizza_menu() {

    if(rising_off == true) return EASY_MENU;
    else if(tecla == '1') {
      interface.set_chosen(1);
      return CONFIRM_PIZZA;
    }
    else if(tecla == '2') {
      interface.set_chosen(2);
      return CONFIRM_PIZZA;
    }
    else if(tecla == '3') {
      interface.set_chosen(3);
      return CONFIRM_PIZZA;
    }
    else return PIZZA_MENU;

}
 
int Manager::confirm_pizza() {

    if(rising_on == true) return COOKING;
    else if(rising_off == true) return PIZZA_MENU;
    else return CONFIRM_PIZZA;

}

int Manager::beans_menu() {

    if(rising_on == true) return CONFIRM_BEANS;   
    else if(rising_off == true) return EASY_MENU;
    else return BEANS_MENU;
    
}

int Manager::confirm_beans() {

    if(rising_on == true) return COOKING;
    else if(rising_off == true) return BEANS_MENU;
    else return CONFIRM_BEANS;

}

int Manager::meat_menu() {

    if(rising_on == true) return CONFIRM_MEAT;   
    else if(rising_off == true) return EASY_MENU;
    else return MEAT_MENU;
   
}

int Manager::confirm_meat() {

    if(rising_on == true) return THAW_ON;
    else if(rising_off == true) return MEAT_MENU;
    else return CONFIRM_MEAT;

}

int Manager::chicken_menu() {

    if(rising_on == true) return CONFIRM_CHICKEN;   
    else if(rising_off == true) return EASY_MENU;
    else return CHICKEN_MENU;

}

int Manager::confirm_chicken() {

    if(rising_on == true) return THAW_ON;
    else if(rising_off == true) return CHICKEN_MENU;
    else return CONFIRM_CHICKEN;

}

int Manager::thaw_on() {

    if( test == false ) return INIT;
    else if( test == false || (press_open == true) || (rising_off == true)) return THAW_OFF;
    else return THAW_OFF;

}

int Manager::thaw_off() {

    if(rising_off == false) return INIT;
    else if((press_open == false) && ((rising_on == true) || test == false)) return THAW_ON;
    else return THAW_OFF;

}

int Manager::list_menu() {

    if(rising_on == true) return LIST_MODE;
    else if(rising_off == true) return EASY_MENU;
    else return LIST_MENU;

}

int Manager::list_mode() {

    if(rising_off == true) return EASY_MENU;
    else return LIST_MODE;

}

void Manager::check_timer() {

    if((press_timer == true) && (down_timer == true) && (check_three == false)) {
        check_three = true;
        forThree = millis();
    }
    else if((press_timer == false) && ((millis() - forThree) >= 3000) && (down_timer ==  true)) {
        three_seconds = PRESSED_FOR_THREE;
        down_timer = false;
        check_three = false;
    }
    else if((press_timer == false) && ((millis() - forThree) < 3000) && (down_timer ==  true)) {
        three_seconds = NO_PRESSED_FOR_THREE;
        down_timer = false;
        check_three = false;
    }

}

Manager::Manager() {

    new_state = TURN_OFF;
    three_seconds = NO_PRESS;
    check_three = false;
    forThree = millis();

}

void Manager::state_manager() {

    check_timer();

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
        case TIMER_E: 
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

    rising_on = false;
    rising_off = false;

}