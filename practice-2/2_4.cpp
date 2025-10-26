//task 2.4
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
  cout << "table for function y = (x^2 - 2x + 2) / (x - 1)" << endl;
  cout << "for x from -4 to +4 with step 0.5" << endl;
  cout << endl;

  cout << setw(4) << "x" << setw(8) << "y" << endl;
  cout << setw(18) << setfill('-') << "" << setfill(' ') << endl;

  for (double x = -4.0; x <= 4.001; x += 0.5)
  {
    cout << fixed << setprecision(1);
    cout << setw(6) << x;

    if (x == 1.0) {
      cout << setw(23) << "cannot divide by 0" << endl;
      continue;
    }
    
    double y = (pow(x, 2) - 2 * x + 2) / (x - 1);

    cout << fixed << setprecision(3);
    cout << setw(10) << y << endl;
  }

  return 0;
}
