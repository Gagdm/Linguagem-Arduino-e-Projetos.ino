#ifndef CONSTANTES_H
#define CONSTANTES_H

#include <Arduino.h>
#include  <LiquidCrystal.h>
#include <stdio.h>

/* ASCII de caracteres utilizados no print */
#define S 255
#define NS 254

/* Portas dos leds do semáforo de carros (Analógico) */
#define RED A5
#define YELLOW A4
#define GREEN A3

/* Portas dos leds do semáforo de pedestre (Analógico) */
#define PED_BLUE A2
#define PED_RED A1
#define PED_GREEN A0

/* Portas dos pinos do LCD 16x2 (Digital) */
#define RS 2
#define E 3
#define D4 4
#define D5 5
#define D6 6
#define D7 7

/* Porta do botão (Digital) */
#define BUTTON 12

/* Porta do Buzzer (Digital) */
#define BUZZER 13

/* Declaração lcd */
extern LiquidCrystal lcd;

/* Declaração das variáveis que guardarão o valor dos 
             caracteres utilizados */
extern char SQUARE;
extern char NOT_SQUARE;

#endif