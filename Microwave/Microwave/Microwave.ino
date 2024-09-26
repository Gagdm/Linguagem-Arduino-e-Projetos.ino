
#include "Interface.h"

LiquidCrystal_I2C lcd(0x27,20,4);
Keypad teclado_personalizado = Keypad(makeKeymap(TECLAS_MATRIZ), PINOS_LINHAS, PINOS_COLUNAS, LINHAS, COLUNAS);

bool cooking = false;

MenuPrincipal Menu;

void setup() {
  
  pinMode(CURR, INPUT_PULLUP);
  pinMode(OPEN, INPUT_PULLUP);
  pinMode(TIMER, INPUT_PULLUP);
  pinMode(ON, INPUT_PULLUP);

  pinMode(LED, OUTPUT);

  lcd.init();
  lcd.backlight();

  Serial.begin(9600);
   
}

void loop() {
  
  Menu.clock();
  if(cooking == false) {
    Menu.initial_menu();
  }
}