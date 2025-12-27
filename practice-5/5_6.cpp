#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int count_matches = 0;

void generatePermutations(vector<int>& balls, int start, int n) {
    if (start == n) {
        for (int i = 0; i < n; i++) {
            if (balls[i] == i + 1) {
                count_matches++;
                return;
            }
        }
        return;
    }
    
    for (int i = start; i < n; i++) {
        swap(balls[start], balls[i]);
        
        generatePermutations(balls, start + 1, n);
        
        swap(balls[start], balls[i]);
    }
}

void task5_6_recursive() {
    cout << "Задача 5.6: Шарики (рекурсивное решение)" << endl;
    cout << "========================================" << endl;
    
    int n;
    cout << "Введите количество шариков (1-10): ";
    cin >> n;
    
    if (n < 1 || n > 10) {
        cout << "Количество должно быть от 1 до 10!" << endl;
        return;
    }
    
    vector<int> balls(n);
    for (int i = 0; i < n; i++) {
        balls[i] = i + 1;
    }
    
    count_matches = 0;
    generatePermutations(balls, 0, n);
    
    cout << "Количество шариков: " << n << endl;
    cout << "Всего перестановок: ";
    
    long long total_permutations = 1;
    for (int i = 1; i <= n; i++) {
        total_permutations *= i;
    }
    
    cout << total_permutations << endl;
    cout << "Ситуаций, когда хотя бы один шарик на своем месте: " << count_matches << endl;
    cout << "Процент: " << (count_matches * 100.0 / total_permutations) << "%" << endl;
}

void task5_6_formula() {
    cout << "Задача 5.6: Шарики (по формуле из задания)" << endl;
    cout << "===========================================" << endl;
    
    cout << "Формула: k_n = (k_{n-1} + k_{n-2}) * (n-1)" << endl;
    cout << "где k_n - количество нужных ситуаций для n шариков" << endl;
    cout << endl;
    
    int n;
    cout << "Введите количество шариков (1-15): ";
    cin >> n;
    
    if (n < 1 || n > 15) {
        cout << "Количество должно быть от 1 до 15!" << endl;
        return;
    }
    
    vector<long long> k(n + 1);
    vector<long long> total(n + 1);
    
    k[1] = 1;
    k[2] = 1;
    total[1] = 1;
    total[2] = 2;
    
    for (int i = 3; i <= n; i++) {
        k[i] = (k[i-1] + k[i-2]) * (i - 1);
        total[i] = total[i-1] * i;
    }
    
    cout << "\nРезультаты:" << endl;
    cout << "n | Всего перестановок | Нужных ситуаций | Формула расчета" << endl;
    cout << "--|-------------------|----------------|----------------" << endl;
    
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            cout << i << " | " << total[i] << "               | " << k[i] << "              | k1 = 1" << endl;
        } else if (i == 2) {
            cout << i << " | " << total[i] << "               | " << k[i] << "              | k2 = 1" << endl;
        } else {
            cout << i << " | " << total[i];
            if (total[i] < 100) cout << "              ";
            else if (total[i] < 1000) cout << "             ";
            else if (total[i] < 10000) cout << "            ";
            else cout << "           ";
            
            cout << "| " << k[i];
            if (k[i] < 100) cout << "              ";
            else if (k[i] < 1000) cout << "             ";
            else if (k[i] < 10000) cout << "            ";
            else cout << "           ";
            
            cout << "| k" << i << " = (k" << i-1 << " + k" << i-2 << ") * " << i-1 
                 << " = (" << k[i-1] << " + " << k[i-2] << ") * " << i-1 << " = " << k[i] << endl;
        }
    }
    
    cout << "\nДля n = " << n << ":" << endl;
    cout << "Всего перестановок: " << total[n] << endl;
    cout << "Нужных ситуаций: " << k[n] << endl;
    cout << "Процент: " << (k[n] * 100.0 / total[n]) << "%" << endl;
}

