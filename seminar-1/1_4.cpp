//discriminant
#include <iostream>
#include <cmath>

using namespace std;

int main() {
  setlocale(LC_ALL, "rus");
  double a, b, c, disc;

  cout << "write a and b and c" << endl;
  cin >> a >> b >> c;

  if (a == 0){
    if (b != 0 and c != 0){
    cout << "x = " << ((-1) * c) / b;
  }

  if (c == 0){
    cout << "x = 0";
    return 0;
  }

  if (b == 0){
    cout << "not answer";
  }
  
  return 0;
  } 

  disc = pow(b, 2) - 4 * a * c;

  if (disc > 0 and a != 0){
    cout << "x1 = " << (-b + sqrt(disc)) / (2 * a) << endl;
    cout << "x2 = " << (-b - sqrt(disc)) / (2 * a);
  }

  if (disc < 0){
    cout << "not answer";
  }


  if (disc == 0){
    cout << "x = " << -b / (2 * a);
  }

  
  return 0;
}
