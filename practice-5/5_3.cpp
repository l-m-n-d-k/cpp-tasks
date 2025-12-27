#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// Задача 5.3.4: Поиск самого длинного слова
void findLongestWord() {
    ifstream file("4_file.txt");
    if (!file.is_open()) {
        cout << "Ошибка открытия файла 4_file.txt!" << endl;
        return;
    }
    
    string longest_word = "";
    string word;
    
    while (file >> word) {
        if (word.length() > longest_word.length()) {
            longest_word = word;
        }
    }
    
    file.close();
    
    cout << "Задача 5.3.4: Поиск слова максимальной длины" << endl;
    cout << "Файл: 4_file.txt" << endl;
    cout << "Самое длинное слово: " << longest_word << endl;
    cout << "Длина: " << longest_word.length() << " символов" << endl;
}

// Задача 5.3.19: Самый частый символ
void findMostCommonChar() {
    ifstream file("19_file.txt");
    if (!file.is_open()) {
        cout << "Ошибка открытия файла 19_file.txt!" << endl;
        return;
    }
    
    // Подсчитываем только английские буквы
    int letters[26] = {0};
    char ch;
    
    while (file.get(ch)) {
        if (ch >= 'a' && ch <= 'z') {
            letters[ch - 'a']++;
        } else if (ch >= 'A' && ch <= 'Z') {
            letters[ch - 'A']++;
        }
    }
    
    file.close();
    
    char most_common = 'a';
    int max_count = 0;
    
    for (int i = 0; i < 26; i++) {
        if (letters[i] > max_count) {
            max_count = letters[i];
            most_common = 'a' + i;
        }
    }
    
    cout << "Задача 5.3.19: Поиск частого символа" << endl;
    cout << "Файл: 19_file.txt" << endl;
    cout << "Самая частая английская буква: '" << most_common << "'" << endl;
    cout << "Встречается " << max_count << " раз" << endl;
}

// Задача 5.3.32: Шифрование 
void encryptCaesar() {
    ifstream input_file("32_file.txt");
    if (!input_file.is_open()) {
        cout << "Ошибка открытия файла 32_file.txt!" << endl;
        return;
    }
    
    string content = "";
    string line;
    while (getline(input_file, line)) {
        content += line + "\n";
    }
    input_file.close();
    
    int shift = 3;
    string encrypted = "";
    
    for (char c : content) {
        if (c >= 'A' && c <= 'Z') {
            char encrypted_char = ((c - 'A' + shift) % 26) + 'A';
            encrypted += encrypted_char;
        } else if (c >= 'a' && c <= 'z') {
            char encrypted_char = ((c - 'a' + shift) % 26) + 'a';
            encrypted += encrypted_char;
        } else {
            encrypted += c;
        }
    }
    
    ofstream output_file("32_encrypted.txt");
    output_file << encrypted;
    output_file.close();
    
    cout << "Задача 5.3.32: Шифрование сдвигом" << endl;
    cout << "Файл: 32_file.txt" << endl;
    cout << "Сдвиг: " << shift << endl;
    cout << "Зашифровано в: 32_encrypted.txt" << endl;
}

// Задача 5.3.15: Поиск слова
void searchWord() {
    ifstream file("15_file.txt");
    if (!file.is_open()) {
        cout << "Ошибка открытия файла 15_file.txt!" << endl;
        return;
    }
    
    string search_term = "программирование";
    
    string line;
    int line_num = 1;
    int total_count = 0;
    
    while (getline(file, line)) {
        size_t pos = 0;
        int line_count = 0;
        
        while ((pos = line.find(search_term, pos)) != string::npos) {
            line_count++;
            total_count++;
            pos += search_term.length();
        }
        
        if (line_count > 0) {
            cout << "Строка " << line_num << ": " << line_count << " раз" << endl;
        }
        
        line_num++;
    }
    
    file.close();
    
    cout << "Задача 5.3.15: Поиск слова" << endl;
    cout << "Файл: 15_file.txt" << endl;
    cout << "Искомое слово: " << search_term << endl;
    cout << "Всего найдено: " << total_count << " раз" << endl;
}

// Задача 5.3.12: Чтение файла
void readFile() {
    ifstream file("12_file.txt");
    if (!file.is_open()) {
        cout << "Ошибка открытия файла 12_file.txt!" << endl;
        return;
    }
    
    cout << "Задача 5.3.12: Чтение файла" << endl;
    cout << "Файл: 12_file.txt" << endl;
    
    string line;
    int line_num = 1;
    
    while (getline(file, line)) {
        cout << line_num << ": " << line << endl;
        line_num++;
    }
    
    file.close();
}

// Задача 5.3.38: Проверка скобок
void checkBrackets() {
    ifstream file("38_file.txt");
    if (!file.is_open()) {
        cout << "Ошибка открытия файла 38_file.txt!" << endl;
        return;
    }
    
    cout << "Задача 5.3.38: Проверка скобок" << endl;
    cout << "Файл: 38_file.txt" << endl;
    
    string line;
    int line_num = 1;
    
    while (getline(file, line)) {
        int round_open = 0;
        int round_close = 0;
        
        for (char c : line) {
            if (c == '(') round_open++;
            else if (c == ')') round_close++;
        }
        
        bool round_ok = (round_open == round_close);
        
        cout << "Строка " << line_num << ": ";
        if (round_ok) {
            cout << "OK";
        } else {
            cout << "ERROR ( " << round_open << "/" << round_close << " )";
        }
        cout << endl;
        
        line_num++;
    }
    
    file.close();
}

int main() {
    int choice;
    
    do {
        cout << "----------------------------" << endl;
        cout << "\nПрактическое задание 5.3" << endl;
        cout << "1. 5.3.4  - Слово максимальной длины" << endl;
        cout << "2. 5.3.12 - Чтение файла" << endl;
        cout << "3. 5.3.15 - Поиск слова" << endl;
        cout << "4. 5.3.19 - Частый символ" << endl;
        cout << "5. 5.3.32 - Шифрование" << endl;
        cout << "6. 5.3.38 - Скобки" << endl;
        cout << "0. Выход" << endl;
        cout << "Выбор: ";
        cin >> choice;
        cout << "----------------------------" << endl;        
        switch(choice) {
            case 1: findLongestWord(); break;
            case 2: readFile(); break;
            case 3: searchWord(); break;
            case 4: findMostCommonChar(); break;
            case 5: encryptCaesar(); break;
            case 6: checkBrackets(); break;
            case 0: cout << "Выход" << endl; break;
            default: cout << "Неверно" << endl;
        }
        
    } while (choice != 0);
    
    return 0;
}
