#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Введіть розмірність квадратної матриці: ";
    cin >> n;
    int a[n][n];
    cout << "Введіть елементи матриці: " << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    int max = a[0][0];
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(a[i][i] > max) {
            max = a[i][i];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(a[i][j] > max) {
                count++;
            }
        }
    }
    cout << "Кількість елементів, більших за будь-який елемент на головній діагоналі: " << count << endl;
    return 0;
}
