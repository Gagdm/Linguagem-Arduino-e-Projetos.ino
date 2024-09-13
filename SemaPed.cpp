#include "SemaPed.h"

char NOT_SQUARE = NS;

// bip med=édio ao abrir o sinal verde
void SemaphorePed::handle_PedRed() {
  if((btn_on == true) && ((millis() - millisPedestre) > 17000)) {
    digitalWrite(PED_RED, LOW);
  }
  else {
    if(((millis() - millisPedestre) > 7000) && ((millis() - millisPedestre) < 7200)) {
      digitalWrite(PED_RED, LOW);
    }
    else {
      digitalWrite(PED_RED, HIGH);
      lcd.setCursor(14, 0);
      lcd.print(NOT_SQUARE);
      lcd.print(NOT_SQUARE);
    }
  }
}

void SemaphorePed::handle_PedGreen() {
  if((btn_on == true) && ((millis() - millisPedestre) > 17000)) {
    if(((millis() - millisPedestre) > 28000) && ((millis() - millisPedestre) < 28200)) {
      digitalWrite(PED_GREEN, LOW);
    }
    else {
      digitalWrite(PED_GREEN, HIGH);
    }

    count = 21;
    int take_count = ((millis() - millisPedestre) - 17000) / 1000;
    count = count - take_count;

    lcd.setCursor(14, 0);
    lcd.print(NOT_SQUARE);
    lcd.print(NOT_SQUARE);
    if(count < 10) {
      lcd.setCursor(15, 0);
    }
    else {
      lcd.setCursor(14, 0);
    }

    lcd.print(count);
  }
  else {
    digitalWrite(PED_GREEN, LOW);
  }
}

void SemaphorePed::handle_PedBlue() {
  if((btn_on == true) && ((millis() - millisPedestre) > 28000)) {
    if((millis() - forBlue) > 500) {
      restart_forBlue();
    }
    if((millis() - forBlue) < 250) {
      digitalWrite(PED_BLUE, HIGH);
    }
    else {
      digitalWrite(PED_BLUE, LOW);
    }
  }
  else {
    digitalWrite(PED_BLUE, LOW);
  }
}

void SemaphorePed::controller_Buzzer() {
  if((btn_on == true) && ((millis() - millisPedestre) > 17000) && ((millis() - millisPedestre) < 17600)) {
    tone(BUZZER, 2000);
  }
  else if((btn_on == true) && ((millis() - millisPedestre) > 28000)) {
    if((millis() - millisPedestre) < 37000) {
      if((millis() - forBuzzer) > 2000) {
        restart_forBuzzer();
      }
      if((millis() - forBuzzer) < 300) {
        tone(BUZZER, 6500);
      }
      else {
        noTone(BUZZER);
      }
    }
    else { 
      tone(BUZZER, 2000);
    }
    
  }
  else {
    noTone(BUZZER);
  }
}

void SemaphorePed::reset_flags_count() {
  btn_on = false;
  restart = true;
  count = 21;
}


void SemaphorePed::restart_millisPedestre() {
  millisPedestre = millis();
  restart = false;
}

void SemaphorePed::restart_forBlue() {
  forBlue = millis();
}

void SemaphorePed::restart_forBuzzer() {
  forBuzzer = millis();
}



SemaphorePed::SemaphorePed() {
  millisPedestre = millis();
  forBlue = millis();
  forBuzzer = millis();
  btn_on = false;
  restart = true;
  count = 21;
}

void SemaphorePed::SemaPed() {
  if(digitalRead(BUTTON) == LOW) {
    btn_on = true;
    if(restart == true) {
      restart_millisPedestre();
      restart_forBlue();
      restart_forBuzzer();
    }
  }

  if((btn_on == true) && (restart == false) && ((millis() - millisPedestre) > 38000)) {
    reset_flags_count();
  }

  handle_PedRed();
  handle_PedGreen();
  handle_PedBlue();

  controller_Buzzer();
}