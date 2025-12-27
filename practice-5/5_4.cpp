#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

// Задача 5.4.1: Вычисление ряда
void task5_4_1() {
    ifstream file("5.4.1_input.txt");
    if (!file.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }
    
    cout << "Задача 5.4.1" << endl;
    cout << "y = 1/sin1 + 2/(sin1+sin2) + ... + n/(sin1+...+sinn)" << endl;
    cout << "================================" << endl;
    
    int n;
    while (file >> n) {
        double y = 0;
        double denominator_sum = 0;
        
        for (int i = 1; i <= n; i++) {
            denominator_sum += sin(i);
            y += i / denominator_sum;
        }
        
        cout << "n = " << n << " -> y = " << y << endl;
    }
    
    file.close();
}

// Задача 5.4.2: Вычисление ряда с факториалами
void task5_4_2() {
    ifstream file("5.4.2_input.txt");
    if (!file.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }
    
    cout << "Задача 5.4.2" << endl;
    cout << "y = n!/√1 + (n-1)!/√(2+3) + ..." << endl;
    cout << "================================" << endl;
    
    int n;
    while (file >> n) {
        double y = 0;
        int start_num = 1;
        
        for (int i = 0; i < n; i++) {
            double factorial = 1;
            for (int j = 1; j <= (n - i); j++) {
                factorial *= j;
            }
            
            double sum_inside = 0;
            for (int k = 0; k <= i; k++) {
                sum_inside += (start_num + k);
            }
            start_num += (i + 1);
            
            y += factorial / sqrt(sum_inside);
        }
        
        cout << "n = " << n << " -> y = " << y << endl;
    }
    
    file.close();
}

// Задача 5.4.3: Последовательность с точностью
void task5_4_3() {
    ifstream file("5.4.3_input.txt");
    if (!file.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }
    
    cout << "Задача 5.4.3" << endl;
    cout << "Последовательность a_n = (12 - a_{n-1}*x)/(a_{n-2}^2 + 5)" << endl;
    cout << "Найти первый член с |a_n - a_{n-1}| < ε" << endl;
    cout << "================================" << endl;
    
    double x, epsilon;
    while (file >> x >> epsilon) {
        vector<double> a(100, 0);
        a[0] = 1;
        a[1] = x;
        
        int n_found = -1;
        double a_found = 0;
        
        for (int n = 2; n < 100; n++) {
            a[n] = (12 - a[n-1] * x) / (a[n-2] * a[n-2] + 5);
            
            if (fabs(a[n] - a[n-1]) < epsilon && n > 15) {
                n_found = n;
                a_found = a[n];
                break;
            }
        }
        
        if (n_found != -1) {
            cout << "x = " << x << ", ε = " << epsilon << endl;
            cout << "Найден a[" << n_found << "] = " << a_found << endl;
        } else {
            cout << "x = " << x << ", ε = " << epsilon << " -> не найдено" << endl;
        }
    }
    
    file.close();
}

// Задача 5.4.8: Вычисление ряда с произведением
void task5_4_8() {
    ifstream file("5.4.8_input.txt");
    if (!file.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }
    
    cout << "Задача 5.4.8" << endl;
    cout << "y = 1/a + 2/(a(a+1)) + 3/(a(a+1)(a+2)) + ..." << endl;
    cout << "================================" << endl;
    
    int n;
    double a;
    while (file >> n >> a) {
        double y = 0;
        double denominator = 1;
        
        for (int i = 0; i <= n; i++) {
            denominator = 1;
            for (int j = 0; j <= i; j++) {
                denominator *= (a + j);
            }
            y += (i + 1) / denominator;
        }
        
        cout << "n = " << n << ", a = " << a << " -> y = " << y << endl;
    }
    
    file.close();
}

