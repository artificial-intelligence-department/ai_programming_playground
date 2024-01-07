#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;


double double_f()
{
   int x=rand(), y=rand ();
            double a=(1-y)*pow(x+y,2)/pow(x+4,3)/(exp(-(x-2))+(pow (x,3)+4));
            double b=(1+cos(y-2))/(pow(x,2)+pow(sin(y-2),2));
            return a/b;  
}
double** double_matrix() {
    int N = 10;
    double** arr = new double* [N];
    for (int i = 0; i < N; ++i) {
        arr[i] = new double[N];
        for (int j = 0; j < N; ++j) {
            arr[i][j] = double_f();
        }
    }
    return arr;

};

double int_f()
{
     int x=rand(), y=rand();
       int a = (1 - y) * pow(x + y, 2) / pow(x + 4, 3) / (exp(-(x - 2)) + (pow(x, 3) + 4));
        int b=(1+cos(y-2))/(pow(x,2)+pow(sin(y-2),2));
        return a/b;
}
int** int_matrix() {
    int N = 10;
    int** arr = new int* [N];
    for (int i = 0; i < N; ++i) {
        arr[i] = new int[N];
        for (int j = 0; j < N; ++j) {
            arr[i][j] = int_f();
        }
    }
    return arr;

}

    double** sort_matrix(double** a, int rows=10, int cols=10) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols - 1; ++j) {
            for (int k = 0; k < cols - j - 1; ++k) {
                if (a[i][k] > a[i][k + 1]) {
                    swap(a[i][k], a[i][k + 1]);
                }
            }
        }
    }
    return a;
}

   int* sum_array(int** a, int rows = 10, int cols = 10) {
         int N = 10;
        int* arr = new int[N];
        for (int i = 0; i < rows; ++i) {
            int col1 = rand() % 10, col2, col3;
            do {
                int col2 = rand() % 10;
            } while (col2 == col1);

            do {
                int col3 = rand() % 10;
            } while (col3 == col1 || col3 == col2);
            arr[i] = col1 + col2 + col3;
        }

        return arr;

}
        bool writeToNewFile(const int* arr, const std::string& fileName) {
    std::ofstream outputFile(fileName);

    if (!outputFile.is_open()) {
        std::cerr << "Не вдалося відкрити файл для запису." << std::endl;
        return false;
    }

    for (int i = 0; i < 10; ++i) {
        outputFile << arr[i] << " ";
    }

    outputFile.close();

    std::cout << "Запис у файл завершено успішно." << std::endl;

    return true;
}

        
    
    int main() {
    const int pull_request_n = 876;
    
    if (pull_request_n % 2 == 0) {
        double** matrix = double_matrix();
        matrix = sort_matrix(matrix);
    }
    else {
        int** matrix = int_matrix();
        matrix = sort_matrix(matrix);
    }

    


    return 0;
}
    
    
    








