#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

// Визначення функцій
void floatmatrix(double y);
void intmatrix(int zround);

// Константа
const int nomer = 933;

// Змінні
double h = 0.5;
double x = -2.5;
double z = 0;
double y = 0;
int zround = 0;

// Масиви
double masuv[10][10];
int matrix[10][10];

int main(){
    int count = 0;
    for(x; x <= 2; x += h){
        z = fabs(x) + pow(x, 2);
        y = z * (sin(pow((2 + x), 2))) / (2 + x);
        zround = round(y);

        if(nomer % 2 == 0){
            floatmatrix(y);
        } else {
            intmatrix(zround);
        }
        count++;
        if(count == 10) break;
    }

    return 0;
}

// Функція для створення матриці з числами з плаваючою крапкою
void floatmatrix(double y){
    static int row = 0;
    double masuv[10][10]; // Визначення матриці
    for(int j = 0; j < 10; j++){
        masuv[row][j] = y;
    }

    row++;
    if(row == 10){
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                z = fabs(x) + pow(x, 2);
                y = z * (sin(pow((2 + x), 2))) / (2 + x);
                cout << fixed << setprecision(2) << masuv[i][j] << " ";
                x += h;
            }
            cout << endl;
        }
    }
}

// Функція для створення матриці з цілими числами
void intmatrix(int zround){
    static int row = 0;
    int matrix[10][10]; // Визначення матриці
    for(int j = 0; j < 10; j++){
        matrix[row][j] = zround;
    }

    row++;
    if(row == 10){
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                z = fabs(x) + pow(x, 2);
                y = z * (sin(pow((2 + x), 2))) / (2 + x);
                cout << round(y) << " ";
                x += h;
            }
            cout << endl;
        }
    }
}
