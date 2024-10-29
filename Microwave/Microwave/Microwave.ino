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
  
  pinMode(OPEN, INPUT_PULLUP);
  pinMode(TIMER, INPUT_PULLUP);
  pinMode(ON, INPUT_PULLUP);
  pinMode(OFF, INPUT_PULLUP);

  pinMode(LED, OUTPUT);

  lcd.init();

  Serial.begin(9600);
  
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
  
  manager.state_manager();
  Serial.println(state);
  
  controller.task_manager();
  interface.interface_manager();
  
}