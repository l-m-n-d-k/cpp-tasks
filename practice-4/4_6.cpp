//task 4.6
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
    int sellers = 3;
    int goods = 4;

    double A[sellers][goods];
    double price[goods];
    double commission[goods];
    double C[sellers][2] = {0};

    ifstream fileA("4_6_a.txt");
    
    for (int i = 0; i < sellers; i++)
        for (int j = 0; j < goods; j++)
            fileA >> A[i][j];

    fileA.close();

    ifstream fileB("4_6_b.txt");

    int productNumber;
    for (int i = 0; i < goods; i++) {
        fileB >> productNumber >> price[i] >> commission[i];
    }

    fileB.close();

    for (int i = 0; i < sellers; i++) {
        for (int j = 0; j < goods; j++) {
            C[i][0] += A[i][j] * price[j];
            C[i][1] += A[i][j] * commission[j];
        }
    }

    cout << fixed << setprecision(2);

    cout << "\nМатрица C (выручка | комиссионные):\n";
    for (int i = 0; i < sellers; i++) {
        cout << "Продавец " << i + 1 << ": "
             << C[i][0] << " | "
             << C[i][1] << endl;
    }

    int maxRev = 0, minRev = 0;
    int maxCom = 0, minCom = 0;
    double totalRevenue = 0, totalCommission = 0;

    for (int i = 0; i < sellers; i++) {
        totalRevenue += C[i][0];
        totalCommission += C[i][1];

        if (C[i][0] > C[maxRev][0]) maxRev = i;
        if (C[i][0] < C[minRev][0]) minRev = i;

        if (C[i][1] > C[maxCom][1]) maxCom = i;
        if (C[i][1] < C[minCom][1]) minCom = i;
    }

    cout << "\n1) Больше всего выручил продавец: " << maxRev + 1 << endl;
    cout << "   Меньше всего выручил продавец: " << minRev + 1 << endl;

    cout << "\n2) Больше всего комиссионных получил продавец: " << maxCom + 1 << endl;
    cout << "   Меньше всего комиссионных получил продавец: " << minCom + 1 << endl;

    cout << "\n3) Общая выручка: " << totalRevenue << endl;
    cout << "4) Всего комиссионных: " << totalCommission << endl;
    cout << "5) Общая сумма денег, прошедших через продавцов: "
         << totalRevenue + totalCommission << endl;

    return 0;
}
