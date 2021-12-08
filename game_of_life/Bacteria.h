#include <stdlib.h>

class Bacteria {
private:
  uint16_t life;
  char symbol;

public:
  Bacteria(char symbol);
  virtual ~Bacteria();
  void progress();
  uint16_t getLife();
};