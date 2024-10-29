#include "clock.h"

Clock::Clock() {

    millisClock = millis();

    clockSeg = 0;
    clockMin = 0;
    clockHour = 12;

    Old_clockMin = 0;
    Old_clockHour = 0;

    start_fixing = false;
    input = 0;

    millisTimer = millis();
    forBlink = millis();

    timerSeg = 0;
    timerMin = 0;

    timer_is_up = false;
    timer_on = false;

}

void Clock::microwave_clock() {

    if((millis() - millisClock) > 1000) {
        clockSeg++;
        millisClock = millis();
    }

    if(clockSeg == 60) {
        clockMin++;
        clockSeg = 0;
    }

    if(clockMin == 60) {
        clockHour++;
        clockMin = 0;
    }

    if(clockHour == 24) {
        clockHour = 0;
    }

}

void Clock::microwave_timer() {

    if(timerMin == 0 && timerSeg == 0) {
        timer_is_up = true;
    }
    
    if(timerSeg == -1 && timerMin > 0) {
        timerSeg = 59;
        timerMin--;
    }

    if((millis() - millisTimer) > 1000) {
        timerSeg--;
        millisTimer = millis();
    }

}

void Clock::show_time() {

  for(int i = 0; i < 4; i++) {

    lcd.setCursor(0,i);

    switch(i) {
      case 0:

        if((block == true) && (mute == true)) lcd.print(lcd_clock[4]);
        else if(block == true) lcd.print(lcd_clock[3]);
        else if(mute == true) lcd.print(lcd_clock[2]);
        else lcd.print(lcd_clock[0]);

        break;

      case 1:

        lcd.print(lcd_clock[1]);
        break;

      case 2:

        if((millis() - forBlink) > 300) {
          forBlink = millis();
        }

        if(state == FIX_CLOCK && (millis() - forBlink) < 150) {

          if(clockHour < 10) {
            lcd.print("0");
            lcd.print(clockHour);
          }
          else {
            lcd.print(clockHour);
          }

          lcd.print(DOIS_PONTOS);

          if(clockMin < 10) {
            lcd.print("0");
            lcd.print(clockMin);
          }
          else {
            lcd.print(clockMin);
          }

        }
        else if(state == FIX_CLOCK && (millis() - forBlink) >= 150 && (input < 4)) {

          lcd.print(lcd_clock[0]);

        }
        else if(state != FIX_CLOCK) {
          
          if(clockHour < 10) {
            lcd.print("0");
            lcd.print(clockHour);
          }
          else {
            lcd.print(clockHour);
          }

          lcd.print(DOIS_PONTOS);

          if(clockMin < 10) {
            lcd.print("0");
            lcd.print(clockMin);
          }
          else {
            lcd.print(clockMin);
          }

        }
        break;

      default:

        lcd.print(lcd_clock[0]);

    } 
  }

}
  
void Clock::fix_clock() {

  if(start_fixing == true) {
    Old_clockMin = clockMin;
    Old_clockHour = clockHour;
    clockMin = 0;
    clockHour = 0;
    start_fixing = false;
    input = 0;
  }

  if(tecla >= '0' && tecla <= '9') {

    tecla = tecla - '0';

    switch(input) {
      case 0: 
        clockHour = (tecla*10)%24;
        break;
      case 1:
        clockHour = (clockHour+tecla)%24;
        break;
      case 2:
        clockMin = (tecla*10)%60;
        break;
      case 3:
        clockMin = (clockMin+tecla)%60;
        break;   
    }
    input++;

  }

}

void Clock::set_start_fixing(bool value) {

  start_fixing = value;

}

void Clock::set_clockHour() {

  clockHour = Old_clockHour;
  clockMin = Old_clockMin;

}

int Clock::get_input() {

  return input;
  
}

