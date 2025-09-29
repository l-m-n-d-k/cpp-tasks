//task 2.2
#include <iostream>
#include <cmath>
using namespace std;

int main() {
  double x, y, b;
  cout << "write x, y, and b" << endl;
  cin >> x >> y >> b;

  if (b - x == 0) {
      cout << "error: division by zero (b - x = 0)" << endl;
      return 1;
  }

  if (b - y <= 0) {
      cout << "error: logarithm argument must be positive (b - y <= 0)" << endl;
      return 1;
  }

  double z = log(b - y) / (b - x);

  cout << "z = " << z << endl;

  return 0;
}
