#include <iostream>
#include <cmath>
#include <array>
#include <random>
#include <algorithm>
#include <fstream>

using namespace std;

array <array <double, 10>, 10> Fmatrix(){
   array <array <double, 10>, 10> matrix; //умова 7
    const int num = 2; // умова 1 умова 4
    const double num2 = 2.2; // умова 2 умова 4

    
    for(int i = 0; i < 10; i++){ // умова 10
        for(int j = 0; j < 10; j++){
            int n = (j * num)/num2;
            
            double f_a1 = (num*n - 1)/(pow(num, n)); // в коді використано математичні операції та математичні функції
            matrix[i][j] = f_a1;
        }
    }

    return matrix;

}
void bubbleSort(array<double, 10>& arr) {
    int n = arr.size();
    for(int i = 0; i < n-1; i++) {     
        for (int j = 0; j < n-i-1; j++) { 
            if (arr[j] > arr[j+1]) { // умова 5
                swap(arr[j], arr[j+1]);
            }
        }
    }
}
void intbubbleSort(array<int, 10>& arr) {
    int n = arr.size();
    for(int i = 0; i < n-1; i++) {     
        for (int j = 0; j < n-i-1; j++) { 
            if (arr[j] < arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}
void sortMatrix(array<array<double, 10>, 10>& matrix) { // умова 12
    for(auto& row : matrix) {
        bubbleSort(row);
    }
}
void sortMatrix(array<array<int, 10>, 10>& matrix) {// умова 12
    for(auto& row : matrix) {
        intbubbleSort(row);
    }
}
void printMatrix(const array<array<double, 10>, 10>& matrix) {// умова 12
    for(const auto& row : matrix) {
        for(const auto& elem : row) {
            cout << elem << ' '; // в коді використано оператори виведення та введення даних
        }
        cout << '\n';
    }
}
void printMatrix(const array<array<int, 10>, 10>& matrix) {// умова 12
    for(const auto& row : matrix) {
        for(const auto& elem : row) {
            cout << elem << ' '; // в коді використано оператори виведення та введення даних
        }
        cout << '\n';
    }
}


double function(array <array <double, 10>, 10> matrix){// умова 12
         sortMatrix(matrix);
         printMatrix(matrix);
    }
double function(array <array <int, 10>, 10> matrix){// умова 12
    sortMatrix(matrix);
    printMatrix(matrix);
}


array<int, 10> calculateSums(const array<array<double, 10>, 10>& matrix) {
    array<int, 10> sums; //умова 6
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 9);

    for(int j = 0; j < 10; j++){
        double sum = 0;
        for(int i = 0; i < 4; i++){
            int randIndex = dis(gen);
            sum += matrix[randIndex][j];
        }
        sums[j] = static_cast<int>(sum); // відкидаємо дробову частину
    }

    return sums;
}

void writefile(array<int, 10> matrix){
    ofstream exemple1("text.txt");
    if (exemple1.is_open())
    {
        for(const auto &e : matrix) 
        {
            exemple1 << e << "\n";
        }
        exemple1.close();
    }
    else 
    {
        std::cout << "Unable to open file";
    }
}

int main (){
    array <array <double, 10>, 10> matrix = Fmatrix();

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    function(matrix); // в коді використано параметри та аргументи функції
    array<int, 10> sums = calculateSums(matrix);

    writefile(sums);

    return 0;
}