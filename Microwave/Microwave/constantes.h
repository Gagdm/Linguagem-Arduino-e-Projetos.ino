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
#define TURN_OFF 0
#define INIT 1
#define INIT_HELP 2
#define BLOCKED 3
#define FIX_CLOCK 4
#define CHOOSE_TIMER 5
#define TIMER 6
#define FAN_MENU 7
#define FAN_ON 8
#define FAN_OFF 9
#define THIRTY_SECONDS 10
#define CHOOSE_TIME 11
#define POWER_MENU 12
#define CHOOSE_POWER 13
#define COOKING 14 
#define STOPPED_COOKING 15
#define EASY_MENU 16
#define POPCORN_MENU 17
#define CONFIRM_POPCORN 18
#define CONFIRM_MUGCAKE 19
#define CONFIRM_OMELET 20
#define RICE_MENU 21
#define CONFIRM_RICE 22
#define CONFIRM_BRIGADEIRO 23
#define PIZZA_MENU 24
#define CONFIRM_PIZZA 25
#define BEANS_MENU 26
#define CONFIRM_BEANS 27
#define MEAT_MENU 28
#define CONFIRM_MEAT 29
#define CHICKEN_MENU 30
#define CONFIRM_CHICKEN 31
#define THAW_ON 32
#define THAW_OFF 33
#define LIST_MENU 34
#define LIST_MODE 35

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

extern bool rising_on;
extern bool rising_off;


#endif