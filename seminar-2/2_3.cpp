//task 2.3
#include <iostream>
using namespace std;

int main() {
  int N;

  cout << "write N" << endl;
  cin >> N;

  if (N <= 0)
  {
    int count = 0;
    while (count < 10)
    {
      cout << 1 + count << " ";
      count++;
    }
    } else {
      int count = 0;
      while (count < 10)
      {
        cout << N + count << " ";
        count++;
    }
  }
  return 0;
}
