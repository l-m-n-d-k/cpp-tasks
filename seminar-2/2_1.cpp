//task 2.1
#include <iostream>
#include <cmath>
using namespace std;

int main() {
  double x, a;
  cout << "write x and a:" << endl;
  cin >> x >> a;

  if (abs(x) < 1) {
    if (x == 0) {
      cout << "error 1" << endl;
    } else {
      cout << "w = " << a * log(abs(x)) << endl;
    }
  } else {
    if (a - pow(x, 2) < 0) {
      cout << "error 2" << endl;
    } else {
      cout << "w = " << sqrt(a - pow(x, 2)) << endl;
    }
  }

  return 0;
}
