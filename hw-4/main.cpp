#include <fstream>
#include <iostream>
#include <math.h>
#include <sstream>
#include <stdio.h>
#include <string.h>

using namespace std;
void testVar(void *v) { cout << v << "\n"; }
// Задача 1
int q1() {
  ofstream fout;
  fout.open("q1.txt");
  fout << "0 1 2 3 4 5 6 7 8 9"
       << "\n";
  fout.close();

  fstream fin("q1.txt", ios::in);

  if (!fin) {
    cout << "Файла q1.txt не существует"
         << "\n";

    return 0;
  }

  int i;
  int sum = 0;

  while (fin >> i && !fin.eof()) {
    sum += i;
  }

  fin.close();
  cout << sum << "\n";

  return 0;
}

// Задача 2
int q2() {
  int a;
  cout << "Введите число:"
       << "\n";

  if (cin >> a) {
    int ans = abs(a) == a ? 1 : -1;
    if (a == 0)
      ans = 0;

    cout << ans << "\n";
  } else {
    cout << "Некорректные входные данные"
         << "\n";
  }

  return 0;
}

// Задача 3
double rect_sq(double a, double b) { return a * b; }

double trig_sq(double a, double h) { return a * h / 2.0; }

double circle_sq(double r) { return 3.14159 * r * r; }

// Задача 4
int q4() {
  fstream fin("flag.txt", ios::in);
  char c;
  int counter = 1;
  while (fin >> c && !fin.eof()) {
    cout << c;
    if (counter % 47 == 0)
      cout << "\n";
    counter++;
  }

  fin.close();

  return 0;
}

// Задача 5
int q5() {
  fstream fin("sin.txt", ios::in);
  int counter = 1;
  string line;
  while (getline(fin, line) && !fin.eof()) {
    cout << line << "\n";
  }

  fin.close();

  return 0;
}

// Задача 6
int parseValue(char v) {
  switch (v) {
  case 'I':
    return 1;
  case 'V':
    return 5;
  case 'X':
    return 10;
  case 'L':
    return 50;
  case 'C':
    return 100;
  case 'D':
    return 500;
  case 'M':
    return 1000;
  }

  return -1;
}
int q6() {
  string a;
  cout << "Введите число в римской записи:"
       << "\n";
  if (cin >> a) {
    int ans = 0;
    for (int i = 0; i < a.length(); i++) {
      int v1 = parseValue(a[i]);

      if (v1 == -1) {
        cout << "Некорректные входные данные!"
             << "\n";
        return 0;
      }

      if (i + 1 < a.length()) {
        int v2 = parseValue(a[i + 1]);
        if (v1 >= v2) {
          ans += v1;
        } else {
          ans += v2 - v1;
          i++;
        }
      } else {
        ans += v1;
      }
    }

    cout << a << " = " << ans << "\n";
  } else {
    cout << "Некорректные входные данные!"
         << "\n";
  }

  return 0;
}

// Задача 7
int s(int i) {
  if (i == 0)
    return 0;

  return (25173 * s(i - 1) + i) % 65537;
}

int q7() {
  cout << s(13849) << "\n";
  return 0;
}

// Задача 8 @TODO: доделать

