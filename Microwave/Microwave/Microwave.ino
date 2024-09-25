
// A - acessar Menu
// * - Bloquear
// # - Mute
// B - Timer
// C - Potencia
// D - Tirar Odor

#include "constantes.h"

LiquidCrystal_I2C lcd(0x27,20,4);
Keypad teclado_personalizado = Keypad(makeKeymap(TECLAS_MATRIZ), PINOS_LINHAS, PINOS_COLUNAS, LINHAS, COLUNAS);

int estado = 0;
char hora[5] = {"12:00"} ;
char begin[12][6];

void showTime() {

  char a = 235;
  char b = 124;
  char c = 235;
  lcd.setCursor(0,1);
  lcd.print("Time");
  lcd.print(c);
  lcd.setCursor(0,2);
  lcd.print(hora);
  for(int i = 0; i < 4; i++) {
    lcd.setCursor(5,i);
    lcd.print(b);
  }

}

void initialMenu() {

  char d = 162;
  char e = 163;
  lcd.setCursor(8,1);
  lcd.print(d);
  lcd.print(d);
  lcd.print(" HELP ");
  lcd.print(e);
  lcd.print(e);

}

void setup() {
  
  pinMode(CURR, INPUT_PULLUP);
  pinMode(OPEN, INPUT_PULLUP);
  pinMode(OFF, INPUT_PULLUP);
  pinMode(ON, INPUT_PULLUP);

  pinMode(LED, OUTPUT);

  lcd.init();
  lcd.backlight();
   
}

void loop() {
  if(estado == 0) {
    showTime();
    initialMenu();
  }
 
}