//task 2.5
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double S, p, n;
    cout << "write S rubles, p percentages and n years" << endl;
    cin >> S >> p >> n;

    double r = p / 100 / 12;
    double months = n * 12;
    double m = (S * r * pow(1 + r, months)) / (pow(1 + r, months) - 1);

    cout << m << " rub" << endl;

    return 0;
}
