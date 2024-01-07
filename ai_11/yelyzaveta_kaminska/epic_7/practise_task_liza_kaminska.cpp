#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int my_number = 891;// Додана цілочисельна константа
const string my_file = "output.txt";

float** Float_matrix() { 
    int R_1=15;
    int R_2=20;
    float** matrix = new float*[10];
    for (int i = 0; i < 10; ++i) { // for цикл
        matrix[i] = new float[10];
        for (int j = 0; j < 10; ++j) {
            matrix[i][j] = (R_1 * R_2) / (R_1 + R_2) / my_number; // математичні операції
        }
    }
    return matrix; // рекурсія функції
}
int** Int_matrix() {
    int R_1=15;
    int R_2=20;
    int** matrix = new int*[10];
    for (int i = 0; i < 10; ++i) {
        matrix[i] = new int[10];
        for (int j = 0; j < 10; ++j) {
            matrix[i][j] = (R_1 * R_2) / (R_1 + R_2) % my_number;
        }
    }
    return matrix;
}
// Функція для сортування стовпців матриці з числами з плаваючою крапкою
void sort_float(float** matrix) { // перевантаження функції
    for (int j = 0; j < 10; ++j) {
        for (int i = 0; i < 10 - 1; ++i) {
            for (int k = 0; k < 10 - i - 1; ++k) {
                if (matrix[k][j] > matrix[k + 1][j]) { // if цикл
                    float temp = matrix[k][j];
                    matrix[k][j] = matrix[k + 1][j];
                    matrix[k + 1][j] = temp;
                }
            }
        }
    }
}

void sort_int(int** matrix) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10 - 1; ++j) {
            for (int k = 0; k < 10 - j - 1; ++k) {
                if (matrix[k][i] < matrix[k + 1][i]) {
                    int temp = matrix[k][i];
                    matrix[k][i] = matrix[k + 1][i];
                    matrix[k + 1][i] = temp;
                }
            }
        }
    }
}
void Matrix_2(float** matrix) {
    float sec_p;
    cout << "Enter the float number: ";
    cin >> sec_p;

    if (my_number % 2 == 0) {
        // Виклик функції для сортування стовпців з числами з плаваючою крапкою
        sort_float(matrix);
    } else {
        // Виклик функції для сортування рядків з цілими числами
        sort_int(reinterpret_cast<int**>(matrix));
    }

    // Вивід матриці після сортування
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cout << matrix[i][j] << " "; // двовимірний масив
        }
        cout << endl;
    }
}
// Функція для генерації рандомного числа в заданому діапазоні
int rand_array(int min, int max) {
    return rand() % (max - min + 1) + min;
}
// Функція для розрахунку та створення нового масиву
int* calculateAndCreateArray(float** matrix) {
    int* resultArray = new int[10];

    for (int j = 0; j < 10; ++j) {
        int sum = 0;

        for (int k = 0; k < rand_array(3, 4); ++k) {
            int randomIndex = rand_array(0, 9);
            sum += static_cast<int>(matrix[randomIndex][j]);
        }

        resultArray[j] = sum;
    }

    return resultArray;
}
// Функція для запису значень масиву у файл
bool write(const int* array) { // операція роботи з файлу
    ofstream my_file("output.txt");

    if (!my_file.is_open()) {
        cout << "Error opening file fot reading!" << endl;
        return false;
    }

    for (int i = 0; i < 10; ++i) {
        my_file << array[i] << " ";
    }

    my_file.close();
    return true;
}
// Функція для обчислення добутку елементів у файлі та виведення результату
int calculate() {
    ifstream inFile(my_file);

    if (!inFile.is_open()) {
        cout << "Error opening file fot writing!" << endl;
        return 0;
    }

    int product = 1;
    int value;

    while (inFile >> value) {
        product *= value;
    }

    inFile.close();

    cout << "Product or the elemrnts in the file: " << product << endl;

    return product;
}
// Функція для видалення файлу
bool deleteFile() {
    if (remove(my_file.c_str()) != 0) {
        cout << "Failed to delete file(" << endl;
        return false;
    }

    cout << "File deleted successfully." << endl;
    return true;
}
int main(){
    srand(static_cast<unsigned int>(time(nullptr)));
    if (my_number % 2 == 0) {

        float** floatMatrix = Float_matrix();

        int* resultArray = calculateAndCreateArray(floatMatrix);

        cout << "New array: ";
        for (int i = 0; i < 10; ++i) {
            cout << resultArray[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                cout << floatMatrix[i][j] << " ";
            }
            cout << endl;
        }

        for (int i = 0; i < 10; ++i) {
            delete[] floatMatrix[i];
        }
        delete[] floatMatrix;
    } else {

        int** intMatrix = Int_matrix();
        int* resultArray = calculateAndCreateArray(reinterpret_cast<float**>(intMatrix));

        cout << "New array: ";
        for (int i = 0; i < 10; ++i) {
            cout << resultArray[i] << " ";
        }
        cout << endl;// оператори вводу та виводу

        if (write(resultArray)) {
            cout << "Data writed to file successfully." << endl;
        } else {
            cout << "Failed to write data to file." << endl;
        }
        delete[] resultArray;

        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                cout << intMatrix[i][j] << " ";
            }
            cout << endl;
        }

        for (int i = 0; i < 10; ++i) {
            delete[] intMatrix[i];
        }
        delete[] intMatrix;
    }
    int product = calculate();

    return 0;
}