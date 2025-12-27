#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

// Структуры для данных
struct Toy {
    string name;
    double price;
    int min_age;
    int max_age;
};

struct Book {
    string author;
    string title;
    int year;
};

// Задача 5.5.1: Игрушки
void task5_5_1() {
    ifstream file("5.5.1_toys.txt");
    if (!file.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }
    
    cout << "Задача 5.5.1: Игрушки" << endl;
    cout << "================================" << endl;
    
    vector<Toy> toys;
    Toy temp;
    
    while (file >> temp.name >> temp.price >> temp.min_age >> temp.max_age) {
        toys.push_back(temp);
    }
    file.close();
    
    // a) Игрушки до 400р для 8 лет
    cout << "\nа) Игрушки до 400р для 8 лет:" << endl;
    for (const auto& toy : toys) {
        if (toy.price <= 400 && toy.min_age <= 8 && toy.max_age >= 8) {
            cout << "  " << toy.name << " - " << toy.price << " руб" << endl;
        }
    }
    
    // б) Самая дорогая игрушка
    double max_price = 0;
    for (const auto& toy : toys) {
        if (toy.price > max_price) max_price = toy.price;
    }
    
    cout << "\nб) Самая дорогая игрушка(и):" << endl;
    for (const auto& toy : toys) {
        if (toy.price == max_price) {
            cout << "  " << toy.name << " - " << toy.price << " руб" << endl;
        }
    }
    
    // в) Игрушки для 4 и 10 лет
    cout << "\nв) Игрушки для детей 4 и 10 лет:" << endl;
    for (const auto& toy : toys) {
        if (toy.min_age <= 4 && toy.max_age >= 10) {
            cout << "  " << toy.name << " - " << toy.price << " руб" << endl;
        }
    }
}

// Задача 5.5.2: Библиотека
void task5_5_2() {
    ifstream file("5.5.2_books.txt");
    if (!file.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }
    
    cout << "Задача 5.5.2: Библиотека" << endl;
    cout << "================================" << endl;
    
    vector<Book> books;
    Book temp;
    
    while (file >> temp.author >> temp.title >> temp.year) {
        books.push_back(temp);
    }
    file.close();
    
    // a) Поиск книги по автору и году
    string search_author, search_title;
    int search_year;
    
    cout << "\nа) Поиск книги:" << endl;
    cout << "Введите автора: ";
    cin.ignore();
    getline(cin, search_author);
    cout << "Введите название: ";
    getline(cin, search_title);
    cout << "Введите год: ";
    cin >> search_year;
    
    bool found = false;
    for (const auto& book : books) {
        if (book.author == search_author && book.title == search_title && book.year == search_year) {
            cout << "Найдена книга: " << book.title << " (" << book.year << ")" << endl;
            found = true;
            break;
        }
    }
    
    if (!found) {
        cout << "Книга не найдена" << endl;
    }
    
    // б) Поиск книги со словом "Паскаль"
    cout << "\nб) Поиск книг со словом 'Паскаль':" << endl;
    bool has_pascal = false;
    for (const auto& book : books) {
        if (book.title.find("Паскаль") != string::npos) {
            cout << "Найдена: " << book.title << " - " << book.author << " (" << book.year << ")" << endl;
            has_pascal = true;
        }
    }
    
    if (!has_pascal) {
        cout << "Книг со словом 'Паскаль' не найдено" << endl;
    }
}

