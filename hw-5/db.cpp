#include <fstream>
#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

// Задача 6.2*
// csv база данных книг в библиотеке
// поиск книг с помощью двоичного дерева и хэширования
struct Book {
  string author;
  string title;
  uint16_t year;
};

void fill_book(Book *b, string author, string title, uint16_t year) {
  b->author = author;
  b->title = title;
  b->year = year;
}

void write_book(ofstream *fout, Book *book) {
  Book b = *book;
  *fout << b.author << "," << b.title << "," << b.year << "\n";
}

void parse_line(string line) {}

int main() {
  cout << "Добро пожаловать в электронное средство ведения библиотеки"
       << "\n"
       << "Добавьте новую книгу:"
       << "\n";
  ifstream fin("books_db.csv");
  ofstream fout;
  bool isNew = fin.good();
  cout << isNew << "\n";
  fout.open("books_db.csv");
  if (!isNew)
    fout << "author,title,year"
         << "\n";

  while (true) {
    string author;
    string title;
    uint16_t year;
    char ans = '0';
    bool isEnd = false;

    cout << "> Введите ФИО автора\n";
    getline(cin, author);
    cout << "> Введите название книги\n";
    getline(cin, title);
    cout << "> Введите год издания\n";
    while (!(cin >> year)) {
      cout << "Год издания - число!"
           << "\n";
    }
    struct Book book;
    fill_book(&book, author, title, year);
    write_book(&fout, &book);

    do {
      cout << "Добавить новую книгу (y/n)?"
           << "\n";
      cin >> ans;
      if (ans == 'n') {
        isEnd = true;
      }
      cout << ans << "\n";
    } while (ans != 'y' || ans != 'n');

    if (isEnd)
      break;
  }
}