#include "controller.h"

void Controller::leds() {

  if((millis() - forLedPower) > 1600) {
    forLedPower = millis();
  }

  if((millis() - forLedPower) <= 200) {
    analogWrite(POWER_1, 255);
    analogWrite(POWER_2, LOW);
    analogWrite(POWER_3, LOW);
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_DOOR, LOW);
  }
  else if((millis() - forLedPower) <= 400) {
    analogWrite(POWER_1, LOW);
    analogWrite(POWER_2, 80);
    analogWrite(POWER_3, LOW);
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_DOOR, LOW);
  }
  else if((millis() - forLedPower) <= 600) {
    analogWrite(POWER_1, LOW);
    analogWrite(POWER_2, LOW);
    analogWrite(POWER_3, 10);
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_DOOR, LOW);
  }
  else if((millis() - forLedPower) <= 800) {
    analogWrite(POWER_1, LOW);
    analogWrite(POWER_2, LOW);
    analogWrite(POWER_3, LOW);
    digitalWrite(LED_RED, HIGH);
    digitalWrite(LED_DOOR, LOW);
  }
  else if((millis() - forLedPower) <= 1000) {
    analogWrite(POWER_1, LOW);
    analogWrite(POWER_2, LOW);
    analogWrite(POWER_3, LOW);
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_DOOR, HIGH);
  }
  else if((millis() - forLedPower) <= 1200) {
    analogWrite(POWER_1, LOW);
    analogWrite(POWER_2, LOW);
    analogWrite(POWER_3, LOW);
    digitalWrite(LED_RED, HIGH);
    digitalWrite(LED_DOOR, LOW);
  }
  else if((millis() - forLedPower) <= 1400) {
    analogWrite(POWER_1, LOW);
    analogWrite(POWER_2, LOW);
    analogWrite(POWER_3, 10);
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_DOOR, LOW);
  }
  else if((millis() - forLedPower) <= 1600) {
    analogWrite(POWER_1, LOW);
    analogWrite(POWER_2, 80);
    analogWrite(POWER_3, LOW);
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_DOOR, LOW);
  }

}

void Controller::block_microwave() {

  if(old_state == TURN_OFF || old_state == BLOCKED) {
    analogWrite(POWER_1, LOW);
    analogWrite(POWER_2, LOW);
    analogWrite(POWER_3, LOW);
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_DOOR, LOW);
  }

  if((tecla) || something_pressed == true) {
    forBlocked = millis();
  }

  if((millis() - forBlocked) > 90000) {
    time_over_blocked = true;
  }

}

void Controller::fix_clock() {

  clock.fix_clock();
  
}

void Controller::choose_timer() {

  if(input == 0) {
    clock.set_timerSeg(0);
    clock.set_timerMin(0);    
  }

  if(tecla >= '0' && tecla <= '9') {
    input++;

    switch(input) {
      case 1:
        clock.set_timerMin(tecla-48);
        break;

      case 2:
        clock.set_timerMin(((clock.get_timerMin()*10)+(tecla-48))%60);
        break;

      case 3: 
        clock.set_timerSeg(tecla-48);
        break;

      case 4: 
        clock.set_timerSeg(((clock.get_timerSeg()*10)+(tecla-48))%60);
        break;
    }
  }

}

void Controller::timer() {

  clock.microwave_timer();

}

void Controller::fan_on() {

  clock.microwave_timer();

}

void Controller::thirty_seconds() {

  if(rising_on == true) {
    clock.set_timerSeg(clock.get_timerSeg() + 30);
  }

  if(clock.get_timerSeg() == 60) {
    clock.set_timerSeg(0);
    clock.set_timerMin(clock.get_timerMin() + 1);
  }

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
  if(input == 0) {
    gramas = 0;
  }

  switch(input) {
    case 0:
      gramas = (gramas + teclas) - 48;
      break;
    case 1:
      gramas = (gramas*10) + (teclas - 48);
      break;
    case 2:
      break;
    case 3:
      break;
  }
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
  forLedPower = millis();
  forBuzzer = millis();

}

void Controller::task_manager() {

  switch(state) {

    
    case TURN_OFF: 
      leds();
      break;
    case INIT: 
      block_microwave();
      break;
    case INIT_HELP:
      block_microwave(); 
      break;
    case BLOCKED: 
      leds();
      break;
    case FIX_CLOCK: 
      fix_clock(); 
      break;
    case CHOOSE_TIMER: 
      choose_timer(); 
      break;
    case TIMEr_E: 
      timer();
      break;

    /*
    case FAN_MENU: 
      no action
    */

    case FAN_ON: 
      fan_on(); 
      break;

    /*
    case FAN_OFF: 
      no action
    */

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

 void Controller::buzzer() {
  if(!mute) {
    if((tecla) || something_pressed == true) {    
      something_pressed = false;
      forBuzzer = millis();
    }

    if((millis() - forBuzzer) < 120) {
      tone(BUZZER, 3140);
    } 
    else {
      noTone(BUZZER);
    }
  }
}

void Controller::set_input(int value) {

  input = value;

}

 int Controller::get_input() {
   return input;
 }