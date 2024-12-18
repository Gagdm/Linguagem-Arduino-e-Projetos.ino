#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include "constantes.h"

char lcd_tabs_4x15[7][4][15] = {
  {
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
    {' ', ' ', '<', '<', '<', 'H', 'E', 'L', 'P', '>', '>', '>', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', 'S', 'e', 'l', 'e', 'c', 't', 126, '\0'}
  },
  {
    {' ', ' ', '<', '<', '<', 'H', 'E', 'L', 'P', '>', '>', '>', ' ', ' ', '\0'},
    {' ', ' ', ' ', 'B', 'u', 't', 't', 'o', 'n', 's', 58 , ' ', ' ', ' ', '\0'},
    {' ', 165, 'T', 'i', 'm', 'e', 'r', ' ', 165, 'D', 'o', 'o', 'r', ' ', '\0'},
    {' ', ' ', 165, 'O', 'f', 'f', ' ', ' ', ' ', 165, 'O', 'n', ' ', ' ', '\0'}
  },
  {
    {' ', ' ', '<', '<', '<', 'H', 'E', 'L', 'P', '>', '>', '>', ' ', ' ', '\0'},
    {' ', ' ', ' ', 'K', 'e', 'y', 'b', 'o', 'a', 'r', 'd', ' ', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', 'A', 58 , 'M', 'e', 'n', 'u', ' ', ' ', ' ', ' ', '\0'},
    {' ', ' ', ' ', 'B', 58 , 'F', 'a', 'n', ' ', 'o', 'n', ' ', ' ', ' ', '\0'} 
  },
  {
    {' ', ' ', '<', '<', '<', 'H', 'E', 'L', 'P', '>', '>', '>', ' ', ' ', '\0'},
    {' ', ' ', ' ', 'K', 'e', 'y', 'b', 'o', 'a', 'r', 'd', ' ', ' ', ' ', '\0'},
    {' ', 'C', 58 , 'P', 'i', 'c', 'k', ' ', 'p', 'o', 'w', 'e', 'r', ' ', '\0'},
    {' ', ' ', ' ', 'D', 58, 'S' , 'e', 'l', 'e', 'c', 't', ' ', ' ', ' ', '\0'}
  },
  {
    {' ', ' ', '<', '<', '<', 'H', 'E', 'L', 'P', '>', '>', '>', ' ', ' ', '\0'},
    {' ', ' ', ' ', 'K', 'e', 'y', 'b', 'o', 'a', 'r', 'd', ' ', ' ', ' ', '\0'},
    {' ', ' ', '*', 58 , 'B', 'l', 'o', 'c', 'k', ' ', 'o', 'n', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', '#', 58 , 'M', 'u', 't', 'e', ' ', ' ', ' ', ' ', '\0'}
  },
  {
    {' ', ' ', ' ', ' ', 'F', 'i', 'x', 'i', 'n', 'g', ' ', ' ', ' ', ' ', '\0'},
    {' ', ' ', ' ', 't', 'h', 'e', ' ', 't', 'i', 'm', 'e', ' ', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
    {127, 'O', 'f', 'f', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'O', 'n', 126, '\0'}
  },
  {
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'}
  }
};

char lcd_tabs_4x20[31][4][21]= {
  {
    {' ', ' ', ' ', 'T', 'i', 'm', 'e', 'r', ' ', 'f', 'u', 'n', 'c', 't', 'i', 'o', 'n', ' ', ' ', ' ', '\0'},
    {' ', ' ', ' ', 'T', 'i', 'm', 'e', ' ', 's', 'e', 't', ' ', 'm', 'o', 'd', 'e', ':', ' ', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
    {127, 'O', 'f', 'f', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'O', 'n', 126, '\0'}
  },
  {
    {' ', 'D', 'o', ' ', 'y', 'o', 'u', ' ', 'w', 'a', 'n', 't', ' ', 'c', 'h', 'o', 'o', 's', 'e', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', ' ', 'a', ' ', 'p', 'o', 'w', 'e', 'r', '?', ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
    {127, 'O', 'f', 'f', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'O', 'n', 126, '\0'}
  },
  {
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', '1', ':', 'L', 'o', 'w', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', ' ', '2', ':', 'M', 'e', 'd', 'i', 'u', 'm', ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', '3', ':', 'H', 'i', 'g', 'h', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
    {127, 'O', 'f', 'f', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'}
  },
  {
    {' ', ' ', 'C', 'h', 'e', 'c', 'k', ' ', 'i', 'n', 's', 'i', 'd', 'e', ' ', 't', 'h', 'e', ' ', ' ', '\0'},
    {' ', ' ', 'm', 'i', 'c', 'r', 'o', 'w', 'a', 'v', 'e', ',', ' ', 'i', 's', ' ', 'i', 't', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', 'e', 'm', 'p', 't', 'y', '?', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
    {127, 'O', 'f', 'f', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'O', 'n', 126, '\0'}
  },
  {
    {' ', ' ', 'S', 'e', 'l', 'e', 'c', 't', ' ', 'a', 'n', ' ', 'o', 'p', 't', 'i', 'o', 'n', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'C', 'o', 'o', 'k', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', ' ', 165, 'P', 'o', 'p', 'c', 'o', 'r', 'n', ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
    {127, 'S', 'e', 'l', 'e', 'c', 't', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'}
  },
  {
    {' ', ' ', 'S', 'e', 'l', 'e', 'c', 't', ' ', 'a', 'n', ' ', 'o', 'p', 't', 'i', 'o', 'n', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'C', 'o', 'o', 'k', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', 165, ' ', 'M', 'u', 'g', ' ', 'c', 'a', 'k', 'e', ' ', ' ', ' ', ' ', ' ', '\0'},
    {127, 'S', 'e', 'l', 'e', 'c', 't', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'}
  },
  {
    {' ', ' ', 'S', 'e', 'l', 'e', 'c', 't', ' ', 'a', 'n', ' ', 'o', 'p', 't', 'i', 'o', 'n', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'C', 'o', 'o', 'k', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', ' ', 165, ' ', 'O', 'm', 'e', 'l', 'e', 't', ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
    {127, 'S', 'e', 'l', 'e', 'c', 't', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'}
  },
  {
    {' ', ' ', 'S', 'e', 'l', 'e', 'c', 't', ' ', 'a', 'n', ' ', 'o', 'p', 't', 'i', 'o', 'n', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'C', 'o', 'o', 'k', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', 165, ' ', 'R', 'i', 'c', 'e', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
    {127, 'S', 'e', 'l', 'e', 'c', 't', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'}
  },
  {
    {' ', ' ', 'S', 'e', 'l', 'e', 'c', 't', ' ', 'a', 'n', ' ', 'o', 'p', 't', 'i', 'o', 'n', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'C', 'o', 'o', 'k', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', 165, ' ', 'B', 'r', 'i', 'g', 'a', 'd', 'e', 'i', 'r', 'o', ' ', ' ', ' ', ' ', '\0'},
    {127, 'S', 'e', 'l', 'e', 'c', 't', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'}
  },
  {
    {' ', ' ', 'S', 'e', 'l', 'e', 'c', 't', ' ', 'a', 'n', ' ', 'o', 'p', 't', 'i', 'o', 'n', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'H', 'e', 'a', 't', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', 165, 'P', 'i', 'z', 'z', 'a', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
    {127, 'S', 'e', 'l', 'e', 'c', 't', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'}
  },
  {
    {' ', ' ', 'S', 'e', 'l', 'e', 'c', 't', ' ', 'a', 'n', ' ', 'o', 'p', 't', 'i', 'o', 'n', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'T', 'h', 'a', 'w', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', 165, 'B', 'e', 'a', 'n', 's', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
    {127, 'S', 'e', 'l', 'e', 'c', 't', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'}
  },
  {
    {' ', ' ', 'S', 'e', 'l', 'e', 'c', 't', ' ', 'a', 'n', ' ', 'o', 'p', 't', 'i', 'o', 'n', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'T', 'h', 'a', 'w', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', 165, ' ', 'M', 'e', 'a', 't', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
    {127, 'S', 'e', 'l', 'e', 'c', 't', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'}
  },
  {
    {' ', ' ', 'S', 'e', 'l', 'e', 'c', 't', ' ', 'a', 'n', ' ', 'o', 'p', 't', 'i', 'o', 'n', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'T', 'h', 'a', 'w', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', ' ', 165, 'C', 'h', 'i', 'c', 'k', 'e', 'n', ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
    {127, 'S', 'e', 'l', 'e', 'c', 't', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'}
  },
  {
    {' ', ' ', 'S', 'e', 'l', 'e', 'c', 't', ' ', 'a', 'n', ' ', 'o', 'p', 't', 'i', 'o', 'n', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'T', 'i', 'p', 's', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', 165, ' ', 'L', 'i', 's', 't', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
    {127, 'S', 'e', 'l', 'e', 'c', 't', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'}
  },
  {
    {' ', ' ', 'S', 'e', 'l', 'e', 'c', 't', ' ', 'a', 'n', ' ', 'o', 'p', 't', 'i', 'o', 'n', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', '1', ':', '5', '0', 'g', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', '2', ':', '1', '0', '0', 'g', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
    {127, 'O', 'f', 'f', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'}
  },
  {
    {' ', ' ', 'S', 'e', 'l', 'e', 'c', 't', ' ', 'a', 'n', ' ', 'o', 'p', 't', 'i', 'o', 'n', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', ' ', '1', ':', '1', ' ', 'c', 'u', 'p', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', ' ', '2', ':', '2', ' ', 'c', 'u', 'p', 's', ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
    {127, 'O', 'f', 'f', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'}
  },
  {
    {' ', ' ', 'S', 'e', 'l', 'e', 'c', 't', ' ', 'a', 'n', ' ', 'o', 'p', 't', 'i', 'o', 'n', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', '1', ':', ' ', '1', ' ', 's', 'l', 'i', 'c', 'e', ' ', ' ', ' ', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', '2', ':', ' ', '1', '/', '2', ' ', 'p', 'i', 'z', 'z', 'a', ' ', ' ', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', '3', ':', ' ', '1', ' ', 'p', 'i', 'z', 'z', 'a', ' ', ' ', ' ', ' ', ' ', '\0'}
  },
  {
    {' ', ' ', ' ', ' ', ' ', ' ', 'T', 'i', 'p', 's', ' ', 'f', 'o', 'r', ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', 'e', 'a', 'c', 'h', ' ', 'p', 'o', 'w', 'e', 'r', ' ', ' ', ' ', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', 'a', 'n', 'd', ' ', 'c', 'l', 'e', 'a', 'n', 'i', 'n', 'g', ' ', ' ', ' ', ' ', '\0'},
    {127, 'O', 'f', 'f', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'O', 'n', 126, '\0'}
  },
  {
    {' ', ' ', ' ', ' ', 'P', 'r', 'e', 's', 's', ' ', 'O', 'f', 'f', ' ', 't', 'o', ' ', ' ', ' ', ' ', '\0'},
    {' ', ' ', ' ', 'l', 'e', 'a', 'v', 'e', ' ', 't', 'h', 'e', ' ', 'l', 'i', 's', 't', ' ', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
    {127, 'S', 'e', 'l', 'e', 'c', 't', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'}
  },
  {
    {' ', ' ', '1', ':', 'S', 'o', 'f', 't', 'e', 'n', ' ', 'b', 'u', 't', 't', 'e', 'r', ',', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', 'c', 'h', 'e', 'e', 's', 'e', ' ', 'a', 'n', 'd', ' ', ' ', ' ', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', 'i', 'c', 'e', ' ', 'c', 'r', 'e', 'a', 'm', ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
    {127, 'S', 'e', 'l', 'e', 'c', 't', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'}
  },
  {
    {' ', ' ', ' ', '2', ':', 'S', 'o', 'f', 't', 'e', 'n', ' ', 'f', 'o', 'o', 'd', 's', ' ', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', '3', ':', 'T', 'h', 'a', 'w', ' ', 'f', 'o', 'o', 'd', 's', ' ', ' ', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
    {127, 'S', 'e', 'l', 'e', 'c', 't', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'}
  },
  {
    {' ', ' ', ' ', '4', ':', ' ', 'S', 'l', 'o', 'w', 'l', 'y', ' ', 'c', 'o', 'o', 'k', ' ', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', 't', 'o', 'u', 'g', 'h', ' ', 'm', 'e', 'a', 't', ' ', ' ', ' ', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
    {127, 'S', 'e', 'l', 'e', 'c', 't', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'}
  },
  {
    {' ', '5', ':', 'T', 'h', 'a', 'w', ' ', 'r', 'e', 'a', 'd', 'y', ' ', 'm', 'e', 'a', 'l', 's', ' ', '\0'},
    {' ', '6', ':', 'S', 'o', 'u', 'p', 's', ' ', 'a', 'n', 'd', ' ', 'p', 'a', 's', 't', 'a', 's', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
    {127, 'S', 'e', 'l', 'e', 'c', 't', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'}
  },
  {
    {' ', ' ', '7', ':', 'P', 'o', 'u', 'l', 't', 'r', 'y', ',', ' ', 'c', 'a', 'k', 'e', 's', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', ' ', 'a', 'n', 'd', ' ', 'p', 'i', 'e', 's', ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
    {127, 'S', 'e', 'l', 'e', 'c', 't', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'}
  },
  {
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
    {' ', '8', ':', 'H', 'e', 'a', 't', ' ', 'r', 'e', 'a', 'd', 'y', ' ', 'm', 'e', 'a', 'l', 's', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
    {127, 'S', 'e', 'l', 'e', 'c', 't', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'}
  },
  {
    {' ', ' ', ' ', ' ', ' ', '9', ':', 'B', 'r', 'a', 'i', 's', 'i', 'n', 'g', ' ', ' ', ' ', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', 'a', 'n', 'd', ' ', 'm', 'e', 'a', 't', 's', ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
    {127, 'S', 'e', 'l', 'e', 'c', 't', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'}
  },
  {
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
    {' ', ' ', '1', '0', ':', 'B', 'o', 'i', 'l', ' ', 'a', 'n', 'd', ' ', 'c', 'o', 'o', 'k', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
    {127, 'S', 'e', 'l', 'e', 'c', 't', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'}
  },
  {
    {'C', ':', 'B', 'e', 'f', 'o', 'r', 'e', ' ', 'F', 'a', 'n', ' ', 'o', 'n', ',', ' ', 'p', 'u', 't', '\0'},
    {' ', 'a', ' ', 'c', 'u', 'p', ' ', 'o', 'f', ' ', 'w', 'a', 't', 'e', 'r', ' ', 'a', 'n', 'd', ' ', '\0'},
    {'l', 'e', 'm', 'o', 'n', ' ', 't', 'o', ' ', 'b', 'o', 'i', 'l', ' ', '(', '3', 'm', 'i', 'n', ')', '\0'},
    {127, 'S', 'e', 'l', 'e', 'c', 't', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'}
  },
  {
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', 'F', 'a', 'n', ' ', 'o', 'n', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
  },
  {
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'}
  },
  {
    {' ', ' ', ' ', 'C', 'l', 'o', 's', 'e', ' ', 't', 'h', 'e', ' ', 'd', 'o', 'o', 'r', ' ', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', ' ', 'C', 'o', 'n', 'f', 'i', 'r', 'm', 33 , ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'}
  }
};

char lcd_clock[5][6] = {
  {' ', ' ', ' ', ' ', ' ', '\0'},
  {'T', 'i', 'm', 'e', 235, '\0'},
  {' ', ' ', ' ', ' ', '#', '\0'},
  {'*', ' ', ' ', ' ', ' ', '\0'},
  {'*', ' ', ' ', ' ', '#', '\0'}
};

#endif