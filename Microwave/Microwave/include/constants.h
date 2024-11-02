#ifndef CONSTANTES_H
#define CONSTANTES_H

//=============================================================================================
/* Include libs */
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <Arduino.h>
#include <stdio.h>
#include <string.h>

//=============================================================================================
/* Defining pins to buttons, leds and among others
                  components */
#define OFF 2
#define TIMER 3
#define OPEN 18
#define ON 19
#define LED 8

//=============================================================================================
/* Characters used in lcd prints and tabs */
const char DOIS_PONTOS = 58;
const char BOLINHA = 165;
const char FLORZINHA = 235;
const char BARRA = 124;
const char NOT_SQUARE = 254;
const char ARROW_RIGHT = 126;
const char ARROW_LEFT = 127;

//=============================================================================================
/* The duration of the button bounce treated in the 
                  interruptions */
#define BOUNCE_DURATION 40

//=============================================================================================
/* Defining matrix keyboard: number of lines and columns, meaning of 
    the keys, keyboard pins and the object 'teclado_persinalizado' */
const byte LINHAS = 4; 
const byte COLUNAS = 4;

const char TECLAS_MATRIZ[LINHAS][COLUNAS] = 
{ 
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

const byte PINOS_LINHAS[LINHAS] = {45, 44, 43, 42}; 
const byte PINOS_COLUNAS[COLUNAS] = {41, 40, 39, 38}; 

extern Keypad teclado_personalizado;

//=============================================================================================
/* Defining the microwave states */
enum states_t 
{  
  TURN_OFF, INIT, INIT_HELP, BLOCKED, FIX_CLOCK,
  CHOOSE_TIMER, TIMER_E, FAN_MENU, FAN_ON, FAN_OFF,
  THIRTY_SECONDS, CHOOSE_TIME, POWER_MENU, CHOOSE_POWER,
  COOKING, STOPPED_COOKING, EASY_MENU, POPCORN_MENU,
  CONFIRM_POPCORN, CONFIRM_MUGCAKE, CONFIRM_OMELET,
  RICE_MENU, CONFIRM_RICE, CONFIRM_BRIGADEIRO, PIZZA_MENU,
  CONFIRM_PIZZA, BEANS_MENU, CONFIRM_BEANS, MEAT_MENU,
  CONFIRM_MEAT, CHICKEN_MENU, CONFIRM_CHICKEN,
  THAW_ON, THAW_OFF, LIST_MENU, LIST_MODE     
};

//=============================================================================================
/* This is used for identify if 'TIMER' was pressed 
                  for 3 seconds */
#define NO_PRESS 0
#define NO_PRESSED_FOR_THREE 1
#define PRESSED_FOR_THREE 2

//=============================================================================================
/* Defining things used in the microwave interface: 
         lcd tabs and the object 'lcd' */
extern char lcd_tabs_4x15[7][4][15];
extern char lcd_tabs_4x20[30][4][21];
extern char lcd_clock[5][6];

extern LiquidCrystal_I2C lcd;

//=============================================================================================

/* vou colocar isso aq tbm dentro de uma classe */
extern bool mute;
extern bool block;

/* vou colocar dentro de alguma classe ainda */
extern bool time_over_blocked;
extern int state;
extern int old_state;
extern char tecla;
extern int index_easy_menu;
extern int index_list;

#endif