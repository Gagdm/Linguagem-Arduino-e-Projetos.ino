#ifndef SEMAPED_H
#define SEMAPED_H

#include "constantes.h"

class SemaphorePed {
  private:
    /* Declarando variáveis que irão salvar os millis 
        necessário nas funções desta classe */
    unsigned long millisPedestre;
    unsigned long forBlue;
    unsigned long forBuzzer;

    /* Declarando as flags */
    bool btn_on;
    bool restart;

    /* Auxiliar utilizado para definir o número que irá 
        aparecer no LCD na contagem regressiva */
    int count;
    
    /* Auxiliar utilizado para evitar que os números da contagem regresiva
         para o LED PED_GREEN apareçam de forma tremeluzente */
    int erase;

    /* Gerenciam o funcionamento do LEDs do semáforo para pedestres */
    void handle_PedRed();
    void handle_PedGreen();
    void handle_PedBlue();

    /* Gerencia o funcionamento do Buzzer */
    void controller_Buzzer();

     /* Funções utilizadas para resetar os millis, 
            as flags e os auxiliares */
    void reset_flags_count();
    void restart_millisPedestre();
    void restart_forBlue();
    void restart_forBuzzer();

  public:
    /* Construtor */
    SemaphorePed();

    /* Função que genrenciará o funcionamento 
          do semáfaro para pedestres */
    void SemaPed();

};

#endif