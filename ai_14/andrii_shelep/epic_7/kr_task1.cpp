#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

float ** createMatrix() // функція, що створює матрицю
{
    float ** matrix = new float * [10];
    for(int i = 0; i < 10; i++){
        matrix[i] = new float[10];
    }

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            matrix[i][j]=tan(i+j); //заповнюю матрицю математичною функцією
        }
    }
    return matrix;
}

void print(float** matrix) //функція, що виводить матрицю
{
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cout << matrix[i][j] << "   ";
        }
        cout << endl;
    }
}

void deleteMatr(float** matrix) //функція що видаляє виділену пам'ять для динамічного масиву
{
    for(int i = 0; i < 10; i++){
        delete[] matrix[i];
    }
    delete[] matrix;
}

float ** Sort(float** matrix, int rows, int cols){
    for(int i = 0; i < cols-1; i++){
        for(int k = 0; k < rows-1; k++){
            for(int j = 0; j < rows - k - 1; j++){
                if(matrix[j][i]>matrix[j+1][i]){
                    float temp = matrix[j][i];
                    matrix[j][i] = matrix[j+1][i];
                    matrix[j+1][i] = temp; 
                }
            }
        }
    }
    return matrix;
}

float Sort(const int number, float n){
    float result;
    result = number * n;
    return result;
}

int * createArr(float ** matrix, int arr[]){
    for(int i = 0; i < 10; i++){
        float sum = 0;
        for(int j = 0; j < 10; j++){
            sum += matrix[j][i];
        }
        int number = static_cast<int>(trunc(sum));
        arr[i] = number;
    }
    return arr;
}

void WriteToFile(int arr[]){
    ofstream file("array.txt");
    if(file.is_open()){
        for(int i = 0; i < 10; i++){
            file << arr[i] << " ";
        }
    } else{
        cout << "error" << endl;
        return;
    }
}

void dob(){
    ifstream file("array.txt");
    string line;
    int n;
    int dob = 1;
    while(getline(file, line, ' ')){
        int n = stoi(line);
        dob *= n;
    }
    cout << endl << "Добуток:" << dob << endl;
}

void ReadFromFile() //вивід вмістимого з файлу
{
    ifstream file("array.txt");
    string line;
    while(getline(file, line)){
        cout << line;
    }
}

int main(){
    const int number = 872; //константа з номером пул реквесту

    float ** matrix = createMatrix();

    print(matrix);

    matrix = Sort(matrix, 10, 10);

    cout << endl << "sorted: " << endl;

    print(matrix);

    float n;
    cout << endl << "enter the number (float): ";
    cin >> n;
    float result = Sort(number, n);
    cout << "Добуток номера пул-реквесту та введеного числа: " << result;

    int array[10];
    createArr(matrix, array);
    cout << endl;
    for(int i = 0; i < 10; i++){
        cout << array[i] << " ";
    }

    WriteToFile(array);
    dob();
    ReadFromFile();

    deleteMatr(matrix);

    return 0;
}