#include <fstream>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
using namespace std;

// Задача 1
int q1() {
  double S, p, n;
  cout << "Введите через пробел тело займа S, процент годовых p и срок n "
          "(кол-во лет)"
       << "\n";
  if (cin >> S >> p >> n) {
    if (S * p * n <= 0 || (int)n != n) {
      cout << "Некорректные входные данные!"
           << "\n";
      return 0;
    }

    double r = p / 100.0;
    double m = (S * r * pow(1 + r, n)) / (12 * ((pow(1 + r, n) - 1)));

    cout << "Месячная выплата по займу m = " << m << "\n";
  } else
    cout << "Некорректные входные данные!"
         << "\n";

  return 0;
}

// Задача 2

double find_m(double S, double p, double n) {
  double r = p / 100.0;
  double m = (S * r * pow(1 + r, n)) / (12 * ((pow(1 + r, n) - 1)));

  return m;
}

int q2() {
  double S, p, n, m;

  cout << "Введите через пробел тело ссуды S, месячную выплату m и срок n "
          "(кол-во лет)"
       << "\n";

  if (cin >> S >> m >> n) {
    if (S * m * n <= 0 || (int)n != n) {
      cout << "Некорректные входные данные!"
           << "\n";
      return 0;
    }

    for (double i = 0.1; i < 100; i += 0.1) {
      double r = i / 100.0;
      if (abs(find_m(S, p, n) - m) < 1 || find_m(S, p, n) > m) {
        p = i;
        break;
      }
    }

    cout << "Процент годовых p = " << p << "\n";

    return 0;
  } else {
    cout << "Некорректные входные данные!"
         << "\n";
  }

  return 0;
}

int q3() {

  string input;
  getline(cin, input);

  ofstream fout;
  fout.open("./text.txt");
  fout << input << "\n";

  fout.close();

  fstream fin("./text.txt", ios::in);

  string ans = "";
  char ch;

  while (fin >> ch && !fin.eof()) {
    ans += ch;
  }

  cout << ans << "\n";
  fin.close();

  return 0;
}

// Задача 4
int q4() {
  fstream fin("./text.txt", ios::in);
  if (!fin) {
    cout << "Файла text.txt не существует"
         << "\n";

    return 0;
  }

  char ch;
  string ans = "";

  while (fin >> ch && !fin.eof()) {
    if ((ch >= 48) && (ch <= 57)) {
      ans += ch;
    }
  }

  cout << ans << "\n";
  fin.close();
  return 0;
}

// Задача 5
bool isCapital(char a) {
  if (a >= 65 && a <= 90)
    return true;
  else
    return false;
}

char normalizeLetter(char a) {
  if (isCapital(a)) {
    return a + (97 - 65);
  }

  else
    return a;
}

int q5() {
  string a = "asdfghjklxcvbnmrtyasdfgABhbnmrty";
  char buf;
  for (int i = 0; i < 30; i++) {
    for (int j = 0; j < 30; j++) {
      if (normalizeLetter(a[i]) < normalizeLetter(a[j])) {
        buf = a[j];
        a[j] = a[i];
        a[i] = buf;
      }
    }
  }

  cout << a << "\n";
  return 0;
}

int main() {
  setlocale(0, "");
  q1();
  q2();
  // q3();
  // q4();
  // q5();
}