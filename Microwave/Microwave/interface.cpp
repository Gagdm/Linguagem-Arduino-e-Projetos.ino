#include "interface.h"


void Interface::turn_off() {

  if(old_state != TURN_OFF) {
    lcd.clear();
    lcd.noBacklight();
  }

}

void Interface::init() {

  clock.show_time();

  if(old_state == TURN_OFF) {
    lcd.backlight();
  }

  for(int i = 0; i < 4; i++) {
    lcd.setCursor(5,i);
    lcd.print(BARRA);
    lcd.print(lcd_tabs_4x15[0][i]);
  }

  if((millis() - forHelp) > 60) {
    forHelp = millis();

    char aux = lcd_tabs_4x15[0][1][0];
    for(int i = 0; i < 4; i++) {
      lcd_tabs_4x15[0][1][i] = lcd_tabs_4x15[0][1][i+1];
    }
    lcd_tabs_4x15[0][1][4] = aux;

    aux = lcd_tabs_4x15[0][1][13];
    for(int i = 12; i >= 9; i--) {
      lcd_tabs_4x15[0][1][i+1] = lcd_tabs_4x15[0][1][i];
    }
    lcd_tabs_4x15[0][1][9] = aux;

  }
  
} 

void Interface::init_help() {

  clock.show_time();

  if((millis() - forInit) > 12000) {
    forInit = millis();
  }
  
  if((millis() - forInit) < 3000) {
    for(int i = 0; i < 4; i++) {
      lcd.setCursor(5,i);
      lcd.print(BARRA);
      lcd.print(lcd_tabs_4x15[1][i]);
    }
  }
  else if(((millis() - forInit) >= 3000) && ((millis() - forInit) < 6000)) {
    for(int i = 0; i < 4; i++) {
      lcd.setCursor(5,i);
      lcd.print(BARRA);
      lcd.print(lcd_tabs_4x15[2][i]);
    }
  }
  else if(((millis() - forInit) >= 6000) && ((millis() - forInit) < 9000)) {
    for(int i = 0; i < 4; i++) {
      lcd.setCursor(5,i);
      lcd.print(BARRA);
      lcd.print(lcd_tabs_4x15[3][i]);
    }
  }
  else {
    for(int i = 0; i < 4; i++) {
      lcd.setCursor(5,i);
      lcd.print(BARRA);
      lcd.print(lcd_tabs_4x15[4][i]);
    }
  }

}

void Interface::blocked() {

  clock.show_time();

  for(int i = 0; i < 4; i++) {
    lcd.setCursor(5,i);
    lcd.print(BARRA);
    lcd.print(lcd_tabs_4x15[6][i]);
  }

}

void Interface::fix_clock() {

  clock.show_time();

  for(int i = 0; i < 4; i++) {
    lcd.setCursor(5,i);
    lcd.print(BARRA);

    if((millis() - forBlink) > 300) {
      forBlink = millis();
    }

    if(i == 3) {
      if(clock.get_input() >= 4 && (millis() - forBlink) >= 150) {
        lcd.print(lcd_tabs_4x15[5][2]);
      }
      else {
        lcd.print(lcd_tabs_4x15[5][i]);
      }
    }
    else {
        lcd.print(lcd_tabs_4x15[5][i]);
    }
    

  }

}

void Interface::choose_timer() {

  for(int i = 0; i < 4; i++) {
    
    lcd.print(lcd_tabs_4x20[0][i]);
  
  }
}

void Interface::timer() {

}

void Interface::fan_menu() {

  lcd.setCursor(0,0);

  for(int i = 0; i < 4; i++) {
    lcd.print(lcd_tabs_4x20[3][i]);
    lcd.setCursor(0, i+1);
  }

}

void Interface::fan_on() {

}

void Interface::fan_off() {

}

void Interface::thirty_seconds() {
  //lcd.clear();
  //lcd.noBacklight();
}

void Interface::choose_time() {

}

void Interface::power_menu() {

  for(int i = 0; i < 4; i++) {
    lcd.print(lcd_tabs_4x20[1][i]);
  }

}

void Interface::choose_power() {

  for(int i = 0; i < 4; i++) {
    lcd.print(lcd_tabs_4x20[2][i]);
  }

}

void Interface::cooking() {

}

void Interface::stopped_cooking() {

}

void Interface::easy_menu() {
  
  if(old_state == CONFIRM_MUGCAKE) index_easy_menu = 1;
  else if(old_state == CONFIRM_OMELET) index_easy_menu = 2;
  else if(old_state == RICE_MENU) index_easy_menu = 3;
  else if(old_state == CONFIRM_BRIGADEIRO) index_easy_menu = 4;
  else if(old_state == PIZZA_MENU) index_easy_menu = 5;
  else if(old_state == BEANS_MENU) index_easy_menu = 6;
  else if(old_state == MEAT_MENU) index_easy_menu = 7;
  else if(old_state == CHICKEN_MENU) index_easy_menu = 8;
  else if(old_state == LIST_MENU) index_easy_menu = 9;
  else index_easy_menu = 0;

  for(int i = 0; i < 4; i++) {
    if(i != 3) {
      lcd.print(lcd_tabs_4x20[(index_easy_menu + 4)][i]);
    }
    else {
      /* fazer piscar */
    }
  }

}

void Interface::popcorn_menu() {

}

void Interface::confirm_popcorn() {

}

void Interface::confirm_mugcake() {

}

void Interface::confirm_omelet() {

}

void Interface::rice_menu() {

}

void Interface::confirm_rice() {

}

void Interface::confirm_brigadeiro() {

}

void Interface::pizza_menu() {

}

void Interface::confirm_pizza() {

}

void Interface::beans_menu() {

}

void Interface::confirm_beans() {

}

void Interface::meat_menu() {

}

void Interface::confirm_meat() {

}

void Interface::chicken_menu() {

}

void Interface::confirm_chicken() {

}

void Interface::thaw_on() {

}

void Interface::thaw_off() {

}

void Interface::list_menu() {

}

void Interface::list_mode() {

}

Interface::Interface() {

    forInit = millis();
    forHelp = millis();
    forBlink = millis();

}

void Interface::interface_manager() {

  switch(state) {
    case TURN_OFF: 
      turn_off(); 
      break;
    case INIT: 
      init(); 
      break;
    case INIT_HELP: 
      init_help(); 
      break;
    case BLOCKED: 
      blocked(); 
      break;
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
    default:
      turn_off();
  }

}