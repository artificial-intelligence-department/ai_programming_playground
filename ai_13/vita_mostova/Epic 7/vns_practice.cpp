#include <iostream>// Використовую директиву include, щоб використати cout та cin із  заголовкового файлу <iostream>
#include <cmath>// Використовую директиву include, для використання cos із  заголовкового файлу <cmath>
#include<algorithm>//щоб використати swap
#include <fstream>//для роботи з файлами
using namespace std;//Використовую простір імен std
const int CHYSLO=993;
const int SIZE=10;
bool compare(int a, int b) {
    return a > b;
}

void createArray(int array[SIZE][SIZE]){  //створюю функцію,яка створює матрицю 10*10 та заповнює значеннями cos(i*j)( цілочисельна)
for(int i=0;i<SIZE;i++){
     for(int j=0;j<SIZE;j++){
          array[i][j]= cos(i*j);
    
     }
	}
}
void createArray(float array[SIZE][SIZE]){  //створюю функцію,яка створює матрицю 10*10 та заповнює значеннями sin(i+j)(з плаваючою комою)
for(int i=0;i<SIZE;i++){
     for(int j=0;j<SIZE;j++){
          array[i][j]= sin(i+j);
    
     }
	}
}
void printMatrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}
void printMatrix(float matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}
void sorting(float matrix[SIZE][SIZE]) {
    for (int col = 0; col < SIZE; col++) {
        sort(matrix[0] + col, matrix[SIZE] + col);
    }
}

void sorting(int matrix[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        sort(matrix[row], matrix[row] + SIZE, compare);
    }
}
int* Sums(int matrix[SIZE][SIZE]) {
    int* sums = new int[SIZE]; // Динамічно створюємо масив

    for (int i = 0; i < SIZE; i++) {
        int sum = 0;
        int count = 0;  // Лічильник елементів для визначення дробової частини

        for (int k = 0; k < 4; k++) {
            int rowRand = rand() % SIZE;
            sum += matrix[rowRand][i];
            count++;
        }

        // Перевірка наявності дробової частини та запис у масив
        if (count == 4) {
            sums[i] = sum;
        } else {
            sums[i] = sum;  
        }
    }

    return sums;
}
bool write_to_file(int array[SIZE],const string& FILE_NAME) {
    ofstream output(FILE_NAME);

    if (!output.is_open()) {
        cout<<"File can not be opened "<<endl;
        return false;
    }

    for (int i = 0; i < SIZE; i++) {
        output << array[i] << " ";
    }

    output.close();
    return true;
}
bool readAndCalculate(const string& FILE_NAME) {
    ifstream input(FILE_NAME); // оголошуємо об'єкт класу ifstream для зчитування

    if (!input.is_open()) {
        cout<<"File can not be opened "<<endl;
        return false;
    }

    int dobutok = 1; //змінна для зберігання добутку
    int value;

    while (input >> value) {
        dobutok *= value;
    }

    input.close();

   
    cout << "Product of elements in the file: " << dobutok << endl;

    return true;}
void deleteFile(const string& FILE_NAME) {
    if (remove(FILE_NAME.c_str()) != 0) {
        cout << "Operation is not successful" << endl;
    } else {
        cout << "File deleted successfully." << endl;
    }
}

int main() {
    const string FILE_NAME = "output.txt"; // Назва файлу, що використовується у програмі

    // Вибір типу матриці в залежності від парності константи CHYSLO
    if (CHYSLO % 2 != 0) {
        int myArray1[SIZE][SIZE];
        createArray(myArray1);

       
        int* result = Sums(myArray1);

  
        if (write_to_file(result, FILE_NAME)) {
            
            readAndCalculate(FILE_NAME);
           
            deleteFile(FILE_NAME);
        }

        
        delete[] result;
    } else {
        float myArray2[SIZE][SIZE];
        createArray(myArray2);

        
        sorting(myArray2);

        

        
    }

    return 0;
}
