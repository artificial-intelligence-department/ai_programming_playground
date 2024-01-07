#include <iostream>
#include <cmath>
using namespace std;

double** matrix_double() {
    int rows = 10;
    int cols = 10;
    double** array = new double*[rows];
    for (int i = 0; i < rows; ++i) {
        array[i] = new double[cols];
    }

    double a = 0.3;
    double b = 0.9;
    double x = 0.53;
    double y = (pow(a, 2*x)+pow(b, -x)*cos(a+b)*x)/abs(x+1);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            array[i][j] = y;
            a+=0.4;
            b+=0.3;
            x+=0.6;
        }
    }

    return array;
}

int** matrix_int() {
    int rows = 10;
    int cols = 10;
    int** array = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        array[i] = new int[cols];
    }

    int a = 3;
    int b = 9;
    int x = 5;
    int y = (pow(a, 2*x)+pow(b, -x)*cos(a+b)*x)/abs(x+1);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            array[i][j] = y;
            a+=4;
            b+=3;
            x+=6;
        }
    }

    return array;
}

void printArray(int** array, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << array[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

void printArray(double** array, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << array[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

void deleteArray(int** array, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] array[i];
    }
    delete[] array;
}

void deleteArray(double** array, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] array[i];
    }
    delete[] array;
}

void swap(double &a, double &b) {
    double temp = a;
    a = b;
    b = temp;
}

void bubbleSort(double arr[], int n) {
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < n-i-1; ++j) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < n-i-1; ++j) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

double** bubbleSort(double** arr, double pull, int rows = 10, int cols = 10){
    double** array = new double*[rows];
    for (int i = 0; i < rows; ++i) {
        array[i] = new double[cols];
    }
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            array[i][j] = arr[i][j];
        }
    }
    for (int i = 0; i < cols; i++)
    {
        double col[rows];
        for (int j = 0; j < rows; j++)
        {
            col[i] = array[j][i];
        }
        bubbleSort(col, rows);
    }
    return array;
}

int** bubbleSort(int** arr, int pull, int rows = 10, int cols = 10){
    int** array = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        array[i] = new int[cols];
    }
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            array[i][j] = arr[i][j];
        }
    }
    for (int i = 0; i < cols; i++)
    {
        int col[rows];
        for (int j = 0; j < rows; j++)
        {
            col[i] = array[j][i];
        }
        bubbleSort(col, rows);
    }
    return array;
}

int main() {
    const int pull = 946;

    if (pull%2==0){
        double** result = matrix_double();
        double input;
        cin >> input;
        double** sorted = bubbleSort(result, pull*input);
    }
    else{
        int** result = matrix_int();
        int** sorted = bubbleSort(result, pull);
    }


    // printArray(result, 10, 10);
    // deleteArray(result, 10);
    return 0;
}
