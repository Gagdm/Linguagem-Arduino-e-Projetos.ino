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

    if(i == 3) {
      if(clock.get_input() >= 4 && (millis() - forBlink) >= 350) {
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
    lcd.setCursor(0, i);
    if(i == 3) {
      if(controller.get_input() >= 4 && (millis() - forBlink) >= 600) {
        lcd.print(lcd_tabs_4x20[29][0]);
      }
      else {
        lcd.print(lcd_tabs_4x20[0][i]);        
      }
    }
    else if(i == 2) {
      if(controller.get_input() < 4 && (millis() - forBlink) >= 600) {
        lcd.print(lcd_tabs_4x20[29][0]);
      }
      else {
      
        if(clock.get_timerMin() < 10) {
          lcd_tabs_4x20[0][2][7] = '0';
          lcd_tabs_4x20[0][2][8] = clock.get_timerMin() + 48;
        }
        else {
          lcd_tabs_4x20[0][2][7] = (clock.get_timerMin()/10) + 48;
          lcd_tabs_4x20[0][2][8] = (clock.get_timerMin()%10) + 48;
        }

        lcd_tabs_4x20[0][2][9] = ':';

        if(clock.get_timerSeg() < 10) {
          lcd_tabs_4x20[0][2][10] = '0';
          lcd_tabs_4x20[0][2][11] = clock.get_timerSeg() + 48;
        }
        else {
          lcd_tabs_4x20[0][2][10] = (clock.get_timerSeg()/10) + 48;
          lcd_tabs_4x20[0][2][11] = (clock.get_timerSeg()%10) + 48;
        }
    

        lcd.print(lcd_tabs_4x20[0][i]);

      }
    }
    else {
      lcd.print(lcd_tabs_4x20[0][i]);
    }
  }

}

void Interface::timer() {
  
  effects();

  for(int i = 0; i < 4; i++) {

    lcd.setCursor(0, i);
    if(i == 0) {   
      if((millis() - forBlink) >= 600) {
        lcd.print(lcd_tabs_4x20[29][0]);
      }
      else {
        lcd.print(lcd_tabs_4x20[0][i]);
      }
    }
    else {
      lcd.print(lcd_tabs_4x20[28][i]);
    }

  }

}

void Interface::fan_menu() {

  for(int i = 0; i < 4; i++) {

    lcd.setCursor(0, i);
    if(i == 3 && ((millis() - forBlink) >= 600)) {   
      lcd.print(lcd_tabs_4x20[29][0]);
    }
    else {
      lcd.print(lcd_tabs_4x20[3][i]);
    }

  }

}

void Interface::fan_on() {

  effects();

  for(int i = 0; i < 4; i++) {

    lcd.setCursor(0, i);
    if(i == 0 && (millis() - forBlink) >= 600) {
      lcd.print(lcd_tabs_4x20[29][0]);
    }
    else {
      lcd.print(lcd_tabs_4x20[28][i]);
    }

  }

}

void Interface::fan_off() {

  if(press_open == true) {
    for(int i = 0; i < 4; i++) {
      lcd.setCursor(0, i);
      if(i == 0) {
        lcd.print(lcd_tabs_4x20[30][0]);
      }
      else {
        lcd.print(lcd_tabs_4x20[28][i]);
      }  
    }
  }
  else {
    for(int i = 0; i < 4; i++) {
      lcd.setCursor(0, i);
      if(i == 3) {
        lcd.print(lcd_tabs_4x20[0][3]);
      }
      else {
        lcd.print(lcd_tabs_4x20[28][i+1]);
      }
    }
  }
}

