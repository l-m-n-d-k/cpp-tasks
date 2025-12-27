#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void reverseString(string& str) {
    int length = str.length();
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }
}

int main() {
    string input_number;
    int source_base, target_base;
    
    cout << "Введите число: ";
    cin >> input_number;
    
    cout << "Введите исходное основание системы счисления: ";
    cin >> source_base;
    
    cout << "Введите новое основание системы счисления: ";
    cin >> target_base;
    
    if (source_base < 2 || source_base > 36 || target_base < 2 || target_base > 36) {
        cout << "Ошибка! Основания должны быть от 2 до 36." << endl;
        return 1;
    }
    
    long long decimal_value = 0;
    int power = 0;
    
    for (int i = input_number.length() - 1; i >= 0; i--) {
        char current_char = input_number[i];
        int digit_value;
        
        if (current_char >= '0' && current_char <= '9') {
            digit_value = current_char - '0';
        } else if (current_char >= 'A' && current_char <= 'Z') {
            digit_value = current_char - 'A' + 10;
        } else if (current_char >= 'a' && current_char <= 'z') {
            digit_value = current_char - 'a' + 10;
        } else {
            cout << "Ошибка! Некорректный символ." << endl;
            return 1;
        }
        
        if (digit_value >= source_base) {
            cout << "Ошибка! Цифра недопустима для системы с основанием " << source_base << endl;
            return 1;
        }
        
        decimal_value += digit_value * pow(source_base, power);
        power++;
    }
    
    string result = "";
    
    if (decimal_value == 0) {
        result = "0";
    } else {
        long long temp_value = decimal_value;
        
        while (temp_value > 0) {
            int remainder = temp_value % target_base;
            char result_digit;
            
            if (remainder < 10) {
                result_digit = '0' + remainder;
            } else {
                result_digit = 'A' + (remainder - 10);
            }
            
            result += result_digit;
            temp_value = temp_value / target_base;
        }
        
        reverseString(result);
    }
    
    cout << "\n=== РЕЗУЛЬТАТ ПЕРЕВОДА ===" << endl;
    cout << "Исходное число: " << input_number << " (основание " << source_base << ")" << endl;
    cout << "В десятичной системе: " << decimal_value << endl;
    cout << "Результат: " << result << " (основание " << target_base << ")" << endl;
    
    return 0;
}
