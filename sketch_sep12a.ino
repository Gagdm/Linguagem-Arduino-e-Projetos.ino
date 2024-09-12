#include "SemaCar.h"

/* Definindo LCD 16x2 */
LiquidCrystal lcd(RS, E, D4, D5, D6, D7);

/* Instanciação global dos objetos semaforos */
Semaphore sem;

void setup() {
  // Mapemento dos LEDS
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(PED_BLUE, OUTPUT);
  pinMode(PED_RED, OUTPUT);
  pinMode(PED_GREEN, OUTPUT);

  // Mapeamento do botão
  pinMode(BUTTON, INPUT_PULLUP);

  // Mapeamento do buzzer
  pinMode(BUZZER, OUTPUT);

  // Inicialização e lcd
  lcd.begin(16, 2);
}

void loop() {
  // Semaforo para os carros
  sem.SemaCar();
}