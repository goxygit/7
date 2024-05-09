#include <iostream>
#include <vector>
using namespace std;

const int M = 20;
const int N = 20;

int main() {
    // Введення розмірів матриці
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

    // Ініціалізація матриці
    vector<vector<int>> matr(row, vector<int>(col));
    
    // Введення елементів матриці
    cout << "Введіть елементи матриці:" << endl;
    for (int i = 0; i < row; ++i) {
        cout << "Рядок " << i + 1 << ": ";
        for (int j = 0; j < col; ++j) {
            cin >> matr[i][j];
        }
    }

    // Пошук індексу стовпця з першим додатнім елементом
    int first_positive_col = -1;
    for (int j = 0; j < col; ++j) {
        bool has_positive = false;
        for (int i = 0; i < row; ++i) {
            if (matr[i][j] > 0) {
                has_positive = true;
                break;
            }
        }
        if (has_positive) {
            first_positive_col = j;
            break;
        }
    }

    // Пошук останнього стовпця з додатніми елементами
    int last_positive_col = -1;
    for (int j = col - 1; j >= 0; --j) {
        bool has_positive = false;
        for (int i = 0; i < row; ++i) {
            if (matr[i][j] > 0) {
                has_positive = true;
                break;
            }
        }
        if (has_positive) {
            last_positive_col = j;
            break;
        }
    }

    // Обмін стовпців, якщо знайдено відповідні стовпці
    if (first_positive_col != -1 && last_positive_col != -1 && first_positive_col != last_positive_col) {
        for (int i = 0; i < row; ++i) {
            swap(matr[i][first_positive_col], matr[i][last_positive_col]);
        }
    }

    // Виведення матриці
    cout << "Матриця після обміну стовпців:" << endl;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << matr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
