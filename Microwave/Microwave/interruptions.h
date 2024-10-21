#ifndef INTERRUPTIONS_H
#define INTERRUPTIONS_H

#include "constantes.h"

void init_interruptions();

/* Se forem de LOW para HIGH, foram apertados */
void on_up();

void off_up();

void curr_up();

/* Se for de HIGH para LOW -> true, LOW para HIGH -> false */
void timer_up();

void timer_down();

/* apertado = true, n apertado = false */
void door_signal();

void changed_timer();

#endif