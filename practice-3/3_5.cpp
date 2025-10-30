//task 3.5
#include <iostream>

using namespace std;

bool prime_check(int num){
  if (num < 2){
    return false;
  }
  for (int i = 2; i * i <= num; i++){
    if (num % i == 0){
      return false;
    }
  }
  return true;
}

int main(){
  int num;
  cout << "write natural number:" << endl;
  cin >> num;

  cout << "prime numbers from 2 to " << num << ":" << endl;
  for (int i = 2; i <= num; i++){
    if (prime_check(i)){
      cout << i << " ";
    }
  }

  cout << endl;
  return 0;
}