void Interface::thirty_seconds() {

  if(old_state == INIT || old_state == INIT_HELP) {
    for(int i = 0; i < 4; i++) {
      lcd.setCursor(0,i);
      lcd.print(lcd_tabs_4x20[29][i]);
    }
  }
  
  for(int i = 0; i < 4; i++) {
    if(i == 1) {
      lcd.setCursor(7,1);
      if(clock.get_timerMin() < 10) {
        lcd.print("0");
        lcd.print(clock.get_timerMin());
      }
      else {
        lcd.print((clock.get_timerMin()/10));
        lcd.print((clock.get_timerMin()%10));
      }

      lcd.print(DOIS_PONTOS);

      if(clock.get_timerSeg() < 10) {
        lcd.print("0");
        lcd.print(clock.get_timerSeg());
      }
      else {
        lcd.print((clock.get_timerSeg()/10));
        lcd.print((clock.get_timerSeg()%10));
      }
    }
    else if(i == 3 && (millis() - forBlink) <= 600) {
      lcd.setCursor(0,3);
      lcd.print(ARROW_LEFT);
      lcd.print("Off");
      
      if(power == 0) {
        lcd.setCursor(8,3);
        lcd.print(P);
        lcd.print(DOIS_PONTOS);
        lcd.print("LOW");
      }
      else if(power == 1) {
        lcd.setCursor(7,3);
        lcd.print(P);
        lcd.print(DOIS_PONTOS);
        lcd.print("MEDIUM");
      }
      else if(power == 2) {
        lcd.setCursor(7,3);
        lcd.print(P);
        lcd.print(DOIS_PONTOS);
        lcd.print("HIGH");
      }

      lcd.setCursor(17,3);
      lcd.print("On");
      lcd.print(ARROW_RIGHT);
    }
    else if(i == 3) {
      lcd.setCursor(0,3);
      lcd.print("    ");
      
      if(power == 0) {
        lcd.setCursor(8,3);
        lcd.print(P);
        lcd.print(DOIS_PONTOS);
        lcd.print("LOW");
      }
      else if(power == 1) {
        lcd.setCursor(7,3);
        lcd.print(P);
        lcd.print(DOIS_PONTOS);
        lcd.print("MEDIUM");
      }
      else if(power == 2) {
        lcd.setCursor(7,3);
        lcd.print(P);
        lcd.print(DOIS_PONTOS);
        lcd.print("HIGH");
      }

      lcd.setCursor(17,3);
      lcd.print("   ");
    }
  }

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
    lcd.setCursor(0,i);
    lcd.print(lcd_tabs_4x20[2][i]);
  }

}

void Interface::cooking() {

}

void Interface::stopped_cooking() {

}

void Interface::easy_menu() {
  
  if(old_state == INIT || old_state == INIT_HELP) index_easy_menu = 0;
  else if(old_state == CONFIRM_MUGCAKE) index_easy_menu = 1;
  else if(old_state == CONFIRM_OMELET) index_easy_menu = 2;
  else if(old_state == RICE_MENU) index_easy_menu = 3;
  else if(old_state == CONFIRM_BRIGADEIRO) index_easy_menu = 4;
  else if(old_state == PIZZA_MENU) index_easy_menu = 5;
  else if(old_state == BEANS_MENU) index_easy_menu = 6;
  else if(old_state == MEAT_MENU) index_easy_menu = 7;
  else if(old_state == CHICKEN_MENU) index_easy_menu = 8;
  else if(old_state == LIST_MENU || old_state == LIST_MODE) index_easy_menu = 9;

  

  for(int i = 0; i < 4; i++) {

    lcd.setCursor(0, i);
    if( ( i == 1 || i == 2) && (millis() - forBlink) >= 600) {
      lcd.print(lcd_tabs_4x20[29][0]);
    }
    else {
      lcd.print(lcd_tabs_4x20[(index_easy_menu + 4)][i]);
    }
    
  }

}

void Interface::popcorn_menu() {

  for(int i = 0; i < 4; i++) {

    lcd.setCursor(0, i);
    if( (i == 1 || i == 2) && (millis() - forBlink) >= 600) {
      lcd.print(lcd_tabs_4x20[29][0]);
    }
    else {
      lcd.print(lcd_tabs_4x20[14][i]);
    }

  }

}

