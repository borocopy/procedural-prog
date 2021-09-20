#include <fstream>
#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

// Задача 1
int euqlid_div(int a, int b) {
  while (a * b != 0) {
    if (a > b) {
      a = a % b;
    } else {
      b = b % a;
    }
  }

  return a + b;
}

int euqlid_diff(int a, int b) {
  while (a != b) {
    if (a > b) {
      a = a - b;
    } else {
      b = b - a;
    }
  }

  return a;
}

int q1() {
  int a, b;
  int ans;
  cout << "Введите через пробел два натуральных числа a и b:"
       << "\n";
  if (cin >> a >> b) {
    if (a < 0 || b < 0) {
      cout << "Я работаю только с натуральными числами!"
           << "\n";

      return 0;
    }

    ans = euqlid_div(a, b);
    cout << ans << "\n";
    ans = euqlid_diff(a, b);
    cout << ans << "\n";

  } else {
    cout << "Некорректные входные данные"
         << "\n";
  }

  return 0;
}

// Задача 2
bool isPrime(int a) {
  for (int i = 2; i < (int)sqrt(a) + 1; i++) {
    if (a % i == 0)
      return 0;
  }

  return 1;
}

int q2() {
  int a;
  cout << "Введите натуральное число"
       << "\n";

  if (cin >> a) {
    if (a < 1) {
      cout << "Я работаю только с натуральными числами!"
           << "\n";
      return 0;
    }

    for (int i = 2; i < a; i++) {
      if (isPrime(i))
        cout << i << " ";
    }
    cout << "\n";

  } else {
    cout << "Некорректные входные данные"
         << "\n";
  }

  return 0;
}

// Задача 3 (номер 4)
int q3_4() {
  ifstream fin;
  fin.open("text.txt");
  string str;
  int max_l = 0;
  string max_w = "";

  if (!fin.is_open()) {
    cout << "Ошибка"
         << "\n";
    return 0;
  }

  while (fin >> str) {
    int l = (int)str.length();
    if (str[str.length() - 1] > 31 && str[str.length() - 1] < 48) {
      l--;
      str.resize(str.size() - 1);
    }

    if (l > max_l) {
      max_l = l;
      max_w = str;
    }
  }
  cout << "Слово " << max_w << " обладает максимальной длиной в тексте "
       << max_l << "\n";
  fin.close();
  return 0;
}

// Задача 3 (номер 32)
char moveABC(char a, uint16_t move) {
  char r;
  if (a == 'Z' || a == 'z') {
    r = (char)((int)a - 26 + move);
  } else {
    r = (char)((int)a + move);
  }

  return r;
}

int q3_32() {

  size_t step;
  ifstream fin;
  fin.open("text.txt");
  ofstream fout;
  fout.open("text_transformed.txt");
  char ch;
  int max_l = 0;

  if (!fin.is_open()) {
    cout << "Ошибка"
         << "\n";
    return 0;
  }
  cout << "Введите число на сколько букв сдвинуть текст:"
       << "\n";
  if (cin >> step) {
    if (step < 0) {
      cout << "Вводите только натуральное число!!!"
           << "\n";

      return 0;
    }
    while (fin.get(ch)) {
      if ((ch > 64 && ch < 91) || (ch > 96 && ch < 123)) {
        ch = moveABC(ch, step);
      }
      fout << ch;
    }
  } else {
    cout << "Некорректные входные данные"
         << "\n";
  }

  fin.close();
  fout.close();
  return 0;
}

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

  cout << "Введите натуральное число n"
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
  // q1();
  // q2();
  // q3_4();
  // q3_32();
  // q4_4();
  // q4_34();
  return 0;
}