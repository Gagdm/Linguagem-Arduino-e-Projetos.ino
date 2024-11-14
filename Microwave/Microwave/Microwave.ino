#include "states_trustee.h"
#include "interruptions.h"
#include "interface.h"
#include "definitions.h"
#include "controller.h"

LiquidCrystal_I2C lcd(0x27,20,4);
Keypad teclado_personalizado = Keypad(makeKeymap(TECLAS_MATRIZ), PINOS_LINHAS, PINOS_COLUNAS, LINHAS, COLUNAS);

Manager manager;
Interface interface;
Clock clock;
Controller controller;

int state = TURN_OFF;
int old_state = TURN_OFF;
int index_list = 0;
int gramas = 0;
int power = 2;

volatile bool rising_on = false;
volatile bool rising_off = false;
volatile bool press_open = false;
volatile bool press_timer = false;
volatile bool down_timer = false;

volatile bool something_pressed = false;

char tecla = '?';
bool test = false;

bool mute = false;
bool block = false;

bool time_over_blocked = false;
int index_easy_menu = 0;

void setup() {
  
  Serial.begin(9600);
  pinMode(OPEN, INPUT_PULLUP);
  pinMode(TIMER, INPUT_PULLUP);
  pinMode(ON, INPUT_PULLUP);
  pinMode(OFF, INPUT_PULLUP);
  pinMode(POWER_1, OUTPUT);
  pinMode(POWER_2, OUTPUT);
  pinMode(POWER_3, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_DOOR, OUTPUT);

  lcd.init();

  init_interruptions();

  rising_on = false;
  rising_off = false;
  press_open = false;
  press_timer = false;
  down_timer = false;

}

void loop() {

  clock.microwave_clock();

  tecla = teclado_personalizado.getKey();

  if(tecla == '#') {
    mute = !mute;
  }
  
  if(state != TURN_OFF) {
    if(press_open == true) {
      digitalWrite(LED_DOOR, HIGH);
    }
    else {
      digitalWrite(LED_DOOR, LOW);
    }
  }

  if(state == COOKING || state == THAW_ON) {
    digitalWrite(LED_RED, HIGH);
  }
  else {
    digitalWrite(LED_RED, LOW);
  }

  manager.state_manager();
  
  controller.task_manager();
  controller.buzzer();
  Serial.println(power);

  interface.interface_manager();
  
}