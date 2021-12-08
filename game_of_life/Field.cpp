#include "Field.h"

Field::Field(char symbol) {
  char bacteriaSymbol = generateRandomSymbol();
  ;
}

char Field::generateRandomSymbol() {
  std::string pool = "#$%^&*!<>?/";
  return pool[rand() % pool.length()];
}