//name
#include <iostream>

using namespace std;

int main() {
  setlocale(LC_ALL, "rus");
  string s1;
  
  cout << "Пожалуйста введите имя на латинице" << endl;
  cin >> s1;
  cout << "Ваше имя " << s1 << endl;

  return 0;
}
