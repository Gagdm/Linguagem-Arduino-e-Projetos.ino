
#include "Interface.h"

void MenuPrincipal::ajustarClock() {

    int tecla;

    /* se o botão off foi apertado */
    if(digitalRead(OFF) == LOW) {
        clockHora = oldHour;
        clockMin = oldMin;
        threeSeg = false;
    }
    else if(numbers == 0) {
        clockHora = 0;
        clockMin = 0;
    }

    tecla = (teclado_personalizado.getKey() - 48);
    if((threeSeg == true) && (tecla >= 0) && (tecla <= 9)) { 
        numbers++;

        switch(numbers) {

            case 1: clockHora = (tecla%2)*10; break;

            case 2: clockHora = (clockHora + tecla)%24; break;

            case 3: 

                if(tecla > 6) {
                    tecla = tecla%6;
                    clockHora = (clockHora + 1)%24;
                }
                clockMin = tecla*10; break;

            case 4: clockMin = clockMin + tecla; break;
            default: break;
        }
    }

    if((digitalRead(ON) == LOW) && (numbers == 4)) {
        threeSeg = false;
        ajustando = false;
    }
}

void MenuPrincipal::verifica_threeSeg() {
    /* se o botão foi pressionado */
    if(digitalRead(TIMER) == LOW) {
        /* checagem a cada 100ms */
        if((millis() - forAjuste) > 100) {
            forAjuste = millis();

            verif_threeSeg++;
            /* caso atinga 3s de pressionado */
            if(verif_threeSeg == 31) {
                oldHour = clockHora;
                oldMin = clockMin;
                threeSeg = true;
                ajustando = true;
            }
        }
    } 
    else {
        /* caso não sejam 3s, reseta o verif, para não afetar em checagens futuras */
        verif_threeSeg = 0;
    }
}

void MenuPrincipal::showTime() {
    /* exibe 'Time' no LCD 20x4 */
    lcd.setCursor(0,1);
    lcd.print("Time");
    lcd.print(FLORZINHA);
    lcd.setCursor(0,2);

    if((ajustando == true) && ((millis() - forBlink) > 800)) {
        forBlink = millis();
    }

    if((ajustando == true) && ((millis() - forBlink) < 200)) {
        lcd.setCursor(0,2);
        for(int i = 0; i < 5; i++) {
            lcd.print(NOT_SQUARE);
        }
    }
    else {  
        /* adiciona um 0, caso o clockHora e clockMin seja menor que 10  
                        ( '00:00'  - 'Hora:Minuto' ) */
        if(clockHora < 10) {
            lcd.print("0");
        }
        lcd.print(clockHora);
        lcd.print(DOIS_PONTOS);
        if(clockMin < 10) {
            lcd.print("0");
        }
        lcd.print(clockMin);
    
        /* exibe uma divisória entre o clock e a página ao lado */
        for(int i = 0; i < 4; i++) {
            lcd.setCursor(5,i);
            lcd.print(BARRA);
        }
    }
}

void MenuPrincipal::help() {
    /* exibe 'HELP' e ajusta as posições das '>' e '<' a cada 90ms, 
            dando efeito ao que é exibido no LCD 20x4 */    
    if((millis() - forHelp) > 90) {
        forHelp = millis();

        lcd.setCursor(6,0);
        lcd.print(HELP);

        /* lado esquerdo '<' */
        char aux = HELP[0];
        for (int i = 0; i < 4; i++) {
            HELP[i] = HELP[i+1];
        }
        HELP[4] = aux;

        /* lado direito '>' */
        aux = HELP[13];
        for (int i = 12; i >= 9; i--) {
            HELP[i+1] = HELP[i];
        }
        HELP[9] = aux;
    }

    /* cada aba da seção ajuda será exibida durante 5s */
    if((millis() - forTab) <= 5000) {
        for(int i = 0; i < 3; i++) {
            lcd.setCursor(6,(i+1));
            lcd.print(BottonsMenu[i]);
        }
    }
    else if((millis() - forTab) <= 10000) {
        for(int i = 0; i < 3; i++) {
            lcd.setCursor(6,(i+1));
            lcd.print(KeysMenuOne[i]);
        }
    }
    else if((millis() - forTab) <= 15000) {
        for(int i = 0; i < 3; i++) {
            lcd.setCursor(6,(i+1));
            lcd.print(KeysMenuTwo[i]);
        }
    }
    else {
        forTab = millis();
    }
}

MenuPrincipal::MenuPrincipal() {
    /* millis para o gerenciamento do clock*/
    millisClock = millis();
    clockSeg = 0;
    clockMin = 0;
    clockHora = 12;

    /* para printar o HELP */
    forHelp = millis();
    forTab = millis();
    strcpy(HELP,"  <<<HELP>>>  ");

    /* para o realizar o ajuste no clock */
    forAjuste = millis();
    forBlink = millis();
    ajustando = false;
    threeSeg = false;
    numbers = 0;
    oldHour = 0;
    oldMin = 0; 
}

void MenuPrincipal::initial_menu() {
    verifica_threeSeg();

    if(threeSeg == true) {
        ajustarClock();
    }

    showTime();
    help();

}

/* gerenciamento do relógio que é exibido no Menu Principal */
void MenuPrincipal::clock() {   

    /* a cada segundo */
    if((millis() - millisClock) > 1000) {
        clockSeg++;
        millisClock = millis();
    }

    /* a cada minuto */
    if(clockSeg == 60) {
        clockSeg = 0;
        clockMin++;
    }

    /* a cada hora */
    if(clockMin == 60) {
        clockMin = 0;
        clockHora++;
    }

    /* a cada dia */
    if(clockHora == 24) {
        clockHora = 0;
    }   
}