void Interface::confirm_popcorn() {

  for(int i = 0; i < 4; i++) {

    lcd.setCursor(0, i);

    if(i == 0) {
      lcd.print(lcd_tabs_4x20[4][2]);
    }
    else if(i == 1) {
      lcd.print(lcd_tabs_4x20[14][chosen]);
    }
    else if(i == 3) {
      if((millis() - forBlink) < 600) {
        lcd.print(lcd_tabs_4x20[0][3]);
      } 
      else {
         lcd.print(lcd_tabs_4x20[29][0]);
      }
    }
    else {
      lcd.print(lcd_tabs_4x20[29][0]);      
    }

  }

}

void Interface::confirm_mugcake() {

  for(int i = 0; i < 4; i++) {

    lcd.setCursor(0, i);

    if(i == 1) {
      lcd.print(lcd_tabs_4x20[5][2]);
    }
    else if(i == 3) {
      if((millis() - forBlink) < 600) {
        lcd.print(lcd_tabs_4x20[0][3]);
      } 
      else {
        lcd.print(lcd_tabs_4x20[29][0]);
      }
    }
    else lcd.print(lcd_tabs_4x20[29][0]);
  }

}

void Interface::confirm_omelet() {

  for(int i = 0; i < 4; i++) {

    lcd.setCursor(0, i);
    
    if(i == 1) {
      lcd.print(lcd_tabs_4x20[6][2]);
    }
    else if(i == 3) {
      if((millis() - forBlink) < 600) {
        lcd.print(lcd_tabs_4x20[0][3]);
      } 
      else {
        lcd.print(lcd_tabs_4x20[29][0]);
      }
    }
    else lcd.print(lcd_tabs_4x20[29][0]);
  }

}

void Interface::rice_menu() {

  for(int i = 0; i < 4; i++) {

    lcd.setCursor(0, i);
    if( (i == 1 || i == 2) && (millis() - forBlink) >= 600) {
      lcd.print(lcd_tabs_4x20[29][0]);
    }
    else {
      lcd.print(lcd_tabs_4x20[15][i]);
    }

  }
}

void Interface::confirm_rice() {

  for(int i = 0; i < 4; i++) {

    lcd.setCursor(0, i);

    if(i == 0) {
      lcd.print(lcd_tabs_4x20[7][2]);
    }
    else if(i == 1) {
      lcd.print(lcd_tabs_4x20[15][chosen]);
    }
    else if(i == 3) {
      if((millis() - forBlink) < 600) {
        lcd.print(lcd_tabs_4x20[0][3]);
      } 
      else {
         lcd.print(lcd_tabs_4x20[29][0]);
      }
    }
    else {
      lcd.print(lcd_tabs_4x20[29][0]);      
    }
  }

}

void Interface::confirm_brigadeiro() {

  for(int i = 0; i < 4; i++) {

    lcd.setCursor(0, i);
    
    if(i == 1) {
      lcd.print(lcd_tabs_4x20[8][2]);
    }
    else if(i == 3) {
      if((millis() - forBlink) < 600) {
        lcd.print(lcd_tabs_4x20[0][3]);
      } 
      else {
        lcd.print(lcd_tabs_4x20[29][0]);
      }
    }
    else lcd.print(lcd_tabs_4x20[29][0]);
  }

}

void Interface::pizza_menu() {

  for(int i = 0; i < 4; i++) {

    lcd.setCursor(0, i);
    if( (i == 1 || i == 2 || i == 3) && (millis() - forBlink) >= 600) {
      lcd.print(lcd_tabs_4x20[29][0]);
    }
    else {
      lcd.print(lcd_tabs_4x20[16][i]);
    }

  }

}

void Interface::confirm_pizza() {

  for(int i = 0; i < 4; i++) {

    lcd.setCursor(0, i);

    if(i == 0) {
      lcd.print(lcd_tabs_4x20[9][2]);
    }
    else if(i == 1) {
      lcd.print(lcd_tabs_4x20[16][chosen]);
    }
    else if(i == 3) {
      if((millis() - forBlink) < 600) {
        lcd.print(lcd_tabs_4x20[0][3]);
      } 
      else {
         lcd.print(lcd_tabs_4x20[29][0]);
      }
    }
    else {
      lcd.print(lcd_tabs_4x20[29][0]);      
    }
  }

}

