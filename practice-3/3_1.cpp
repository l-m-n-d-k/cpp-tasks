//task 3.1
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  string filename;
  cout << "write filename with extension" << endl;
  getline(cin, filename);

  ifstream file(filename);
  if (!file.is_open()) {
    cout << "cant open '" << filename << "'" << endl;
    return 0;
  }

  string line;
  while (getline(file, line)) {
    cout << line << endl;
  }

  file.close();
  return 0;
}