// Задача 5.5.3: Обработка массивов
void task5_5_3() {
    ifstream input_file("5.5.3_arrays.txt");
    if (!input_file.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }
    
    cout << "Задача 5.5.3: Обработка массивов" << endl;
    cout << "================================" << endl;
    
    vector<vector<int>> arrays;
    string line;
    
    while (getline(input_file, line)) {
        stringstream ss(line);
        vector<int> arr;
        int num;
        
        while (ss >> num) {
            arr.push_back(num);
        }
        
        if (!arr.empty()) {
            arrays.push_back(arr);
        }
    }
    input_file.close();
    
    // а) Замена max/min на 0
    vector<vector<int>> modified_arrays = arrays;
    
    for (auto& arr : modified_arrays) {
        if (arr.empty()) continue;
        
        int max_val = arr[0], min_val = arr[0];
        int max_idx = 0, min_idx = 0;
        
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > max_val) {
                max_val = arr[i];
                max_idx = i;
            }
            if (arr[i] < min_val) {
                min_val = arr[i];
                min_idx = i;
            }
        }
        
        arr[max_idx] = 0;
        arr[min_idx] = 0;
    }
    
    // Сохранение в файл 2
    ofstream output_file2("5.5.3_output2.txt");
    for (const auto& arr : modified_arrays) {
        for (int num : arr) {
            output_file2 << num << " ";
        }
        output_file2 << endl;
    }
    output_file2.close();
    
    cout << "\nа) Максимальные и минимальные элементы заменены на 0" << endl;
    cout << "   Результат сохранен в 5.5.3_output2.txt" << endl;
    
    // б) Преобразование в матрицы 10x10
    ofstream output_file3("5.5.3_output3.txt");
    
    for (const auto& arr : arrays) {
        vector<vector<int>> matrix(10, vector<int>(10, 0));
        int idx = 0;
        
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (idx < arr.size()) {
                    matrix[i][j] = arr[idx++];
                } else {
                    matrix[i][j] = rand() % 100;
                }
            }
        }
        
        output_file3 << "Матрица " << &arr - &arrays[0] + 1 << ":\n";
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                output_file3 << matrix[i][j] << " ";
            }
            output_file3 << endl;
        }
        output_file3 << endl;
    }
    
    output_file3.close();
    
    cout << "б) Массивы преобразованы в матрицы 10x10" << endl;
    cout << "   Результат сохранен в 5.5.3_output3.txt" << endl;
}

// Задача 5.5.6: Натуральные числа
void task5_5_6() {
    ifstream file("5.5.6_numbers.txt");
    if (!file.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }
    
    cout << "Задача 5.5.6: Натуральные числа" << endl;
    cout << "================================" << endl;
    
    vector<int> numbers;
    int num;
    
    while (file >> num) {
        numbers.push_back(num);
    }
    file.close();
    
    if (numbers.empty()) {
        cout << "Файл пуст!" << endl;
        return;
    }
    
    // Наименьший общий делитель (НОД)
    int gcd_val = numbers[0];
    for (int i = 1; i < numbers.size(); i++) {
        int a = gcd_val, b = numbers[i];
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        gcd_val = a;
    }
    
    // Наибольший общий делитель (на самом деле НОД, но по смыслу)
    cout << "Наименьший общий делитель: " << gcd_val << endl;
    
    // Простые числа
    vector<int> primes;
    for (int n : numbers) {
        if (n < 2) continue;
        
        bool is_prime = true;
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                is_prime = false;
                break;
            }
        }
        
        if (is_prime) {
            primes.push_back(n);
        }
    }
    
    cout << "Найдено простых чисел: " << primes.size() << endl;
    
    // Сохранение простых чисел
    ofstream prime_file("5.5.6_primes.txt");
    for (int prime : primes) {
        prime_file << prime << " ";
    }
    prime_file.close();
    
    cout << "Простые числа сохранены в 5.5.6_primes.txt" << endl;
    
    // Просмотр содержимого
    cout << "\nПросмотр файлов:" << endl;
    cout << "Исходный файл (первые 10 чисел): ";
    for (int i = 0; i < 10 && i < numbers.size(); i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    
    cout << "Простые числа: ";
    for (int prime : primes) {
        cout << prime << " ";
    }
    cout << endl;
}

