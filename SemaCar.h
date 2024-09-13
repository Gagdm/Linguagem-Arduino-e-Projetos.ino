#ifndef SEMACAR_H
#define SEMACAR_H

#include "constantes.h"

class Semaphore {
  private: 
    /* Declarando variáveis que irão salvar o millis 
         necessário nas funções desta classe */
    unsigned long millisCarro;

    /* Declarando as flags */
    bool btn_on;
    bool restart;

    /* Auxiliar utilizado para definir a quantidade 
        de quadrados a serem printados no LCD */
    int count;

    /* Gerenciam o funcionamento do LEDs do semáforo para carros */
    void handle_green();
    void handle_yellow();
    void handle_red();

    /* Funções utilizadas para resetar o millis, 
            as flags e os auxiliares */
    void reset_flags_count();
    void restart_millisCarro();

  public: 
    /* Construtor */
    Semaphore();

    /* Função que genrenciará o funcionamento 
          do semáfaro para carros */
    void SemaCar();
};

#endif