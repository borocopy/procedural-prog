#include <iostream>
#include <vector>

using namespace std;

bool isCorrect(vector<int> permutation) {
  for (size_t i = 0; i < permutation.size(); i++) {
    if (i + 1 == permutation[i])
      return 1;
  }

  return 0;
}

int main() {
  setlocale(0, "");
  uint64_t count = 0;

  vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  do {
    if (isCorrect(arr))
      count++;
  } while (next_permutation(arr.begin(), arr.end()));

  cout << count << endl;
}