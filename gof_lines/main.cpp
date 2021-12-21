#include <chrono>
#include <ctime>
#include <fstream>
#include <iostream>
#include <thread>

#define SIZE 50

// 1 - 12 –– alive cell;
// 0 –– dead cell;

using namespace std;

char cellSymbol;
char field[SIZE][SIZE];
int16_t currentGen[SIZE][SIZE];
int16_t nextGen[SIZE][SIZE];

char generateRandomChar(uint16_t power) {
  char n = rand() % power + 97;
  return n;
}

void generateInitField(uint16_t power) {
  cellSymbol = generateRandomChar(power);
  for (int16_t i = 0; i < SIZE; i++) {
    for (int16_t j = 0; j < SIZE; j++) {
      char buf = generateRandomChar(power);
      field[i][j] = buf;
    }
  }
}

void writeInitField() {
  ofstream fout;
  fout.open("work.dat", ios::out);

  for (int16_t i = 0; i < SIZE; i++) {
    for (int16_t j = 0; j < SIZE; j++) {
      fout << field[i][j] << ' ';
    }
    fout << endl;
  }

  fout.close();
}

int16_t getCellNextState(int16_t y, int16_t x) {
  int16_t result = currentGen[y][x];
  int16_t neighboursCount = 0;

  for (int16_t mY = -1; mY < 2; mY++) {
    int16_t yPos = y + mY;
    if (yPos < 0 || yPos > SIZE - 1)
      continue;
    for (int16_t mX = -1; mX < 2; mX++) {
      int16_t xPos = x + mX;
      if (xPos < 0 || xPos > SIZE - 1 || (mX == 0 && mY == 0))
        continue;

      if (currentGen[yPos][xPos] > 0) {
        neighboursCount++;
      }
    }
  }

  if (result == 0 && neighboursCount == 3) {
    result = 1;
  } else if (result > 0 && result < 12 &&
             (neighboursCount == 2 || neighboursCount == 3)) {
    result += 1;
  } else {
    result = 0;
  }
  return result;
}

int16_t getNextGen() {
  int16_t sum = 0;
  for (int16_t i = 0; i < SIZE; i++) {
    for (int16_t j = 0; j < SIZE; j++) {
      nextGen[i][j] = getCellNextState(i, j);
      sum += nextGen[i][j];
    }
  }

  return sum;
}

void parseInitField() {
  for (int16_t i = 0; i < SIZE; i++) {
    for (int16_t j = 0; j < SIZE; j++) {
      currentGen[i][j] = (field[i][j] == cellSymbol) ? 1 : 0;
    }
  }
}

void writeOutput() {

  ofstream fout;
  string fileName = "work.out";
  fout.open(fileName, ios::out);

  for (int16_t i = 0; i < SIZE; i++) {
    for (int16_t j = 0; j < SIZE; j++) {
      fout << (char)(currentGen[i][j] > 0 ? '+' : ' ') << ' ';
    }
    fout << endl;
  }
  fout.close();
}

void printGenerationToConsole(int16_t i) {
  cout << "\x1B[2J\x1B[H" << endl;
  cout << "Итерация номер - " << i << endl;
  for (int16_t i = 0; i < SIZE; i++) {
    for (int16_t j = 0; j < SIZE; j++) {
      cout << (currentGen[i][j] > 0 ? "+" : " ") << ' ';
    }

    cout << endl;
  }
}

int main() {
  setlocale(0, "");
  uint16_t n, power;
  int16_t i = 0;
  cout << "Введите мощность алфавита (2-26):" << endl;
  cin >> power;
  cout << "Введите количество итераций:" << endl;
  cin >> n;
  srand((unsigned)time(NULL));
  generateInitField(power);
  cout << "Бактерия находится под символом – " << cellSymbol << endl;
  writeInitField();
  parseInitField();
  for (i = 0; i < n; i++) {
    printGenerationToConsole(i);
    this_thread::sleep_for(chrono::milliseconds(1000));
    bool isAnyAlive = getNextGen() > 0 ? 1 : 0;
    swap(currentGen, nextGen);
    if (!isAnyAlive) {
      break;
    }
  }
  printGenerationToConsole(i);
  writeOutput();
  return 0;
}