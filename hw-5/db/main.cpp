#include <fstream>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

enum QueryTokens { ADD, QUIT, SEARCH, INPUT_ERROR };

typedef struct {
  string author;
  string title;
  uint32_t release_year;
} Book;

typedef struct {
  QueryTokens type;
  vector<string> data;
} InputQuery;

typedef struct {
  string author;
  string title;
  uint32_t release_year;
} SearchQuery;

Book *new_book(string author, string title, uint32_t release_year) {
  Book *book = (Book *)malloc(sizeof(Book));
  book->author = author;
  book->title = title;
  book->release_year = release_year;

  return book;
}

InputQuery new_input_query(vector<string> tokens) {
  // InputQuery *input_query = (InputQuery *)malloc(sizeof(InputQuery));
  InputQuery input_query;
  vector<string> data;
  QueryTokens token;
  if (tokens[0].compare("ADD") == 0) {
    token = ADD;
  } else if (tokens[0].compare("QUIT") == 0) {
    token = QUIT;
  } else if (tokens[0].compare("FIND") == 0) {
    token = SEARCH;
  }

  for (size_t i = 1; i < tokens.size(); i++) {
    data.push_back(tokens[i]);
  }

  input_query.data = data;
  input_query.type = token;

  return input_query;
}

string trim(string a) {
  for (size_t i = 0; i < a.length(); i++) {
    if (a[i] == ' ') {
      a.erase(i, 1);
    } else {
      break;
    }
  }

  for (size_t i = a.length() - 1; i >= 0; i--) {
    if (a[i] == ' ') {
      a.erase(i, 1);
    } else {
      break;
    }
  }

  return a;
}

vector<string> tokenize_input(string input) {
  string proc_input = trim(input);
  bool escape = false;
  vector<string> tokens;
  string buf = "";
  for (size_t i = 0; i < proc_input.length(); i++) {
    if (proc_input[i] == ' ' && !escape) {
      tokens.push_back(buf);
      buf = "";
      continue;
    }

    if (proc_input[i] == '"') {
      escape = !escape;
    } else {
      buf += proc_input[i];
    }
  }
  tokens.push_back(buf);

  return tokens;
}

SearchQuery *new_search_query(vector<string> tokens) {
  SearchQuery *search_query = (SearchQuery *)malloc(sizeof(SearchQuery));

  for (size_t i = 0; i < tokens.size(); i += 2) {
    if (tokens[i].compare("AUTHOR") == 0) {
      search_query->author = tokens[i + 1];
    } else if (tokens[i].compare("TITLE") == 0) {
      search_query->title = tokens[i + 1];
    } else if (tokens[i].compare("RELEASE_YEAR") == 0) {
      search_query->release_year = (uint32_t)stoi(tokens[i + 1]);
    }
  }

  return search_query;
}

vector<Book *> search_books(ifstream &fin, SearchQuery *search_query) {
  string data;
  getline(fin, data);
  Book *search_template = new_book(search_query->author, search_query->title,
                                   search_query->release_year);
  vector<Book *> search_result;
  while (getline(fin, data)) {

    bool is_compatible = true;

    vector<string> current_data;
    string buf = "";
    bool is_whole_string = false;
    for (size_t i = 0; i < data.length(); i++) {
      if (data[i] == '"') {
        is_whole_string = !is_whole_string;
      }
      if (data[i] == ',' && !is_whole_string) {
        current_data.push_back(buf);
        buf = "";
      } else {
        buf += data[i];
      }
    }

    current_data.push_back(buf);
    cout << current_data[0] << current_data[1] << current_data[2] << endl;

    if (search_query->author != "" &&
        current_data[0].find(search_query->author) == string::npos) {
      is_compatible = false;
    }
    if (search_query->title != "" &&
        current_data[1].find(search_query->title) == string::npos) {
      is_compatible = false;
    }
    if (search_query->release_year != 0 &&
        (uint32_t)stoi(current_data[2]) != search_query->release_year) {
      cout << ((uint32_t)stoi(current_data[2]) != search_query->release_year)
           << endl;
      is_compatible = false;
    }

    if (is_compatible) {

      Book *book = new_book(current_data[0], current_data[1],
                            (uint32_t)stoi(current_data[2]));
      search_result.push_back(book);
    }
  }

  return search_result;
}

void print_prompt() { cout << "biblio_db > "; }
void print_help() {
  cout << "???????????????? ???????? 'ADD \"??????????\" \"????????????????_??????????\" \"?????? ??????????????\"' "
          "?????????????????? ?? ???????? ???????????? ???????????????? ?? ??????????."
       << endl;
  cout << "???????????????? ???????? 'QUIT' ?????????????????? ??????????????????." << endl;
}

void write_book(ofstream &fout, Book *book) {
  fout << "\"" << book->author << "\""
       << ","
       << "\"" << book->title << "\""
       << "," << book->release_year << endl;
}

bool check_empty(ifstream &pFile) {
  return pFile.peek() == ifstream::traits_type::eof();
}

void repl(ifstream &fin, ofstream &fout) {
  string input;
  print_help();
  InputQuery input_query;
  while (true) {
    print_prompt();
    getline(cin, input);
    vector<string> tokens = tokenize_input(input);
    input_query = new_input_query(tokens);

    // for (int i = 0; i < tokens.size(); i++) {
    //   cout << tokens[i] << endl;
    // }

    switch (input_query.type) {
    case QUIT: {
      cout << "???????????????????? ????????????" << endl;
      return;
    }
    case ADD: {
      Book *book = new_book(input_query.data[0], input_query.data[1],
                            (uint16_t)stoi(input_query.data[2]));

      write_book(fout, book);
      break;
    }
    case SEARCH: {
      SearchQuery *search_query = new_search_query(input_query.data);
      vector<Book *> search_result = search_books(fin, search_query);

      if (search_result.size() == 0) {
        cout << "?????????? ???? ?????? ??????????????????????" << endl;
      } else {
        cout << "???? ?????????????? ?????????????? " << search_result.size()
             << " ????????????????????:" << endl;
        cout << "?????????? - ???????????????? - ?????? ??????????????" << endl;
        for (size_t i = 0; i < search_result.size(); i++) {
          cout << search_result[i]->author << " - " << search_result[i]->title
               << " - " << search_result[i]->release_year << endl;
        }
      }
      break;
    }
    case INPUT_ERROR: {
      cout << "(!) ???????????? ??????????."
           << "\n";
      print_help();
      break;
    }
    }
  }
}

int main() {
  ifstream fin("db.csv");
  ofstream fout("db.csv", ios_base::app);
  if (!fin || check_empty(fin)) {
    fout << "author,title,release_year"
         << "\n";

    fout.flush();
  }
  setlocale(0, "");
  cout << "???????? ???????????? ????????????????????." << endl;
  repl(fin, fout);
  fout.close();
  fin.close();
  return 0;
}