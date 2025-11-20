//task 4_2

#include <iostream>
using namespace std;

int main() {
    const int WIDTH = 48;

    cout << " ";
    for (int i = 0; i < WIDTH; i++) {
        cout << "_";
    }
    cout << endl;

    for (int row = 0; row < 6; row++) {
        cout << "|";

        for (int col = 0; col < 8; col++) {
            if (row % 2 == 0) {
                cout << "* ";
            } else {
                cout << " *";
            }
        }

        for (int i = 0; i < WIDTH - 16; i++) {
            if (row % 2 == 0) {
                cout << "#";
            } else {
                cout << " ";
            }
        }
        cout << "|" << endl;
    }

    for (int stripe = 0; stripe < 7; stripe++) {
        cout << "|";
        for (int i = 0; i < WIDTH; i++) {
            if (stripe % 2 == 0) {
                cout << "#";
            } else {
                cout << " ";
            }
        }
        cout << "|" << endl;
    }

    cout << " ";
    for (int i = 0; i < WIDTH; i++) {
        cout << "_";
    }
    cout << endl;

    return 0;
}
