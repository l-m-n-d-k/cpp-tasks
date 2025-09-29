//bx + c = 0
#include <iostream>

using namespace std;

int main() {
  setlocale(LC_ALL, "rus");
  double b, c;

  cout << "write b and c" << endl;
  cin >> b >> c;

  if (b != 0 and c != 0){
    cout << "b * x + c = 0 => x = " << ((-1) * c) / b;
  }

  if (c == 0){
    cout << "b * x + c = 0 => x = 0";
  }

  if (b == 0){
    cout << "not answer";
  }
  
  return 0;
}
