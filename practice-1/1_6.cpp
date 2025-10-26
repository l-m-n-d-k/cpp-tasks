//cone
#include <iostream>
#include <cmath>

using namespace std;

int main() {
  double h, R, r;

  cout << "Write h, R, r" << endl;
  cin >> h >> R >> r;

  double l = sqrt(pow((R - r), 2) + pow(h, 2));
  cout << "V = " << (M_PI * h * (pow(R, 2) + R * r + pow(r, 2))) / 3 << endl;
  cout << "S = " << M_PI * (pow(R, 2) + (R + r) * l + pow(r, 2));
  
  return 0;
}
