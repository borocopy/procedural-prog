#include <fstream>
#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

// Задача 4 (номер 4)
unsigned long factorial(unsigned int n) {
  unsigned long f = 1;
  for (uint32_t i = 1; i <= n; i++) {
    f *= i;
  }

  return f;
}

double eval_expr(uint32_t k) {
  long double f = 0;

  for (uint32_t i = 1; i <= k; i++) {
    if (i % 2 != 0) {
      f += 1.0 / (double)(i);
    } else {
      f -= 1.0 / (double)(i);
    }
  }

  return (double)(factorial(k)) / f;
}

int q4_4() {
  int n;

  cout << "Введите натуральное число k"
       << "\n";

  if (cin >> n) {
    if (n < 1) {
      cout << "Введите натуральное число!"
           << "\n";
      return 0;
    }

    long double f = 0;

    for (int i = 1; i <= n; i++) {
      f += eval_expr(i);
    }

    cout << f << "\n";

  } else {
    cout << "Некорректный ввод"
         << "\n";
  }

  return 0;
}

int q4_34() {
  string s;
  string f = "студенчво";
  if (getline(cin, s)) {
    for (size_t i = 0; i < s.length(); i++) {
      for (size_t j = 0; j < f.length(); j++) {
        if (s[i] == f[j]) {
          f.erase(j, 1);
        }
      }
    }

    if (f.length() == 0) {
      cout << "Да, в этой строке содержатся все символы, что есть в слове "
              "'студенчество'"
           << "\n";
    } else {
      cout << "Нет, в этой строке не содержатся все символы, что есть в слове "
              "'студенчество'"
           << "\n";
    }
  } else {
    cout << "Некорректный ввод"
         << "\n";
  }

  return 0;
}

int main() {
  setlocale(0, "");
  // q4_4();
  // q4_34();
  return 0;
}