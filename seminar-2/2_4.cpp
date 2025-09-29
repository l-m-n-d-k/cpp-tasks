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

  cout << setw(10) << "x" << setw(15) << "y" << endl;
  cout << setw(25) << setfill('-') << "" << setfill(' ') << endl;

  for (double x = -4.0; x <= 4.001; x += 0.5)
  {
    double y = (pow(x, 2) - 2 * x + 2) / (x - 1);

    cout << fixed << setprecision(1);
    cout << setw(10) << x;

    cout << fixed << setprecision(3);
    cout << setw(15) << y << endl;
  }

  return 0;
}