void Interface::beans_menu() {

  for(int i = 0; i < 4; i++) {
    lcd.setCursor(0, i);
    if(i == 0) {
      lcd.print(lcd_tabs_4x20[10][2]);
    }
    else if((i == 1 && (millis() - forBlink) <= 600) ||( i == 1 && controller.get_input() >= 4)) {
      if(gramas < 10) {
        lcd.print("        000");
        lcd.print(gramas);
        lcd.print("g");
        lcd.print("       ");
      }
      else if(gramas < 100) {
        lcd.print("        00");
        lcd.print(gramas);
        lcd.print("g");
        lcd.print("       ");
      }
      else if(gramas < 1000) {
        lcd.print("        0");
        lcd.print(gramas);
        lcd.print("g");
        lcd.print("       ");
      }
      else if(gramas >= 1000) {
        lcd.print("        ");
        lcd.print(gramas);
        lcd.print("g");
        lcd.print("       ");
      }
    }
    else if((i == 1 && (millis() - forBlink) > 600) || (i == 2)) {
      lcd.print(lcd_tabs_4x20[29][0]);
    }
    else if((i == 3) && controller.get_input() < 4 || ((i == 3) && controller.get_input() >= 4 && (millis() - forBlink) <= 600) ) {
      lcd.print(lcd_tabs_4x20[0][3]);
    }
    else if((i == 3) && (controller.get_input() >= 4) && ((millis() - forBlink) > 600)) {
      lcd.print(lcd_tabs_4x20[29][0]);
    }
  }
}

void Interface::confirm_beans() {

  for(int i = 0; i < 4; i++) {
    lcd.setCursor(0, i);

    if(i == 0) {
      lcd.print(lcd_tabs_4x20[30][1]);
    }
    else if(i == 1) {
      lcd.print(lcd_tabs_4x20[10][2])
    }
    else if(i == 2) {
       if(gramas < 10) {
        lcd.print("        000");
        lcd.print(gramas);
        lcd.print("g");
        lcd.print("       ");
      }
      else if(gramas < 100) {
        lcd.print("        00");
        lcd.print(gramas);
        lcd.print("g");
        lcd.print("       ");
      }
      else if(gramas < 1000) {
        lcd.print("        0");
        lcd.print(gramas);
        lcd.print("g");
        lcd.print("       ");
      }
      else if(gramas >= 1000) {
        lcd.print("        ");
        lcd.print(gramas);
        lcd.print("g");
        lcd.print("       ");
      }
    }
    else if(i == 3 && (millis() - forBlink) <= 600) {
      lcd.print(lcd_tabs_4x20[0][3]);
    }
    else if(i == 3) {
      lcd.print(lcd_tabs_4x20[29][0]);
    }
  }
}

void Interface::meat_menu() {
  for(int i = 0; i < 4; i++) {
    lcd.setCursor(0, i);
    if(i == 0) {
      lcd.print(lcd_tabs_4x20[11][2]);
    }
    else if((i == 1 && (millis() - forBlink) <= 600) ||( i == 1 && controller.get_input() >= 4)) {
      if(gramas < 10) {
        lcd.print("        000");
        lcd.print(gramas);
        lcd.print("g");
        lcd.print("       ");
      }
      else if(gramas < 100) {
        lcd.print("        00");
        lcd.print(gramas);
        lcd.print("g");
        lcd.print("       ");
      }
      else if(gramas < 1000) {
        lcd.print("        0");
        lcd.print(gramas);
        lcd.print("g");
        lcd.print("       ");
      }
      else if(gramas >= 1000) {
        lcd.print("        ");
        lcd.print(gramas);
        lcd.print("g");
        lcd.print("       ");
      }
    }
    else if((i == 1 && (millis() - forBlink) > 600) || (i == 2)) {
      lcd.print(lcd_tabs_4x20[29][0]);
    }
    else if((i == 3) && controller.get_input() < 4 || ((i == 3) && controller.get_input() >= 4 && (millis() - forBlink) <= 600) ) {
      lcd.print(lcd_tabs_4x20[0][3]);
    }
    else if((i == 3) && (controller.get_input() >= 4) && ((millis() - forBlink) > 600)) {
      lcd.print(lcd_tabs_4x20[29][0]);
    }
  }
}

