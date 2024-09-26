#ifndef INTERFACE_H
#define INTERFACE_H

#include "constantes.h"

class MenuPrincipal {
    private:

        unsigned long millisClock; 

        int clockSeg;
        int clockMin;
        int clockHora;

        char HELP[15];

        unsigned long globalTime;
        unsigned long forTab;
        unsigned long forHelp;
        unsigned long forAjuste;
        unsigned long forBlink;
        
        int verif_threeSeg;
        bool ajustando;
        bool threeSeg;
        int numbers;
        int oldHour;
        int oldMin; 

        void ajustarClock();

        void verifica_threeSeg();

        void showTime();

        void help();

    public:
        MenuPrincipal();

        void initial_menu();

        void clock();
};

#endif