#include <conio.h>
#include <fstream>
#include <iostream>
#include <math.h>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <windows.h>

using namespace std;
void testVar(void *v) { cout << v << "\n"; }
// Задача 1
bool isDigit(char a) {
  if (a - '0' >= 0 && a - '0' <= 9)
    return true;
  return false;
}

int q1() {
  ofstream fout;
  vector<int> a;
  for (int i = 0; i < 9; i++) {
    string buf;
    if (cin >> buf) {
      for (size_t i = 0; i < buf.length(); i++) {
        if (!isDigit(buf[i])) {
          cout << "Некорректный ввод!"
               << "\n";
          return 0;
        }
      }

      a.push_back(stoi(buf));
    } else {
      cout << "Некорректный ввод!"
           << "\n";

      return 0;
    }
  }
  fout.open("q1.txt");
  for (size_t i = 0; i < a.size(); i++) {
    fout << a[i] << " ";
  }
  fout << endl;
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
  hwnd hwnd = getconsolewindow();
  hdc hdc = getdc(hwnd);
  int x = 10;

  hpen hpen;
  hbrush b1, b2 = createsolidbrush(rgb(0, 0, 0));

  int height = 30;
  int width = 0;
  for (int i = 0; i < 7; i++) {
    selectobject(hdc, createsolidbrush(rgb(255, 0, 0)));
    rectangle(hdc, 60, 550, 1000, height);
    height += 40;
    selectobject(hdc, createsolidbrush(rgb(255, 255, 255)));
    rectangle(hdc, 60, 550, 1000, height);
    height += 40;
  }
  selectobject(hdc, createsolidbrush(rgb(0, 0, 255)));
  rectangle(hdc, 60, 311, 480, 30);
  height = 30;
  selectobject(hdc, createsolidbrush(rgb(255, 255, 255)));
  int md = 70;
  int mw = 80;
  for (int j = 0; j < 5; j++) {
    int widthel = 85;
    int heightel = 95;
    for (int i = 0; i < 6; i++) {
      ellipse(hdc, heightel, md, widthel, mw);
      heightel += 72;
      widthel += 72;
    }
    md += 48;
    mw += 48;
  }
  int sd = 95;
  int sw = 105;
  for (int j = 0; j < 4; j++) {
    int widthel2 = 123;
    int heightel2 = 133;
    for (int i = 0; i < 5; i++) {
      ellipse(hdc, heightel2, sd, widthel2, sw);
      heightel2 += 72;
      widthel2 += 72;
    }
    sd += 48;
    sw += 48;
  }
  std::cin.ignore();

  return 0;
}

// Задача 5
int q5() {
  HWND hwnd = GetConsoleWindow();
  HDC hdc = GetDC(hwnd);
  int x = 10;

  HPEN p1, p2 = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
  HBRUSH b1, b2 = CreateSolidBrush(RGB(255, 255, 255));
  p1 = (HPEN)SelectObject(hdc, p2);
  b1 = (HBRUSH)SelectObject(hdc, b2);

  // cout << "y = sin x";
  for (float i = 7; i < 93; i += 1) {
    SetPixel(hdc, 323, i, RGB(255, 255, 255));
  }
  for (float i = 0; i < 3.14 * 10; i += 0.05) {
    SetPixel(hdc, x, 50 + 25 * sin(i), RGB(255, 255, 255));
    SetPixel(hdc, x, 50, RGB(255, 255, 255));
    x += 1;
  }

  std::cin.ignore();

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

bool isRomanCorrect(string &a) {
  char lv = a[0];
  size_t count = 0;
  for (size_t i = 0; i < a.length(); i++) {
    char cv = a[i];
    if (lv == cv) {
      count += 1;
      if (count == 3)
        return 0;
    } else {
      count = 0;
    }

    lv = cv;
  }

  return 1;
}

int q6() {
  string a;
  cout << "Введите число в римской записи:"
       << "\n";
  if (cin >> a) {
    if (!isRomanCorrect(a)) {
      cout << "Некорректные входные данные! Три одинаковых символа не могут "
              "идти подряд!"
           << endl;
      return 1;
    }
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
  // q8();
  q9();

  return 0;
}