void Interface::confirm_meat() {
  for(int i = 0; i < 4; i++) {
    lcd.setCursor(0, i);

    if(i == 0) {
      lcd.print(lcd_tabs_4x20[30][1]);
    }
    else if(i == 1) {
      lcd.print(lcd_tabs_4x20[11][2])
    }
    else if(i == 2) {
       if(gramas < 10) {
        lcd.print("        000");
        lcd.print(gramas);
        lcd.print("g");
        lcd.print("       ");
      }
      else if(gramas < 100) {
        lcd.print("        00");
        lcd.print(gramas);
        lcd.print("g");
        lcd.print("       ");
      }
      else if(gramas < 1000) {
        lcd.print("        0");
        lcd.print(gramas);
        lcd.print("g");
        lcd.print("       ");
      }
      else if(gramas >= 1000) {
        lcd.print("        ");
        lcd.print(gramas);
        lcd.print("g");
        lcd.print("       ");
      }
    }
    else if(i == 3 && (millis() - forBlink) <= 600) {
      lcd.print(lcd_tabs_4x20[0][3]);
    }
    else if(i == 3) {
      lcd.print(lcd_tabs_4x20[29][0]);
    }
  }
}

void Interface::chicken_menu() {
  for(int i = 0; i < 4; i++) {
    lcd.setCursor(0, i);
    if(i == 0) {
      lcd.print(lcd_tabs_4x20[12][2]);
    }
    else if((i == 1 && (millis() - forBlink) <= 600) ||( i == 1 && controller.get_input() >= 4)) {
      if(gramas < 10) {
        lcd.print("        000");
        lcd.print(gramas);
        lcd.print("g");
        lcd.print("       ");
      }
      else if(gramas < 100) {
        lcd.print("        00");
        lcd.print(gramas);
        lcd.print("g");
        lcd.print("       ");
      }
      else if(gramas < 1000) {
        lcd.print("        0");
        lcd.print(gramas);
        lcd.print("g");
        lcd.print("       ");
      }
      else if(gramas >= 1000) {
        lcd.print("        ");
        lcd.print(gramas);
        lcd.print("g");
        lcd.print("       ");
      }
    }
    else if((i == 1 && (millis() - forBlink) > 600) || (i == 2)) {
      lcd.print(lcd_tabs_4x20[29][0]);
    }
    else if((i == 3) && controller.get_input() < 4 || ((i == 3) && controller.get_input() >= 4 && (millis() - forBlink) <= 600) ) {
      lcd.print(lcd_tabs_4x20[0][3]);
    }
    else if((i == 3) && (controller.get_input() >= 4) && ((millis() - forBlink) > 600)) {
      lcd.print(lcd_tabs_4x20[29][0]);
    }
  }
}

void Interface::confirm_chicken() {
  for(int i = 0; i < 4; i++) {
    lcd.setCursor(0, i);

    if(i == 0) {
      lcd.print(lcd_tabs_4x20[30][1]);
    }
    else if(i == 1) {
      lcd.print(lcd_tabs_4x20[12][2]);
    }
    else if(i == 2) {
       if(gramas < 10) {
        lcd.print("        000");
        lcd.print(gramas);
        lcd.print("g");
        lcd.print("       ");
      }
      else if(gramas < 100) {
        lcd.print("        00");
        lcd.print(gramas);
        lcd.print("g");
        lcd.print("       ");
      }
      else if(gramas < 1000) {
        lcd.print("        0");
        lcd.print(gramas);
        lcd.print("g");
        lcd.print("       ");
      }
      else if(gramas >= 1000) {
        lcd.print("        ");
        lcd.print(gramas);
        lcd.print("g");
        lcd.print("       ");
      }
    }
    else if(i == 3 && (millis() - forBlink) <= 600) {
      lcd.print(lcd_tabs_4x20[0][3]);
    }
    else if(i == 3) {
      lcd.print(lcd_tabs_4x20[29][0]);
    }
  }
}

