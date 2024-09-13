#ifndef SEMAPED_H
#define SEMAPED_H

#include "constantes.h"

class SemaphorePed {
  private:

    unsigned long millisPedestre;
    unsigned long forBlue;
    unsigned long forBuzzer;

    bool btn_on;
    bool restart;

    int count;

    void handle_PedRed();
    void handle_PedGreen();
    void handle_PedBlue();

    void controller_Buzzer();

    void reset_flags_count();

    void restart_millisPedestre();
    void restart_forBlue();
    void restart_forBuzzer();

  public:
    SemaphorePed();

    void SemaPed();

};

#endif