#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x, y, b;
    cout << "write x, y, and b" << endl;
    cin >> x >> y >> b;

    if (b - y <= 0) {
        cout << "error: logarithm argument must be positive (b - y <= 0)" << endl;
        return 0;
    }

    if (b - x < 0) {
        cout << "error: square root argument must be non-negative (b - x < 0)" << endl;
        return 0;
    }

    double z = log(b - y) * sqrt(b - x);

    cout << "z = " << z << endl;

    return 0;
}
