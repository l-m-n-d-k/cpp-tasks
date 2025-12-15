//task 4_5
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int main() {
  clock_t start = clock();

  srand(time(nullptr));

  int arr[] = {5, 2, 3, 1, 4};
  int n = 5;

  cout << "исходный массив: ";
  for (int i = 0; i < n; i++){
    cout << arr[i] << " ";
  }
  cout << endl;

  bool sorted = false;
  int attempts = 0;

  while (!sorted) {
    sorted = true;
    for (int i = 1; i < n; i++) {
      if (arr[i-1] > arr[i]) {
        sorted = false;
        break;
      }
    }

    if (!sorted) {
      for (int i = 0; i < n; i++) {
        int j = rand() % n;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
      attempts++;
    }
  }

  clock_t end = clock();
  double time_taken = double(end - start) / CLOCKS_PER_SEC;

  cout << "oтсортированный массив: ";
  for (int i = 0; i < n; i++){
    cout << arr[i] << " ";
  }
  cout << endl;

  cout << "попыток перемешивания: " << attempts << endl;
  cout << fixed << setprecision(6) << "время выполнения: " << time_taken << " мс" << endl;

  return 0;
}
