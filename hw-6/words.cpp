#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <math.h>
#include <set>
#include <string.h>
#include <unicase.h>
#include <vector>
using namespace std;

const string WHITESPACE = " \n\r\t\f\v";

size_t find_char(string dataString, char letter) {
  for (size_t i = 0; i < dataString.length(); i++) {
    if (dataString[i] == letter)
      return i;
  }

  return string::npos;
}

string ltrim(const string &s) {
  size_t start = s.find_first_not_of(WHITESPACE);
  return (start == string::npos) ? "" : s.substr(start);
}

string rtrim(const string &s) {
  size_t end = s.find_last_not_of(WHITESPACE);
  return (end == string::npos) ? "" : s.substr(0, end + 1);
}

string trim(const string &s) { return rtrim(ltrim(s)); }

multiset<string> read_entries(ifstream *fin) {
  multiset<string> words;
  string buf;
  while (getline(*fin, buf)) {
    words.insert(trim(buf));
  }
  return words;
}

void print_set_to_file(multiset<string> entries) {
  ofstream fout("words.txt", ios::out);

  vector<string> bufferVector(entries.size());
  copy(entries.begin(), entries.end(), bufferVector.begin());

  for (size_t i = 0; i < bufferVector.size(); i++) {
    fout << bufferVector[i] << endl;
  }
}

int main() {
  setlocale(0, "");
  ofstream fout_temp("words.txt", ios::app);
  fout_temp.close();
  ifstream fin("words.txt", ios::in);
  multiset<string> entries = read_entries(&fin);
  print_set_to_file(entries);

  while (true) {

    cout << "Слова отсортированны! Можно добавлять новые." << endl;
    cout << "Введите новое слово (для выхода введите :q)" << endl;
    string word;
    getline(cin, word);
    word = trim(word);
    if (word != ":q") {
      entries.insert(word);

      print_set_to_file(entries);
    } else {
      cout << "Конец работы." << endl;
      return 0;
    }
  }

  return 0;
}