void Interface::thaw_on() {

}

void Interface::thaw_off() {

}

void Interface::list_menu() {

  for(int i = 0; i < 4; i++) {

    lcd.setCursor(0, i);
    if( ( i == 3) && (millis() - forBlink) >= 600) {
      lcd.print(lcd_tabs_4x20[29][0]);
    }
    else {
      lcd.print(lcd_tabs_4x20[17][i]);
    }

  }

}

void Interface::list_mode() {

  for(int i = 0; i < 4; i++) {

    lcd.setCursor(0, i);
    if(i == 3 && (millis() - forBlink) >= 600) {
      lcd.print(lcd_tabs_4x20[29][0]);
    } 
    else {
      lcd.print(lcd_tabs_4x20[index_list+18][i]);
    }
  }
}

void Interface::effects() {

  if((millis() - forEffects) > 45) {

    char aux = bolinhas[0];
    for(int i = 0; i < 21; i++) {
      bolinhas[i] = bolinhas[i+1];
    }
    bolinhas[21] = aux;
    
    forEffects = millis();
  }

  for(int i = 0; i < 22; i++) {

    switch(i) {

      case 0: lcd_tabs_4x20[28][3][14]  = bolinhas[0];
      case 1: lcd_tabs_4x20[28][3][13]  = bolinhas[1];
      case 2: lcd_tabs_4x20[28][3][12]  = bolinhas[2];
      case 3: lcd_tabs_4x20[28][3][11]  = bolinhas[3];
      case 4: lcd_tabs_4x20[28][3][10]  = bolinhas[4];
      case 5: lcd_tabs_4x20[28][3][9]   = bolinhas[5];
      case 6: lcd_tabs_4x20[28][3][8]   = bolinhas[6];
      case 7: lcd_tabs_4x20[28][3][7]   = bolinhas[7];
      case 8: lcd_tabs_4x20[28][3][6]   = bolinhas[8];
      case 9: lcd_tabs_4x20[28][3][5]   = bolinhas[9];
      case 10: lcd_tabs_4x20[28][2][5]  = bolinhas[10];
      case 11: lcd_tabs_4x20[28][1][5]  = bolinhas[11];
      case 12: lcd_tabs_4x20[28][1][6]  = bolinhas[12];
      case 13: lcd_tabs_4x20[28][1][7]  = bolinhas[13];
      case 14: lcd_tabs_4x20[28][1][8]  = bolinhas[14];
      case 15: lcd_tabs_4x20[28][1][9]  = bolinhas[15];
      case 16: lcd_tabs_4x20[28][1][10] = bolinhas[16];
      case 17: lcd_tabs_4x20[28][1][11] = bolinhas[17];
      case 18: lcd_tabs_4x20[28][1][12] = bolinhas[18];
      case 19: lcd_tabs_4x20[28][1][13] = bolinhas[19];
      case 20: lcd_tabs_4x20[28][1][14] = bolinhas[20];
      case 21: lcd_tabs_4x20[28][2][14] = bolinhas[21];

    }
  }
  
}

Interface::Interface() {

    forInit = millis();
    forHelp = millis();
    forBlink = millis();
    forEffects = millis();

    chosen = 0;

    for(int i = 0; i < 22; i++) {
      if(i < 12) {
        bolinhas[i] = BOLINHA;
      }
      else {
        bolinhas[i] = ' ';
      }
    }

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
    case TIMEr_E: 
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

  if((millis() - forBlink) > 800) {
    forBlink = millis();
  }

}

void Interface::set_chosen(int i) {

  chosen = i;

}