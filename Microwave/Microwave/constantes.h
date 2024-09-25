
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <Arduino.h>

#define CURR 13
#define OPEN 12
#define OFF 11
#define ON 10
#define LED 9

const byte LINHAS = 4; 
const byte COLUNAS = 4;

const char TECLAS_MATRIZ[LINHAS][COLUNAS] = { 
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

const byte PINOS_LINHAS[LINHAS] = {0, 1, 2, 3}; 
const byte PINOS_COLUNAS[COLUNAS] = {4, 5, 6, 7}; 

extern Keypad teclado_personalizado; 

extern LiquidCrystal_I2C lcd;