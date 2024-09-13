#ifndef SEMAPED_H
#define SEMAPED_H

#include "constantes.h"

class SemaphorePed {
  private:

    void handle_PedRed();
    void handle_PedGreen();
    void handle_PedBlue();
    
  public:
    SemaphorePed();

    void SemaPed();
}

#endif