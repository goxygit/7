#include <iostream>
using namespace std;

const int M = 20;
const int N = 20;

int main() {
    // Введення кількості рядків та стовпців
    int row, col;
    cout << "Введіть кількість рядків (від 2 до 20): ";
    cin >> row;
    cout << "Введіть кількість стовпців (від 2 до 20): ";
    cin >> col;

    // Перевірка на допустимість розмірів матриці
    if (row < 2 || row > M || col < 2 || col > N) {
        cout << "Неправильні розміри матриці!" << endl;
        return 1;
    }

    // Ініціалізація матриці та суми елементів діагоналі
    int matr1[M][N];
    int sm = 0;

    // Введення елементів матриці та обчислення діагональних елементів
    cout << "Введіть елементи матриці через пробіл:" << endl;
    for (int i = 0; i < row; ++i) {
        cout << "Рядок " << i + 1 << ": ";
        for (int j = 0; j < col; ++j) {
            cin >> matr1[i][j];
            // Обчислення суми елементів діагоналі
            if (i == j)
                sm += matr1[i][j];
        }
    }

    // Виведення елементів матриці
    cout << "Елементи матриці:" << endl;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << matr1[i][j] << " ";
        }
        cout << endl;
    }

    // Виведення суми елементів діагоналі
    cout << "Сума елементів діагоналі: " << sm << endl;

    return 0;
}