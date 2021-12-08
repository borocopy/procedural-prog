#include <iostream>
#include <utility>

using namespace std;

uint32_t generateRandomNumber() { return rand() % 9000 + 1000; }

pair<uint32_t, uint32_t> processInput(string computed, string guessed) {
  pair<uint32_t, uint32_t> res(0, 0);

  for (size_t i = 0; i < computed.length(); i++) {
    if (computed[i] == guessed[i]) {
      res.first++;
      // cout << (computed[i]) << endl;
      computed.erase(i, 1);
      guessed.erase(i, 1);
      i--;
    }
  }

  for (size_t i = 0; i < guessed.length(); i++) {
    if (computed.find(guessed[i]) != string::npos) {
      res.second++;
    }
  }

  return res;
}

bool checkInput(string &a) {
  if (a.length() != 4)
    return 0;
  for (size_t i = 0; i < a.length(); i++) {
    if ((a[i] - '0' < 0) || (a[i] - '0' > 9)) {
      return 0;
    }
  }

  return 1;
}

int main() {
  srand(time(NULL));
  setlocale(0, "");
  string buf = "";
  string init_n = to_string(generateRandomNumber());
  cout << init_n << endl;
  cout << "Компьютер загадал некоторое четырехзначное число. Попробуйте "
          "отгадать его!"
       << endl;

  while (true) {
    cout << "Введите число:" << endl;
    getline(cin, buf);
    if (!checkInput(buf)) {
      cout << "Некорректный ввод! Введите четырехзначное число!" << endl;
      continue;
    }

    pair<uint32_t, uint32_t> res = processInput(init_n, buf);

    if (res.first == 4) {
      cout << "Вы угадали число!!! Это было число – " << init_n << endl;
      break;
    } else {
      cout << "Отгадано цифр на своих местах (+): " << res.first << endl;
      cout << "Отгадано цифр не на своих местах (-): " << res.second << endl;
    }
  }

  return 1;
}