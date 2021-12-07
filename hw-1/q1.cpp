#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

// Задача 1

int q1() {
  string a = "Меня зовут Денис!!!";

  cout << a << "\n";
  return 0;
}

// Задача 2
int q2() {

  float a, b;

  cout << "Введите два числа a и b:"
       << "\n";
  if (cin >> a >> b) {
    cout << "\n a + b = " << a + b << "\n a - b = " << a - b
         << "\n a * b = " << a * b << "\n";
    if (b != 0) {
      cout << "a / b = " << a / b << "\n";
    }

  } else {
    cout << "Некорректный ввод"
         << "\n";
  }

  return 0;
}

// Задача 3
int q3() {
  float b, c;
  cout << "Введите числа b и c уравнения вида bx + c = 0:"
       << "\n";
  if (cin >> b >> c) {
    if ((b == 0) && (c == 0)) {
      cout << "x - любое число"
           << "\n";
    } else if (b == 0) {
      cout << "Нет решений"
           << "\n";
    } else {
      cout << "x = " << -c / b << "\n";
    }
  } else {
    cout << "Некорректный ввод"
         << "\n";
  }
  return 0;
}

// Задача 4
int q4() {
  float a, b, c;
  cout << "Введите числа a, b и с уравнения вида ax^2 + bx + c = 0"
       << "\n";
  if (cin >> a >> b >> c) {
    if (a == 0) {
      if (b == 0 && c == 0) {
        cout << "x - любое число"
             << "\n";
      } else if (b == 0) {
        cout << "Нет решений"
             << "\n";
      } else {
        cout << "x = " << -c / b << "\n";
      }
    } else {
      float D = b * b - 4 * a * c;

      if (D < 0) {
        cout << "Нет решений"
             << "\n";
      }

      if (D == 0) {
        cout << "x = " << -b / (2 * a) << "\n";
      }

      if (D > 0) {
        cout << "x принадлежит множеству { " << (-b + sqrt(D)) / 2 * a << ", "
             << (-b - sqrt(D)) / 2 * a << " }\n";
      }
    }
  } else {
    cout << "Некорректный ввод"
         << "\n";
  }

  return 0;
}

// Задача 5

int q5() {
  bool isDay, isOpen, isLamp;
  bool isVisible = false;

  cout << "Введите через пробел данные о состоянии дня и комнаты (1 - да, 0 - "
          "нет): На улице день? Шторы открыты? Лампа включена?"
       << "\n";
  if (cin >> isDay >> isOpen >> isLamp) {

    if (isDay && isOpen)
      isVisible = true;
    if (isLamp)
      isVisible = true;

    if (isVisible) {
      cout << "В комнате светло!"
           << "\n";
    } else {
      cout << "В комнате темно ;("
           << "\n";
    }
  }

  return 0;
}

int main() {
  setlocale(0, "");
  q1();
  q2();
  q3();
  q4();
  q5();

  return 0;
}