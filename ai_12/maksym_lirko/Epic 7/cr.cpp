#include <iostream>
#include <cmath> 

using namespace std;

int calculateValue(int x, float constant)  // Функція використовується для обчислення за допомогою матем. функц
{
    return static_cast<int>(-2.4 * x + 5 * x - constant);
}

void createMatrix(int matrix[10][10], int pullRequestValue, float userInputValue) 
// функція для створення матриці 10 x 10 
{
    for (int i = 1; i <= 10; i++) { // зовнішній цикл відповідає за створення стовпців
        for (int j = 1; j <= 10; j++) { // внутрішній за ствоерння рядків
            int value = calculateValue(i * j, userInputValue * pullRequestValue);
            matrix[i - 1][j - 1] = value;
        }
    }
}

void printMatrix(int matrix[10][10])  // Функція яка виводить матрицю
{
    for (int i = 0; i < 10; ++i) {   // Знову зовнішний масив який виводить стовпці
        for (int j = 0; j < 10; ++j) { //Внутрішній за рядки
            cout << matrix[i][j] << " "; // Вивід матриці
        }
        cout << endl;
    }
}

void sortRows(int matrix[10][10]) // Функція для сортування масиву за допомогою bubble sort 
{
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            for (int k = 0; k < 10 - j - 1; k++) {
                if (matrix[i][k] < matrix[i][k + 1]) {
                    for (int l = 0; l < 10; ++l) {
                        swap(matrix[i][k], matrix[i][k + 1]);
                    }
                }
            }
        }
    }
}

void calculateAndStoreColumnSums(int matrix[10][10], int sums[10]) 
{
    for (int j = 0; j < 10; ++j) {
    float columnSum = 0;
    int count = 0;
    
    for (int i = 0; i < 10; ++i) {
        if (count < 4) {
            columnSum += matrix[i][j];
            count++;
        }
    }
    
    if (columnSum == static_cast<int>(columnSum)) {
        sums[j] = static_cast<int>(columnSum);
    } else {
        int fullColumnSum = 0;
        
        for (int i = 0; i < 10; ++i) {
            fullColumnSum += matrix[i][j];
        }
        
        sums[j] = fullColumnSum;
    }
}
}

bool writeArrayToFile(int matrix[10][10], const string& filename) {
    ofstream file(filename); // Відкриваємо файл для запису

    if (file.is_open()) { // Перевіряємо, чи вдалося відкрити файл
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                file << matrix[i][j] << " "; // Записуємо значення масиву у файл
            }
            file << endl; // Перехід на новий рядок для наступного рядка матриці
        }
        file.close(); // Закриваємо файл після завершення запису
        return true; // Повертаємо true, означаючи успішний запис у файл
    } else {
        return false; // Повертаємо false, якщо відкриття файлу було невдалим
    }
}


int main() {
    int resultMatrix[10][10];  // Оголошення змінної
    const int pullRequestValue = 941; // константа з номером пул-реквесту

    const string filename = "matrix_values.txt";

    float userInputValue; // Оголошення змінної
    cout << "Enter a fractional number: ";
    cin >> userInputValue;

    createMatrix(resultMatrix, pullRequestValue, userInputValue); // виклик створення
    sortRows(resultMatrix); // виклик сортування
    printMatrix(resultMatrix); // Виклик функції виведення масиву

    int columnSums[10] = {0}; // Масив для зберігання сум

    calculateAndStoreColumnSums(resultMatrix, columnSums); // Вивід функції яка

    int resultArray[10];    // Ініціалізація масиву
    for (int i = 0; i < 10; i++) {
        resultArray[i] = columnSums[i]; // Створюється масив із 10 сум
    }

    for (int i = 0; i < 10; ++i) {
        cout << "Sum " << i + 1 << ": " << columnSums[i] << endl;   // Виведення сум стовпців або їх нульових значень
    }

    cout << "Result Array: ";
    for (int i = 0; i < 10; ++i) {
        cout << resultArray[i] << " ";   // Суми елементі виводяться у масиві
    }
    cout << endl;

      bool writeResult = writeArrayToFile(resultMatrix, filename);

    if (writeResult) {
        cout << "Matrix values were successfully written to the file '" << filename << "'." << endl;
    } else {
        cout << "Failed to write matrix values to the file." << endl;
    }

    return 0;
}