void task5_6_test() {
    cout << "Задача 5.6: Шарики (тестирование малых n)" << endl;
    cout << "==========================================" << endl;
    
    cout << "Тестируем для n = 1..5 рекурсивно:" << endl;
    cout << endl;
    
    for (int n = 1; n <= 5; n++) {
        vector<int> balls(n);
        for (int i = 0; i < n; i++) {
            balls[i] = i + 1;
        }
        
        count_matches = 0;
        generatePermutations(balls, 0, n);
        
        long long total_permutations = 1;
        for (int i = 1; i <= n; i++) {
            total_permutations *= i;
        }
        
        cout << "n = " << n << ":" << endl;
        cout << "  Всего перестановок: " << total_permutations << endl;
        cout << "  Нужных ситуаций: " << count_matches << endl;
        
        if (n == 3) {
            cout << "  Примеры нужных ситуаций для n=3:" << endl;
            cout << "  [1,2,3] - шарик 1 на 1 месте" << endl;
            cout << "  [1,3,2] - шарик 1 на 1 месте" << endl;
            cout << "  [2,1,3] - шарик 3 на 3 месте" << endl;
            cout << "  [3,2,1] - шарик 2 на 2 месте" << endl;
        }
        cout << endl;
    }
    
    cout << "Объяснение условия:" << endl;
    cout << "Ситуация считается 'нужной', если хотя бы один шарик" << endl;
    cout << "оказывается на своем месте (шарик №k вынут k-ым по порядку)." << endl;
    cout << endl;
    cout << "Пример: для 3 шариков:" << endl;
    cout << "[1,2,3] - нужная (шарик 1 на месте 1)" << endl;
    cout << "[1,3,2] - нужная (шарик 1 на месте 1)" << endl;
    cout << "[2,1,3] - нужная (шарик 3 на месте 3)" << endl;
    cout << "[2,3,1] - НЕ нужная (никто не на своем месте)" << endl;
    cout << "[3,1,2] - НЕ нужная (никто не на своем месте)" << endl;
    cout << "[3,2,1] - нужная (шарик 2 на месте 2)" << endl;
}

int main() {
    int choice;
    
    do {
        cout << "\n================================" << endl;
        cout << "Задача 5.6: Шарики" << endl;
        cout << "================================" << endl;
        cout << "1. Рекурсивное решение (n ≤ 10)" << endl;
        cout << "2. Решение по формуле (n ≤ 15)" << endl;
        cout << "3. Тестирование малых n (1-5)" << endl;
        cout << "4. Объяснение задачи" << endl;
        cout << "0. Выход" << endl;
        cout << "================================" << endl;
        cout << "Выбор: ";
        cin >> choice;
        cout << "================================" << endl;
        
        switch(choice) {
            case 1: task5_6_recursive(); break;
            case 2: task5_6_formula(); break;
            case 3: task5_6_test(); break;
            case 4: 
                cout << "Объяснение задачи 5.6:" << endl;
                cout << "=======================" << endl;
                cout << "Из урны с n пронумерованными шариками (1..n)" << endl;
                cout << "вынимают по одному шарику." << endl;
                cout << endl;
                cout << "Нужно найти количество ситуаций, когда хотя бы" << endl;
                cout << "один вынутый шарик оказывается на своем месте:" << endl;
                cout << "шарик с номером k вынут k-ым по порядку." << endl;
                cout << endl;
                cout << "Пример для n=3:" << endl;
                cout << "Всего 6 перестановок:" << endl;
                cout << "1) [1,2,3] - нужная (шарик 1 на месте 1)" << endl;
                cout << "2) [1,3,2] - нужная (шарик 1 на месте 1)" << endl;
                cout << "3) [2,1,3] - нужная (шарик 3 на месте 3)" << endl;
                cout << "4) [2,3,1] - НЕ нужная" << endl;
                cout << "5) [3,1,2] - НЕ нужная" << endl;
                cout << "6) [3,2,1] - нужная (шарик 2 на месте 2)" << endl;
                cout << endl;
                cout << "Итого: 4 нужные ситуации из 6." << endl;
                cout << endl;
                cout << "В задании приведена рекуррентная формула:" << endl;
                cout << "k_n = (k_{n-1} + k_{n-2}) * (n-1)" << endl;
                cout << "где k_n - количество нужных ситуаций для n шариков" << endl;
                break;
            case 0: cout << "Выход" << endl; break;
            default: cout << "Неверный выбор" << endl;
        }
        
    } while (choice != 0);
    
    return 0;
}
