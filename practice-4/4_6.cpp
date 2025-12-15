//task 4.6
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void printTable(const string& filename) {
    ifstream file(filename);

    cout << "Содержимое файла " << filename << endl;

    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    cout << endl;
    file.close();
}

int main() {
    printTable("4_6_a.txt");
    printTable("4_6_b.txt");

    return 0;
}
