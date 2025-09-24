//task 2.4 ()
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
  double start, finish, step;
  cout << "write start, finish and step" << endl;
  cin >> start >> finish >> step;

  cout << "table for function y = (x^2 - 2x + 2) / (x - 1)" << endl;
  cout << "for x from " << start << "to " << finish << "with step " << step << endl;
  cout << endl;

  cout << setw(10) << "x" << setw(15) << "y" << endl;
  cout << setw(25) << setfill('-') << "" << setfill(' ') << endl;

  for (double x = start; x <= finish + 0.001; x += step)
  {
    double y = (pow(x, 2) - 2 * x + 2) / (x - 1);

    cout << fixed << setprecision(1);
    cout << setw(10) << x;

    cout << fixed << setprecision(3);
    cout << setw(15) << y << endl;
  }

  return 0;
}