#include "SemaPed.h"
#include "SemaCar.h"

/* Definindo LCD 16x2 */
LiquidCrystal lcd(RS, E, D4, D5, D6, D7);

/* Instanciação global dos objetos semaforos */
SemaphorePed semp;
Semaphore sem;

/* Variáveis que guardam os ASCII dos caracteres 
              a serem utilizados */
char SQUARE = S;
char NOT_SQUARE = NS;

void setup() {
  /* Mapemento dos LEDS */
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(PED_BLUE, OUTPUT);
  pinMode(PED_RED, OUTPUT);
  pinMode(PED_GREEN, OUTPUT);

  /* Mapeamento do botão */
  pinMode(BUTTON, INPUT_PULLUP);

  /* Mapeamento do buzzer */
  pinMode(BUZZER, OUTPUT);

  /* Iicialização do LCD 16x2 */
  lcd.begin(16,2);
}

void loop() {
  /* Chamada dos métodos que gerenciam o funcionamento de cada sinal */
  semp.SemaPed();
  sem.SemaCar();
}