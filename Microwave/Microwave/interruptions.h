#ifndef INTERRUPTIONS_H
#define INTERRUPTIONS_H

#include "constantes.h"

void init_interruptions();

/* Se forem de LOW para HIGH, foram apertados */
void on_up();

void off_up();

/* apertado = true, n apertado = false */
void door_signal();

void timer_signal();

#endif