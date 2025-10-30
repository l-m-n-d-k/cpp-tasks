//task 3.4
#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int num1, num2;
  cout << "write two positive nums:" << endl;
  cin >> num1 >> num2;
  
  int a = abs(num1);
  int b = abs(num2);

  while (a != b) {
    if (a > b) {
      a = a - b;
    } else {
      b = b - a;
    }
  }

  cout << "Euclidean subtraction: " << a << endl;

  a = abs(num1);
  b = abs(num2);

  while (b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
  }

  cout << "Euclidean division: " << a << endl;

  return 0;
}
