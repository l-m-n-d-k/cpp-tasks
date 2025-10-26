//task 3.3
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
  string input_string;
  cout << "write 30 letters" << endl;
  getline(cin, input_string);

  if (input_string.length() != 30) {
    cout << "the length of the string is not equal to 30" << endl;
    return 1;
  }

  for (char c : input_string) {
    if (!isalpha(c)) {
      cout << "the string contains non-letter characters" << endl;
      return 1;
    }
  }

  int n = input_string.length();
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (input_string[j] > input_string[j + 1]) {
        char temp = input_string[j];
        input_string[j] = input_string[j + 1];
        input_string[j + 1] = temp;
      }
    }
  }

  cout << "sorted string: " << input_string << endl;

  return 0;
}
