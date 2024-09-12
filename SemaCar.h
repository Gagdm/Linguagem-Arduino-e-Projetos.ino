#ifndef SEMACAR_H
#define SEMACAR_H

#include "constantes.h"

class Semaphore {
  private: 
    /* Declarando variáveis que salvarão os millis 
        necessários nas funções desta classe */
    unsigned long millisCarro;

    /* Declarando as flags */
    bool btn_on;
    bool restart;

    /* Auxiliar utilizada para definir a quantidade 
        de quadrados a serem printados no LCD */
    int count;

    /* Gerenciam o funcionamento do LEDs do Semaphore */
    void handle_green();
    void handle_yellow();
    void handle_red();

    /* Funções utilizadas para resetar o millis, 
            as flags e os auxiliares */
    void reset_flags();
    void restart_sinal_carro();

  public: 
    /* Construtor */
    Semaphore();

    /* Função que genrenciará o funcionamento 
          do semáfaro para carros */
    void SemaCar();
};

#endif