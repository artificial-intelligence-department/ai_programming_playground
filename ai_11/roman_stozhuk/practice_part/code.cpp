#include <iostream>
#include <cmath>
#include <ctime>
#include <random>
#include <fstream>

using namespace std;

    //завдання 1
long **fillMatrixPair() {
    //формула з завдання 1 варіант 1
    long a=1; 
    long b=2;
    long c=3;  
    long **matrix=new long*[10];
    for (short i=0; i<10; i++) {
        matrix[i]=new long[10];
        for (short j=0; j<10; j++) {
            double p=(a+b+c)/2.0;
            matrix[i][j] = (long)(2.0/a)*(sqrt(p*(p-a)*(p-b)*(p-c))); 
            //примусово перетворено в long щоб отримати ціле число
            a+=1, b+=2, c+=3; 
        }
    }
}

    //завдання 1
double **fillMatrixUnpair() {
    //формула з завдання 1 варіант 1
    double a=1; 
    double b=2;
    double c=3;  
    double **matrix=new double*[10];
    for (short i=0; i<10; i++) {
        matrix[i]=new double[10];
        for (short j=0; j<10; j++) {
            double p=(a+b+c)/2.0;
            matrix[i][j] = (2.0/a)*(sqrt(p*(p-a)*(p-b)*(p-c))); 
        }
    }
}

    //завдання 2
long **sortMatrix(long **matrix, long abc) {
    for (short j=0; j<10; j++) {
        for (short i=0;i<9;i++) {
            for (short k=0; k<9-i;k++) {
                if (matrix[k][j] < matrix[k][j]) {
                    long tmp = matrix[k][j];
                    matrix[k][j]=matrix[k+1][j];
                    matrix[k+1][j]=tmp;
                }
            }
        }
    }
    return matrix;
}

    //завдання 2
double **sortMatrix(double **matrix, double abc) {
    for (short j=0; j<10; j++) {
        for (short i=0;i<9;i++) {
            for (short k=0; k<9-i;k++) {
                if (matrix[k][j] > matrix[k][j]) {
                    double tmp = matrix[k][j];
                    matrix[k][j]=matrix[k+1][j];
                    matrix[k+1][j]=tmp;
                }
            }
        }
    }
    return matrix;
}

    //завдання 3
long *sumMatrix(long **matrix) {
    srand(time(0));
    long sum[10] = {0};
    for (short j=0; j<10; j++) {
        for (short i=0;i<4;i++)
        sum[j]+=matrix[rand() % 10][j];
    }
}

    //завдання 3
long *sumMatrix(double **matrix) {
    srand(time(0));
    long sum[10] = {0};
    for (short j=0; j<10; j++) {
        for (short i=0;i<4;i++)
        sum[j]+=(long)matrix[rand() % 10][j];
    }
}

//завдання 4
bool writeIntoFile(long array[]) {
    bool win=false;
    ofstream out("file.dat", ios::binary);
    if(out.good()) {win=1;}
    for (short i=0; i<10; i++) {
        out << array[i] << ' ';
    }
    if(out.good()) {win=1;}
    out.close();
    return win;
}

//завдання 5
long multiply() {
    ifstream in("file.dat", ios::binary);
    long result = 1, tmp;
    in >> tmp;
    while (!in.eof()) {
        result*=tmp;
        in >> tmp;
    }
    cout << result;
    return result;
}

int main() {
    const int a=899;
    if (a%2 == 0) {    //a
        long **matrix = fillMatrixPair();    //завдання 1
        matrix = sortMatrix(matrix, a);     //завдання 2
        long *array=sumMatrix(matrix);      //завдання 3
    }
    else if (a%2 == 1) {//b
        double **matrix = fillMatrixUnpair();    //завдання 1
        matrix = sortMatrix(matrix, a*0.1);     //завдання 2
        long *array=sumMatrix(matrix);          //завдання 3
    }
    return 0;
}
