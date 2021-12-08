#include <iostream>
#include <utility>

#define INPUTFILE "work.dat"
#define OUTPUTFILE "work.out"

class Field {
public:
  uint64_t iteration;
  char bacteriaSymbol;
  Field(char bacteriaSymbol);
  void generateInitConditions();

private:
};

Field::Field(char symbol) { char bacteriaSymbol = symbol; }

int main() {}