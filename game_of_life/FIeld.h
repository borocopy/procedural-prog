#include <iostream>
#include <utility>

class Field {
public:
  uint64_t iteration;
  char bacteriaSymbol;

  Field(char bacteriaSymbol);
  void generateInitConditions();

private:
  char generateRandomSymbol();
};