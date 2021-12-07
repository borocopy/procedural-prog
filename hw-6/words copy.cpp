#include <fstream>
#include <iostream>
#include <math.h>
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

vector<string> read_entries(ifstream *fin) {
  vector<string> words;
  string buf;
  while (getline(*fin, buf)) {
    words.push_back(buf);
  }
  return words;
}

bool compareWords(const string a, const string b) {
  string SORTING_RULE =
      "0123456789AaBbCcDdEeFfGgHhUuJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz"
      "АаБбВвГгДдЕеЁёЖжЗзИиКкЛлМмНнОоПпРрСсТтУуФфХхЦцЧчШшЩщЪъЫыЬьЯяЮюЭэ";
  uint16_t posA = find_char(SORTING_RULE, a[0]);
  uint16_t posB = find_char(SORTING_RULE, b[0]);
  if (posA == posB) {
    return compareWords(a.substr(1, string::npos), b.substr(1, string::npos));
  }

  return posA < posB;
}

void sort_entries(vector<string> *entries) {
  sort((*entries).begin(), (*entries).end(), &compareWords);
}

int main() {
  setlocale(0, "");
  ofstream fout_temp("words.txt", ios::app);
  fout_temp.close();

  ifstream fin("words.txt", ios::in);
  vector<string> entries = read_entries(&fin);
  sort_entries(&entries);

  ofstream fout("words.txt", ios::out);
  for (size_t i = 0; i < entries.size(); i++) {
    fout << entries[i] << endl;
  }

  cout << "Слова отсортированны! Можно добавлять новые." << endl;

  while (true) {
    cout << "Введите новое слово (для выхода введите :q)" << endl;
    string word;
    getline(cin, word);
    word = trim(word);
    if (word != ":q") {
      entries.push_back(trim(word));

      sort_entries(&entries);

      ofstream fout("words.txt", ios::out);
      for (size_t i = 0; i < entries.size(); i++) {
        fout << entries[i] << endl;
      }
    } else {
      cout << "Конец работы." << endl;
      return 0;
    }
  }

  return 0;
}