#include "Bacteria.h"

Bacteria::Bacteria(char bacteriaSymbol) {
  symbol = bacteriaSymbol;
  life = 1;
}

void Bacteria::progress() {
  life++;
  if (life == 12)
    life = 0;
}

uint16_t Bacteria::getLife() { return life; }