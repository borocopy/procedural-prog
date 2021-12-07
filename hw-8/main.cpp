#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;

void q1() {
  int64_t baseCost, bladeCost, totalCost;

  cin >> baseCost >> bladeCost >> totalCost;
  int64_t n = (totalCost - baseCost) / bladeCost;
  cout << n << endl;
}

void q2() {
  int64_t bladesTotal;
  cin >> bladesTotal;

  int64_t fourWinged = bladesTotal % 3;
  int64_t threeWinged = (bladesTotal - 4 * fourWinged) / 3;

  if (threeWinged >= 0) {
    cout << threeWinged << endl;
    cout << fourWinged << endl;
  } else {
    cout << "0" << endl;
    cout << "0" << endl;
  }
}

void q3() {
  uint64_t n, m;
  cin >> n >> m;

  uint64_t ans = (n * (n + 1) / 2) * (m * (m + 1) / 2);

  cout << ans << endl;
}

int32_t findRoom(int32_t n) {
  if (n <= 36)
    return (n - 1) / 4;

  return 8 - (n - 37) / 2;
}

void q4() {
  int32_t rooms[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  int32_t freeSeatsCount;
  cin >> freeSeatsCount;

  for (size_t i = 0; i < freeSeatsCount; i++) {
    int32_t buf;
    cin >> buf;
    rooms[findRoom(buf)] += 1;
  }

  int32_t ans = 0;
  int32_t current = 0;

  for (size_t i = 0; i < 10; i++) {
    if (rooms[i] == 6) {
      current++;
    } else {
      ans = max(ans, current);
      current = 0;
    }
  }

  cout << ans << endl;
}

void q5() {
  uint64_t n, k;
  cin >> n >> k;
  while (k != 1) {
    n = (n - k % 2) / 2;
    k = k / 2;
  }

  uint64_t side1 = (n - 1) / 2;
  uint64_t side2 = n / 2;

  cout << side1 << endl;
  cout << side2 << endl;
}

int main() {
  setlocale(0, "");

  // q1();
  // q2();
  // q3();
  // q4();
  // q5();

  return 0;
}