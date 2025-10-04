#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double S, m, n;
    cout << "write S, m and n" << endl;
    cin >> S >> m >> n;

    double months = n * 12;
    double left = 0.000001;
    double right = 1.0;
    double r, calc_m;

    for (int i = 0; i < 100; i++) {
        r = (left + right) / 2;
        calc_m = (S * r * pow(1 + r, months)) / (pow(1 + r, months) - 1);

        if (calc_m < m)
            left = r;
        else
            right = r;
    }

    double p = r * 12 * 100;

    cout << p << " %" << endl;

    return 0;
}
