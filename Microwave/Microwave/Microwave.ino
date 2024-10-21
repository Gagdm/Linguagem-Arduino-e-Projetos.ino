#include "states_trustee.h"
#include "interruptions.h"

LiquidCrystal_I2C lcd(0x27,20,4);
Keypad teclado_personalizado = Keypad(makeKeymap(TECLAS_MATRIZ), PINOS_LINHAS, PINOS_COLUNAS, LINHAS, COLUNAS);

Manager manager;

int state = TURN_OFF;
int old_state = TURN_OFF;

bool rising_on = false;
bool rising_off = false;
bool rising_curr = false;
bool press_open = false;
bool press_timer = false;
bool down_timer = false;
int tecla = '?';

void setup() {
  
  pinMode(CURR, INPUT_PULLUP);
  pinMode(OPEN, INPUT_PULLUP);
  pinMode(TIMER, INPUT_PULLUP);
  pinMode(ON, INPUT_PULLUP);

  pinMode(LED, OUTPUT);

  lcd.init();
  lcd.backlight();

  Serial.begin(9600);
  init_interruptions();
}

void loop() {
  tecla = teclado_personalizado.getKey();
  if((tecla)) {
    manager.state_maneger();
  }
}