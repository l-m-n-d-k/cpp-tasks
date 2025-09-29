//arithmetic
#include <iostream>

using namespace std;

int main() {
  setlocale(LC_ALL, "rus");
  double x1, x2, d1, d2;
  
  cout << "пожалуйста введите два числа" << endl;
  cin >> x1 >> x2;

  d1 = x1 + x2;
  cout << "x1 + x2 = " << d1 << endl;
 
  d1 = x1 - x2;
  cout << "x1 - x2 = " << d1 << endl;
  
  d1 = x1 * x2;
  cout << "x2 * x2 = " << d1 << endl;

  if(x2 != 0){
    d1 = x1 / x2;
    cout << "x1 / x2 = " << d1 << endl;
  } else {
    cout << "нельзя делить на 0" << endl;
  }
  return 0;
}