// Задача 5.4.13: Трехзначные числа с заданной суммой цифр
void task5_4_13() {
    ifstream file("5.4.13_input.txt");
    if (!file.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }
    
    cout << "Задача 5.4.13" << endl;
    cout << "Трехзначные числа с суммой цифр = m" << endl;
    cout << "================================" << endl;
    
    int m;
    while (file >> m) {
        if (m < 1 || m > 27) {
            cout << "m = " << m << " (должно быть 1..27)" << endl;
            continue;
        }
        
        vector<int> numbers;
        
        for (int num = 100; num <= 999; num++) {
            int sum = 0;
            int temp = num;
            
            while (temp > 0) {
                sum += temp % 10;
                temp /= 10;
            }
            
            if (sum == m) {
                numbers.push_back(num);
            }
        }
        
        cout << "m = " << m << ": найдено " << numbers.size() << " чисел" << endl;
        if (!numbers.empty()) {
            cout << "Примеры: ";
            for (int i = 0; i < 5 && i < numbers.size(); i++) {
                cout << numbers[i] << " ";
            }
            if (numbers.size() > 5) cout << "...";
            cout << endl;
        }
    }
    
    file.close();
}

// Задача 5.4.18: Анализ роста учеников
void task5_4_18() {
    cout << "Задача 5.4.18" << endl;
    cout << "Анализ роста учеников" << endl;
    cout << "================================" << endl;
    
    vector<int> heights;
    int height;
    
    cout << "Введите рост (см), 0 для завершения:" << endl;
    
    while (true) {
        cout << "-> ";
        cin >> height;
        
        if (height == 0) break;
        
        if (height > 50 && height < 250) {
            heights.push_back(height);
        } else {
            cout << "Некорректный рост!" << endl;
        }
    }
    
    if (heights.empty()) {
        cout << "Нет данных!" << endl;
        return;
    }
    
    double sum = 0;
    for (int h : heights) {
        sum += h;
    }
    double average = sum / heights.size();
    
    int above_average = 0;
    for (int h : heights) {
        if (h > average) above_average++;
    }
    
    cout << "================================" << endl;
    cout << "Средний рост: " << average << " см" << endl;
    cout << "У " << above_average << " человек рост превышает средний" << endl;
}

// Задача 5.4.28: Сумма цифр числа
void task5_4_28() {
    cout << "Задача 5.4.28" << endl;
    cout << "Сумма цифр целого числа" << endl;
    cout << "================================" << endl;
    
    long long n;
    cout << "Введите число: ";
    cin >> n;
    
    if (n < 0) n = -n;
    
    int sum = 0;
    long long temp = n;
    
    while (temp > 0) {
        sum += temp % 10;
        temp /= 10;
    }
    
    cout << "Число: " << n << endl;
    cout << "Сумма цифр: " << sum << endl;
}

int main() {
    int choice;
    
    do {
        cout << "\n----------------------------" << endl;
        cout << "Практическое задание 5.4" << endl;
        cout << "1. 5.4.1  - Ряд с sin" << endl;
        cout << "2. 5.4.2  - Ряд с факториалами" << endl;
        cout << "3. 5.4.3  - Последовательность" << endl;
        cout << "4. 5.4.8  - Ряд с произведением" << endl;
        cout << "5. 5.4.13 - Трехзначные числа" << endl;
        cout << "6. 5.4.18 - Рост учеников" << endl;
        cout << "7. 5.4.28 - Сумма цифр" << endl;
        cout << "0. Выход" << endl;
        cout << "Выбор: ";
        cin >> choice;
        cout << "----------------------------" << endl;
        
        switch(choice) {
            case 1: task5_4_1(); break;
            case 2: task5_4_2(); break;
            case 3: task5_4_3(); break;
            case 4: task5_4_8(); break;
            case 5: task5_4_13(); break;
            case 6: task5_4_18(); break;
            case 7: task5_4_28(); break;
            case 0: cout << "Выход" << endl; break;
            default: cout << "Неверный выбор" << endl;
        }
        
    } while (choice != 0);
    
    return 0;
}
