//task 3.3
#include <iostream>
#include <string>

using namespace std;

int main(){
  string input_string;
  cout << "write 30 letters" << endl;

  for (int i = 0; i < 30; i++) {
    char letter;
    cout << "letter " << (i + 1) << ": ";
    cin >> letter;
    input_string += letter;
  }


  if (input_string.length() != 30) {
    cout << "the length of the string is not equal to 30" << endl;
    return 0;
  }

  for (char c : input_string) {
    if (!isalpha(c)) {
      cout << "the string contains non-letter characters" << endl;
      return 0;
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
