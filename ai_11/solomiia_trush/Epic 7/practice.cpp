#include <iostream>
using namespace std;

int x; // цілочисельна змінна
const int n=10, m=10; // цілочисельна константа

void Function (int p) {
    if(p%2==0) {
        cout << "Number is even" << endl;
    }
    else {
        cout << "Number is odd" << endl;
    }
}

int Factorial(int f) { //рекурсія
    if (f > 1) {
        return f * Factorial(f - 1);
    } else {
        return 1;
    }
}
double Factorial(double n) {
    if (n > 1) {
        return n * Factorial(n - 1); 
    } else {
        return 1;
    }
}



int Matrix (int array[10][10]) {
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            array[i][j]=Factorial(i+j);
        }
    }
    return 0;
}

double Matrix (double array[10][10]) {
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            array[i][j]=Factorial(i+j);
        }
    }
    return 0;
}


void BubbleSort (int rr[n][m]) {
    for (int j=0; j<n; j++) {
        for (int w=0; w<n-j-1; w++) {
            if (rr[j][w] < rr[j][w+1]) {
                x = rr[j][w];
                rr[j][w] = rr[j][w+1];
                rr[j][w+1] = x;
            }
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << rr[i][j] << " " ;
        }
        cout << endl;
    } 
}

void BubbleSort (double rr[n][m]) {
    for (int j=0; j<n; j++) {
        for (int w=0; w<n-j-1; w++) {
            if (rr[j][w] > rr[j][w+1]) {
                x = rr[j][w];
                rr[j][w] = rr[j][w+1];
                rr[j][w+1] = x;
            }
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << rr[i][j] << " ";
        }
        cout << endl;
    } 
}









int main () {
    int number = 917;
    int matrix[10][10]; //двовимірний масив

    Function(number);
    Matrix(matrix);
    BubbleSort(matrix);

}