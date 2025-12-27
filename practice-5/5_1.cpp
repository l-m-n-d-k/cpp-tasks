#include <iostream>
#include <string>
#include <map>

using namespace std;

int romanToInt(const string& roman) {
    map<char, int> values = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}
    };
    
    int result = 0;
    int n = roman.length();
    
    for (int i = 0; i < n; i++) {
        int current = values[roman[i]];
        int next = (i + 1 < n) ? values[roman[i + 1]] : 0;
        
        if (current < next) {
            result -= current;
        } else {
            result += current;
        }
    }
    
    return result;
}

int main() {
    string roman_num;
    cout << "Введите римское число: ";
    cin >> roman_num;
    
    int number = romanToInt(roman_num);
    cout << "Десятичное значение: " << number << endl;
    
    return 0;
}
