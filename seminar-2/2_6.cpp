//task 2.6
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double s, p, n;
    cout << "enter S, p and n " << endl;
    cin >> s >> p >> n;

    double min_p = 0;
    double max_p = 100;

    while (max_p - min_p > 0.0001) {
        double test_p = (min_p + max_p) / 2;
        
        double month_p = test_p / 100 / 12;
        double months = n * 12;
        double test_p = (s * month_p * pow(1 + month_p, months)) /
                             (pow(1 + month_p, months) - 1);

        if (test_p < p) {
            min_p = test_p;
        }
        else {
            max_p = test_p;
        }
    }

    cout << "percent " << (min_p + max_p) / 2 << "%" << endl;
    cout << fixed << setprecision(2);

    return 0;
}
