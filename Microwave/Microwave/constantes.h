#ifndef CONSTANTES_H
#define CONSTANTES_H

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <Arduino.h>
#include <stdio.h>
#include <string.h>

#define CURR 13
#define OPEN 12
#define TIMER 11
#define OFF 10
#define ON 9
#define LED 8

const char DOIS_PONTOS = 58;
const char BOLINHA = 165;
const char FLORZINHA = 235;
const char BARRA = 124;
const char NOT_SQUARE = 254;

const byte LINHAS = 4; 
const byte COLUNAS = 4;

const char TECLAS_MATRIZ[LINHAS][COLUNAS] = { 
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

/* States */

enum states_t {  

  TURN_OFF, INIT, INIT_HELP, BLOCKED, FIX_CLOCK,
  CHOOSE_TIME, TIMER_E, FAN_MENU, FAN_ON, FAN_OFF,
  THIRTY_SECONDS, CHOOSE_TIME, POWER_MENU, CHOOSE_POWER,
  COOKING, STOPPED_COOKING, EASY_MENU, POPCORN_MENU,
  CONFIRM_POPCORN, CONFIRM_MUGCAKE, CONFIRM_OMELET,
  RICE_MENU, CONFIRM_RICE, CONFIRM_BRIGADEIRO, PIZZA_MENU,
  CONFIRM_PIZZA, BEANS_MENU, CONFIRM_BEANS, MEAT_MENU,
  CONFIRM_MEAT, CHICKEN_MENU, CONFIRM_CHICKEN,
  THAW_ON, THAW_OFF, LIST_MENU, LIST_MODE     

};

#define NO_PRESS 0
#define NO_PRESSED_FOR_THREE 1
#define PRESSED_FOR_THREE 2

const char BottonsMenu[3][15] = { 
  { ' ',' ',' ',' ','B','o','t','o','e','s',' ',' ',' ',' ','\0' },
  { 165,'S','e','l','e','c','t',' ',165,'D','o','o','r',' ','\0' },
  { 165,'O','f','f',' ',165,'O','n',' ',165,'T','i','m','e','\0' } 
};

const char KeysMenuOne[3][15] = {
  { ' ',' ',' ',' ','T','e','c','l','a','s',' ',' ',' ',' ','\0' },
  { ' ',' ',' ',' ','A',58,'M','e','n','u',' ',' ',' ',' ','\0' },
  { ' ','B',58,'T','i','r','a','r',' ','o','d','o','r',' ','\0' }
};

const char KeysMenuTwo[3][15] = {
  { ' ',' ','C',58,'P','o','t','e','n','c','i','a',' ',' ','\0' },
  { ' ',' ','*',58,'B','l','o','q','u','e','a','r',' ',' ','\0' },
  { ' ',' ',' ',' ','#',58,'M','u','t','e',' ',' ',' ',' ','\0' }
};

const byte PINOS_LINHAS[LINHAS] = {0, 8, 2, 3}; 
const byte PINOS_COLUNAS[COLUNAS] = {4, 5, 6, 7}; 

extern Keypad teclado_personalizado;

extern LiquidCrystal_I2C lcd;

extern int state;
extern int old_state;
extern int tecla;
extern int index_easy_menu;

extern bool rising_on;
extern bool rising_off;
extern bool rising_curr;
extern bool press_open;
extern bool press_timer;
extern bool down_timer;

extern bool time_over_blocked;

#endif