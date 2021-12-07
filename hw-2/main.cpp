#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

// Задача 1

int q1() {
  double R, r, h;

  cout << "Введите через пробел радиус нижнего основания, радиус верхнего "
          "основания и высоту усеченной пирамиды:"
       << "\n";
  if (cin >> R >> r >> h) {
    if (R * r * h < 0) {
      cout << "Все значения должны быть положительными!"
           << "\n";
      return 0;
    }
    double V = (double)(1.0 / 3.0) * (3.14159) * h * (R * R + R * r + r * r);
    double l = sqrt(pow(R - r, 2) + h * h);
    double S = (3.14159) * (R * R + (R + r) * l + r * r);

    cout << "V = " << V << ", S = " << S << "\n";
  } else
    cout << "Некорректный ввод"
         << "\n";

  return 0;
}

// Задача 2

int q2() {
  double x, a, ans;
  cout << "Введите через пробел числа a и x для вычисления значения функции w:"
       << "\n";
  if (cin >> a >> x) {
    if (abs(x) < 1) {
      if (abs(x) == 0) {
        cout << "Функция не определена при x = 0"
             << "\n";
        return 0;
      }

      ans = a * log(abs(x));
    } else {
      if (a - pow(x, 2) < 0) {
        cout << "Функция не определена при данных значениях x и a"
             << "\n";
        return 0;
      }

      ans = sqrt(a - pow(x, 2));
    }

    cout << "w = " << ans << "\n";

  } else {
    cout << "Некорректный ввод"
         << "\n";
  }
  return 0;
}

// Задача 3

int q3() {
  double x, y, b;
  cout << "Введите числа x, y и b для вычисления функции z=ln(b-y)*sqrt(b-x)"
       << "\n";
  if (cin >> x >> y >> b) {
    if (((b - y) < 0) || ((b - x) <= 0)) {
      cout << "Функция не определена в этой точке при учете входных данных"
           << "\n";
      return 0;
    }

    double z = log(b - y) * sqrt(b - x);

    cout << "z = " << z << "\n";

  } else {
    cout << "Некорректный ввод"
         << "\n";
  }

  return 0;
}

// Задача 4

int q4() {
  double n;
  cout << "Введите произвольное число N"
       << "\n";

  if (cin >> n) {
    int start = n;
    if ((int)n != n)
      start = (int)n + 1;
    if (n <= 0)
      start = 1;
    for (int i = start; i < start + 10; i++) {
      cout << i << " ";
    }

    cout << "\n";
  } else {
    cout << "Некорректный ввод!"
         << "\n";
  }

  return 0;
}

// Задача 5

double y(double x) { return (pow(x, 2) - 2 * x + 2) / (x - 1); }

int q5() {
  cout << "| x \t| y"
       << "\n";
  for (double i = -4; i <= 4; i += 0.5) {

    if (i == 1) {
      cout << "| 1 \t| не определена\n";
    } else {
      cout << "| " << i << " \t| " << y(i) << "\n";
    }
  }
  cout << "\n";

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