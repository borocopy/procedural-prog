#include <iostream>
using namespace std;

const int MAX = 1000;

uint64_t f[93] = {0};

/*
  Если n - четное, то k = n/2:
  F(n) = [2*F(k-1) + F(k)]*F(k)

  Если n - нечетное, то k = (n + 1)/2
  F(n) = F(k)*F(k) + F(k-1)*F(k-1)
*/

uint64_t fib(uint64_t n) {
  if (n == 0)
    return 0;
  if (n == 1 || n == 2)
    return (f[n] = 1);

  if (f[n])
    return f[n];

  // n & 1 -> 1 (нечетное), 0 (четное)
  uint64_t k = (n & 1) ? (n + 1) / 2 : n / 2;

  if (n & 1) {
    f[n] = fib(k) * fib(k) + fib(k - 1) * fib(k - 1);
  } else {
    f[n] = (2 * fib(k - 1) + fib(k)) * fib(k);
  }

  return f[n];
}

int main() {

  setlocale(0, "");

  cout << "Введите какое число Фибоначчи необходимо определить (n <= 93):"
       << endl;
  uint32_t n;
  if (cin >> n) {
    uint64_t ans = fib(n);
    cout << "Ответ: " << ans << endl;
  } else {
    cout << "Введите натуральное число!" << endl;
    return 1;
  }
}