// Задача 5.5.7: Матрицы
void task5_5_7() {
    ifstream file("5.5.7_matrices.txt");
    if (!file.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }
    
    cout << "Задача 5.5.7: Матрицы" << endl;
    cout << "================================" << endl;
    
    vector<vector<vector<int>>> matrices;
    
    // Читаем до конца файла
    while (!file.eof()) {
        int rows, cols;
        
        // Пытаемся прочитать размеры матрицы
        if (!(file >> rows)) break;
        if (!(file >> cols)) break;
        
        vector<vector<int>> matrix(rows, vector<int>(cols));
        bool read_success = true;
        
        // Читаем элементы матрицы
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (!(file >> matrix[i][j])) {
                    read_success = false;
                    break;
                }
            }
            if (!read_success) break;
        }
        
        if (read_success) {
            matrices.push_back(matrix);
        }
    }
    
    file.close();
    
    if (matrices.empty()) {
        cout << "Не удалось прочитать матрицы из файла!" << endl;
        return;
    }
    
    cout << "Прочитано матриц: " << matrices.size() << endl;
    
    ofstream result_file("5.5.7_results.txt");
    
    for (int m = 0; m < matrices.size(); m++) {
        result_file << "Матрица " << m + 1 << ":\n";
        
        // Выводим саму матрицу
        vector<vector<int>> matrix = matrices[m];
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result_file << matrix[i][j] << " ";
            }
            result_file << endl;
        }
        result_file << endl;
        
        map<int, vector<pair<int, int>>> positions;
        
        // Собираем позиции одинаковых элементов
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                positions[matrix[i][j]].push_back(make_pair(i, j));
            }
        }
        
        // Выводим элементы с повторениями
        for (const auto& entry : positions) {
            if (entry.second.size() > 1) {
                result_file << "Элемент " << entry.first << " встречается " 
                          << entry.second.size() << " раз:" << endl;
                
                for (const auto& pos : entry.second) {
                    result_file << "  Строка " << pos.first + 1 
                              << ", Столбец " << pos.second + 1 << endl;
                }
                result_file << endl;
            }
        }
        
        result_file << "------------------------" << endl;
    }
    
    result_file.close();
    
    cout << "Результаты сохранены в 5.5.7_results.txt" << endl;
    cout << "Обработано матриц: " << matrices.size() << endl;
}
// Задача 5.5.12: Пилообразная последовательность
void task5_5_12() {
    ifstream file("5.5.12_real.txt");
    if (!file.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }
    
    cout << "Задача 5.5.12: Пилообразная последовательность" << endl;
    cout << "================================" << endl;
    
    vector<double> numbers;
    double num;
    
    while (file >> num) {
        numbers.push_back(num);
    }
    file.close();
    
    if (numbers.empty()) {
        cout << "Файл пуст!" << endl;
        return;
    }
    
    // Поиск самой длинной возрастающей последовательности
    int max_length = 1;
    int current_length = 1;
    int start_idx = 0;
    int max_start = 0;
    
    for (int i = 1; i < numbers.size(); i++) {
        if (numbers[i] > numbers[i-1]) {
            current_length++;
            if (current_length > max_length) {
                max_length = current_length;
                max_start = start_idx;
            }
        } else {
            current_length = 1;
            start_idx = i;
        }
    }
    
    cout << "Самая длинная возрастающая последовательность:" << endl;
    cout << "Длина: " << max_length << endl;
    cout << "Начинается с позиции: " << max_start + 1 << endl;
    cout << "Элементы: ";
    
    for (int i = max_start; i < max_start + max_length; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
}

int main() {
    int choice;
    
    do {
        cout << "----------------------------" << endl;
        cout << "Практическое задание 5.5" << endl;
        cout << "1. 5.5.1  - Игрушки" << endl;
        cout << "2. 5.5.2  - Библиотека" << endl;
        cout << "3. 5.5.3  - Обработка массивов" << endl;
        cout << "4. 5.5.6  - Натуральные числа" << endl;
        cout << "5. 5.5.7  - Матрицы" << endl;
        cout << "6. 5.5.12 - Пилообразная последовательность" << endl;
        cout << "0. Выход" << endl;
        cout << "Выбор: ";
        cin >> choice;
        cout << "----------------------------" << endl;
        
        switch(choice) {
            case 1: task5_5_1(); break;
            case 2: task5_5_2(); break;
            case 3: task5_5_3(); break;
            case 4: task5_5_6(); break;
            case 5: task5_5_7(); break;
            case 6: task5_5_12(); break;
            case 0: cout << "Выход" << endl; break;
            default: cout << "Неверный выбор" << endl;
        }
        
    } while (choice != 0);
    
    return 0;
}
