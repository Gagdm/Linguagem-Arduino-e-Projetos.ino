#include "clock.h"

Clock::Clock() {

    millisClock = millis();

    clockSeg = 0;
    clockMin = 0;
    clockHour = 12;

    Old_clockMin = 0;
    Old_clockHour = 0;

    ring = false;
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

    if(timerSeg == -3) {
      ring = false;
      timer_is_up = true;
    }
    
    if((millis() - millisTimer) > 1000) {
      timerSeg--;
      millisTimer = millis();
    }

    if(timerSeg == -1 && timerMin > 0) {
      timerSeg = 59;
      timerMin--;
    }
    else if(timerSeg <= 0 && timerMin == 0) {
      ring = true;
    }

    show_timer();

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
        clockHour = tecla;
        break;
      case 1:
        clockHour = ((clockHour*10)+tecla)%24;
        break;
      case 2:
        clockMin = tecla;
        break;
      case 3:
        clockMin = (
          (clockMin*10)+tecla)%60;
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


void Clock::set_timerMin_Seg(int Min, int Seg) {

  timerMin = Min;
  timerSeg = Seg;
  
}

bool Clock::get_ring() {

  return ring;

}
void Clock::set_ring(bool value) {
  ring = value;
}

bool Clock::get_timer_is_up() {

  return timer_is_up;
  
}

void Clock::set_timer_is_up(bool value) {

  timer_is_up = value;

}

bool Clock::get_timer_on() {

  return timer_on;

}

void Clock::set_timer_on(bool value) {

  timer_on = value;

}

void Clock::set_timerSeg(int value) {

  timerSeg = value;

}

void Clock::set_timerMin(int value) {

  timerMin = value;

}

void Clock::reset_millisTimer() {

  millisTimer = millis();

}

int Clock::get_timerSeg() {
  return timerSeg;
}

int Clock::get_timerMin() {
  return timerMin;
}

void Clock::show_timer() {

  if((millis() - forBlink) > 800) {

    forBlink = millis();

  }

  if(ring == false) {

    if(timerMin < 10) {

      lcd_tabs_4x20[28][2][7] = '0';
      lcd_tabs_4x20[28][2][8] = timerMin + 48;

    }
    else {

      lcd_tabs_4x20[28][2][7] = (timerMin/10) + 48;
      lcd_tabs_4x20[28][2][8] = (timerMin%10) + 48;

    }

    lcd_tabs_4x20[28][2][9] = DOIS_PONTOS;

    if(timerSeg < 10) {

      lcd_tabs_4x20[28][2][10] = '0';
      lcd_tabs_4x20[28][2][11] = timerSeg + 48;

    }    
    else {

      lcd_tabs_4x20[28][2][10] = (timerSeg/10) + 48;
      lcd_tabs_4x20[28][2][11] = (timerSeg%10) + 48;

    }

  }
  else if(ring == true && (millis() - forBlink) >= 600) {

    lcd_tabs_4x20[28][2][7] = ' ';
    lcd_tabs_4x20[28][2][8] = ' ';
    lcd_tabs_4x20[28][2][9] = ' ';
    lcd_tabs_4x20[28][2][10] = ' ';
    lcd_tabs_4x20[28][2][11] = ' ';

  }
  else {

  
    lcd_tabs_4x20[28][2][7] = '0';
    lcd_tabs_4x20[28][2][8] = '0';
    lcd_tabs_4x20[28][2][9] = ':';
    lcd_tabs_4x20[28][2][10] = '0';
    lcd_tabs_4x20[28][2][11] = '0';

  }

}