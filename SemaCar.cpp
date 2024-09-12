#include "SemaCar.h"

/* reseta as flags e o count para o próximo ciclo */
void Semaphore::reset_flags_count() {
  btn_on = false;
  restart = true;
  count = 0;
}

void Semaphore::handle_green() {
  if(apertado == false) {
    digitalWrite(GREEN, HIGH);
    for(int i = 0; i < 10; i ++) {
      lcd.setCursor(i,0);
      lcd.print(val);
      lcd.setCursor(i,1);
      lcd.print(val);
    }
  }
  if (((millis() - millis_carro) < 15000) && (apertado == true)) {
    digitalWrite(GREEN, HIGH);
    if(((millis() - millis_carro) < 5000) || (((millis() - millis_carro) > 5200) && ((millis() - millis_carro) < 6000))) {
        for(int i = 0; i < 10; i ++) {
          lcd.setCursor(i,0);
          lcd.print(val);
          lcd.setCursor(i,1);
          lcd.print(val);
        }
    }
    if(((millis() - millis_carro) < 5200) && ((millis() - millis_carro) > 5000)) {
      lcd.clear();
    }


    if(((millis() - millis_carro)  < 16000) && ((millis() - millis_carro) > 6000)) {
      int quant = ((millis() - millis_carro) - 5000) / 1000;
      if(temp < quant) {
        temp = quant;
        lcd.clear();
      }
      for(int i = 0; i < 10 - quant; i++) {
        lcd.setCursor(i,0);
        lcd.print(val);
        lcd.setCursor(i,1);
        lcd.print(val);
      }
    }

  }
  else {
    digitalWrite(GREEN, LOW);
  }
}

void Semaphore::handle_yellow() {
  if (((millis() - millis_carro) > 15000) && ((millis() - millis_carro) < 17000) && (apertado == true)) {
    lcd.clear();
    temp = 0;
    digitalWrite(YELLOW, HIGH);
  }
  else {
    digitalWrite(YELLOW, LOW);
  }
}

void Semaphore::handle_red() {
  if (((millis() - millis_carro) > 17000) && (apertado == true)) {
    digitalWrite(RED, HIGH);
    if(((millis() - millis_carro) < 27000) || (((millis() - millis_carro) < 28000) && ((millis() - millis_carro) > 27200))) {
      for(int i = 0; i < 10; i ++) {
        lcd.setCursor(i,0);
        lcd.print(val);
        lcd.setCursor(i,1);
        lcd.print(val);
      }
    }
    if(((millis() - millis_carro) < 27200) && ((millis() - millis_carro) > 27000)) {
      lcd.clear();
    }
    if(((millis() - millis_carro)  < 38000) && ((millis() - millis_carro) > 28000)) {
      int quant2 = ((millis() - millis_carro) - 27000) / 1000;
      if(temp < quant2) {
        temp = quant2;
        lcd.clear();
      }
      for(int i = 0; i < 10 - quant2; i++) {
        lcd.setCursor(i,0);
        lcd.print(val);
        lcd.setCursor(i,1);
        lcd.print(val);
      }
    }
  }
  else {
    digitalWrite(RED, LOW);
  }
}

void Semaphore::restart_sinal_carro() {  
  millis_carro = millis();
  restart = false;  
}



Semaphore::Semaphore() {
  millis_carro = millis();
  millisPedestre = millis();
  forBlue = millis();
  forBuzzer = millis();
  apertado = false;
  restart = true;
  temp = 0;
}

void Semaphore::SemaCar() {
  if (digitalRead(BUTTON) == LOW) {
    apertado = true;
    if((restart == true)) {
      restart_sinal_carro();
    }
  }

  if((apertado == true) && (restart == false) && ((millis() - millis_carro) > 38000)) {
    reset_flags();
  } 
  handle_green();
  handle_yellow();
  handle_red();
}
