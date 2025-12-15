//task 2.5
#include <iostream>
#include <cmath>
using namespace std;

int main(){
  double S, m, n, p, r = 0.0001, res = 0;
  cin >> S >> m >> n;
  while(res < m){
    res = (S * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));
    r += 0.0001;
  }
  cout << r * 100 << endl;
  return 0;
}
