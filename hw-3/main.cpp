#include <fstream>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
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

    for (double i = 0.001; i < 100; i += 0.1) {
      if (find_m(S, i, n) > m) {
        p = i;
        break;
      }
    }

    cout << "Процент годовых p = " << p - 0.001 << "\n";

    return 0;
  } else {
    cout << "Некорректные входные данные!"
         << "\n";
  }

  return 0;
}

int q3() {

  string input;
  cout << "Введите строку, которая будет помещена в файл text.txt" << endl;
  getline(cin, input);

  ofstream fout;
  fout.open("./text.txt");
  fout << input << endl;

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
  bool isDouble = false;
  bool isNegative = false;
  string buf = "";
  vector<double> nums;

  // while(getline(fin,))

  while (fin >> ch && !fin.eof()) {
    cout << ch << endl;
    if ((ch == ' ') || (ch == '\n') || (ch == '\t')) {
      buf = "";
      continue;
    }
    if (buf == "" && ch == '-' && !isNegative) {
      buf = "-";
      isNegative = true;
      continue;
    }
    if (ch == ',' && !isDouble) {
      buf += ",";
      isDouble = true;
      continue;
    }

    if (((ch >= 48) && (ch <= 57))) {
      buf += ch;
    } else {
      if (buf != "" && buf != "-" && buf[0] != ',') {
        isDouble = false;
        isNegative = false;
        nums.push_back(stod(buf));
      }
      if (ch == '-') {
        buf = "-";
      } else {
        buf = "";
      }
    }
  }

  if (buf != "")
    nums.push_back(stod(buf));

  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << " ";
  }
  cout << endl;
  fin.close();
  return 0;
}

// Задача 5 !
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
  cout << "Введите строку длиной в 30 символов (на латинице):" << endl;
  string a;
  getline(cin, a);

  if (a.size() > 30) {
    cout << "Введите 30 символов!!!"
         << "\n";
    return 0;
  }

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
  // q1();
  // q2();
  // q3();
  q4();
  // q5();
}