int q8() {
  double m1[3][4] = {{5, 2, 0, 10}, {3, 5, 2, 5}, {20, 0, 0, 0}};
  double m2[4][2] = {{1.20, 0.5}, {2.8, 0.4}, {5, 1}, {2, 1.5}};
  double mf[3][2];

  // Заполнение нулями матрицы произведения
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      mf[i][j] = 0;
    }
  }

  // Перемножение матриц
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 2; k++) {
        mf[i][k] += m1[i][j] * m2[j][k];
      }
    }
  }

  // Вывод матрицы
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      cout << mf[i][j] << " ";
    }
    cout << "\n";
  }

  // Большие деньги
  cout << "Пункт а)"
       << "\n";
  double maxMoney = 0;
  double minMoney = 1000;
  int topSeller = 0;
  int botSeller = 0;
  for (int i = 0; i < 3; i++) {
    double cur = mf[i][0];
    if (maxMoney < cur) {
      maxMoney = cur;
      topSeller = i + 1;
    }

    if (minMoney > cur) {
      minMoney = cur;
      botSeller = i + 1;
    }
  }
  printf("Больше всех денег выручил продавец %d с продажами %.2f\n", topSeller,
         maxMoney);
  printf("Меньше всех денег выручил продавец %d с продажами %.2f\n", botSeller,
         minMoney);

  // Большие комиссионные
  cout << "Пункт b)"
       << "\n";
  double maxKom = 0;
  double minKom = 1000;
  int topKom = 0;
  int botKom = 0;
  for (int i = 0; i < 3; i++) {
    double cur = mf[i][1];
    if (maxKom < cur) {
      maxKom = cur;
      topKom = i + 1;
    }

    if (minKom > cur) {
      minKom = cur;
      botKom = i + 1;
    }
  }
  printf("Больше всего комиссионных получил продавец %d размером %.2f\n",
         topKom, maxKom);
  printf("Меньше всего комиссионных получил продавец %d размером %.2f\n",
         botKom, minKom);

  // Общая сумма прибыли
  cout << "Пункт c)" << endl;
  double moneySum = 0;
  for (int i = 0; i < 3; i++) {
    moneySum += mf[i][0];
  }

  printf("Общая сумма денег, заработанных продавцами - %.2f\n", moneySum);

  // Общая сумма комиссионных
  cout << "Пункт d)" << endl;
  double comSum = 0;
  for (int i = 0; i < 3; i++) {
    comSum += mf[i][1];
  }

  printf("Общая сумма комиссионных, полученных продавцами - %.2f\n", comSum);

  // Общая сумма денег
  cout << "Пункт e)" << endl;
  printf("Общая сумма комиссионных, полученных продавцами - %.2f\n",
         moneySum + comSum);

  return 0;
}

// Задание 9

int letterToInt(char sym) {
  if ((int)sym > 57) {
    return (int)(sym)-55;
  }
  return (int)(sym)-48;
}
char intToLetter(int N) {
  if (N > 9) {
    return (char)(N + 55);
  }
  return (char)(N + 48);
}

int fromBaseToDecimal(string N, unsigned int base) {
  string str = N;
  int ans = 0;

  for (size_t i = 0; i < str.length(); i++) {
    ans += letterToInt(str[str.length() - 1 - i]) * pow(base, i);
  }
  return ans;
}

string fromDecimalToBase(int N, unsigned int base) {
  string ans = "";

  while (N >= base) {
    int buf = N % base;
    ans += intToLetter(buf);
    N /= base;
  }
  ans += intToLetter(N % base);
  // ans += intToLetter(N / base);

  reverse(ans.begin(), ans.end());
  return ans;
}

int q9() {
  string bN;
  unsigned int bBase, eBase;
  cout << "Введите через пробел число, основание его системы счисления и "
          "основание системы счисления, в которую его надлежит перевести"
          "(основание системы счисления от 2 до 42 (только заглавные буквы "
          "латиницы))"
       << "\n";

  if (cin >> bN >> bBase >> eBase) {
    for (int i = 0; i < bN.length(); i++) {
      if (bN[i] == '.') {
        cout << "Я умею работать только с целыми числами!!!!"
             << "\n";
        return 0;
      }

      if (letterToInt(bN[i]) >= bBase) {
        cout << "Вы ввели число в системе счисления с другим основанием!!!"
             << "\n";
        return 0;
      }
    }
    if ((int)bBase != bBase || (int)eBase != eBase) {
      cout << "Я умею работать только с целыми числами!!!!"
           << "\n";

      return 0;
    }

    if (bBase < 2 || bBase > 42 || eBase < 2 || eBase > 42) {
      cout << "Основание системы счисления - натуральное число от 2 до 42!!!"
           << "\n";

      return 0;
    }

    if (bN[0] == '-') {
      cout << "-";
      bN.erase(0, 1);
    }

    cout << fromDecimalToBase(fromBaseToDecimal(bN, bBase), eBase) << "\n";

  } else {
    cout << "Некорректный ввод данных!!!"
         << "\n";
  }

  return 0;
}

int main() {
  setlocale(0, "");
  // q1();
  // q2();
  // q4();
  // q5();
  // q6();
  // q7();
  q8();
  // q9();

  return 0;
}
