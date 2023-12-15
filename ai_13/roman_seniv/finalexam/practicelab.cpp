#include <iostream>
#include <cstlib>
#include <cstime>
using namespace std;

const int 928; // ствоерння константи яка дорівнює номеру пулреквесту
const int rows = 10;
const int cols = 10;

int matrix[rows][cols];

void generateMatrix() { // функція яка створює двохвимірну матрицю 
    for (int i = 0; i < rows; ++i) { // використовується цикл
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = static_cast<int>(sin(i * 10 + j) * 100);
        }
    }
}

int main() {
    generateMatrix();

    for (int i = 0; i < rows; ++i) { // використання циклу
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << '\t'; // виведення результату
        }
        cout << endl;
    }


    return 0;
}
void sort(float floatvalue){ // перевантаження функції 
    for (int j=0; i<cols; i++){
        for (int i=0; i<rows-1; i++){
            if (matrix[i][j]> matrix[i+1][j])
            swap(matrix[i][j],matrix[i+1][j])// використовується для обміну знаень двох змінних
        }
    }
}
void sort(float intvalue){ // переватаження функції
    for (int i=0; i<rows; i++){
        for (int j=0; j<cols-1; j++){
            if (matrix[i][j]< matrix[i][j+1])
            swap(matrix[i][j],matrix[i+1][j])
        }
    }
}
int main() {
    // виклик функцій
    generateMatrix();

    cout << "Original Matrix:" << endl;
    printMatrix();

    float floatValue;
    cout << "Enter a floating-point value: ";
    cin >> floatValue;

    // Сортування стовпців за зростанням для матриці з числами з плаваючою крапкою
    sortColumns(floatValue);

    cout << "\nMatrix after sorting columns in ascending order:" << endl;
    printMatrix();

    int intValue;
    cout << "\nEnter an integer value: ";
    cin >> intValue;

    // Сортування рядків за спаданням для матриці з цілими числами
    sortRows(intValue);

    cout << "\nMatrix after sorting rows in descending order:" << endl;
    printMatrix();


    return 0;
}
void Sums (int resultarray[10]){// задаю масив
for (int j=0; j<cols; j++){
    int sum=0;
    int count =( rand()%2)+3
    for (int k=0; k<count; k++){
        int random = rand()
    }
}
}
bool writeToDisk(const int arr[rows][cols]) {
    ofstream outputFile("matrix.txt");

    if (outputFile.is_open()) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                outputFile << arr[i][j] << '\t';
            }
            outputFile << endl;
        }
        outputFile.close();
        return true;
    } else {
        return false;
    }
}

int main() {
    generateMatrix();

    cout << "Original Matrix:" << endl;
    printMatrix();

    float floatValue;
    cout << "Enter a floating-point value: ";
    cin >> floatValue;

   
    sortColumns(floatValue);

    cout << "\nMatrix after sorting columns in ascending order:" << endl;
    printMatrix();

    int intValue;
    cout << "\nEnter an integer value: ";
    cin >> intValue;

   
    sortRows(intValue);

    cout << "\nMatrix after sorting rows in descending order:" << endl;
    printMatrix();

    if (writeToDisk(matrix)) {
        cout << "\nMatrix has been written to the file 'matrix.txt'.\n";
    } else { // використання операторів
        cout << "\nFailed to write matrix to the file.\n";
    }

    return 0;
}