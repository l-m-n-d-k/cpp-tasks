//task 4_4
include <iostream>

using namespace std;

void RandomSequence(int m, int i, int c, int count) {
    int s_curr = 0;
    
    cout << "parameters: m=" << m << ", i=" << i << ", c=" << c << endl;
    for (int j = 0; j < count; j++) {
        cout << "s_" << j << " = " << s_curr << endl;
        s_curr = (m * s_curr + i) % c;
    }
}

int main() {
    RandomSequence(37, 3, 64, 10);
    cout << endl;
    
    RandomSequence(25173, 13849, 65537, 10);
    cout << endl;

    return 0;
}
