//task 3.2
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int main() {
  string filename;
  cout << "write filename with extension" << endl;
  getline(cin, filename);

  ifstream file(filename);
  if (!file.is_open()) {
    cerr << "cant open '" << filename << "'" << endl;
    return 1;
  }

  string line;
  int digit_counter = 0;
  string digits = "";

  while (getline(file, line)) {
    for (char c : line) {
      if (isdigit(c)) {
        digits += c;
        digit_counter++;
      }
    }
  }

  if (digit_counter > 0) {
    cout << "digits from the file: " << digits << endl;
  } else {
    cout << "no digits in the file" << endl;
  }

  file.close();
  return 0;
}
