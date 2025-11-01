//task 3.6
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream outfile("numbers.txt");
    
    cout << "write 10 numbers:" << endl;
    for (int i = 0; i < 10; i++) {
        int number;
        cout << "number " << (i + 1) << ": ";
        cin >> number;
        outfile << number << endl;
    }
    
    outfile.close();
    
    ifstream infile("numbers.txt");
    int number, sum = 0;
    
    while (infile >> number) {
        sum += number;
    }
    
    infile.close();
    
    cout << "sum of numbers: " << sum << endl;

    return 0;
}
