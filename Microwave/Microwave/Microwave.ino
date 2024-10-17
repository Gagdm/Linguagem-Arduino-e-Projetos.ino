#include "states_trustee.h"

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

void setup() {
  
  pinMode(CURR, INPUT_PULLUP);
  pinMode(OPEN, INPUT_PULLUP);
  pinMode(TIMER, INPUT_PULLUP);
  pinMode(ON, INPUT_PULLUP);

  pinMode(LED, OUTPUT);

  lcd.init();
  lcd.backlight();

  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(ON), on_up, RISING);
  attachInterrupt(digitalPinToInterrupt(OFF), off_up, RISING);
  attachInterrupt(digitalPinToInterrupt(CURR), curr_up, RISING);
  attachInterrupt(digitalPinToInterrupt(TIMER), timer_up, RISING);
  attachInterrupt(digitalPinToInterrupt(TIMER), timer_down, FALLING);

  attachInterrupt(digitalPinToInterrupt(OPEN), door_signal, CHANGE);
}

void loop() {
  manager.state_maneger();
}

/* Se forem de LOW para HIGH, foram apertados */
void on_up() {
  rising_on = true;
}

void off_up() {
  rising_off = true;
}

void curr_up() {
  rising_curr = true;
}

/* Se for de HIGH para LOW -> true, LOW para HIGH -> false */
void timer_up() {
  press_timer = false;
}

void timer_down() {
  press_timer = true;
}

/* apertado = true, n apertado = false */
void door_signal() {
  press_open = !press_open;
}