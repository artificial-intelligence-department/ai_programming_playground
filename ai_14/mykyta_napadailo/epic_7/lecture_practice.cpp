#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int** fillArray(int N)
{   
    int **arr = new int*[N];
    for (int i = 0; i < N; ++i) {
        arr[i] = new int[N];
    }

    for (int x = 0; x < N; x++) 
    {
        for (int y = 0; y < N; y++)
        {
            arr[x][y] = (1 + pow(sin(x + 1), 2)) / (2 + abs((x - 2 * x*x*x) / (1 + x*x*y*y*y))) + x*x*x*x;
        }
    }
    return arr;
}

void processArray(int** arr, int PR_number, int N = 10)
{
    for (int row = 0; row < N; row++) {
        for (int i = 0; i < N - 1; i++) {
            for (int j = 0; j < N - i - 1; j++) {
                if (arr[row][j] < arr[row][j + 1]) {
                    int tmp = arr[row][j];
                    arr[row][j] = arr[row][j + 1];
                    arr[row][j + 1] = tmp;
                }
            }
        }
    }
}

int* calculateSums(int** matrix, int N)
{
    int* sums = new int[10]; // Створюємо масив поза межами функції

    for (int col = 0; col < N; ++col) {
        int sum = 0;
        for (int i = 0; i < 4; ++i) {
            int randRow = rand() % N; 
            sum += matrix[randRow][col]; 
        }
        sums[col] = sum; 
    }

    return sums;
}

bool writeToFile(int* array, int size, const string& filename)
{
    ofstream file(filename);
    if (!file.is_open()) {
        return false;
    }

    for (int i = 0; i < size; ++i) {
        file << array[i] << " ";
    }
    file.close();

    return true;
}

void deleteFile(const string& filename)
{
    if (remove(filename.c_str()) != 0) {
        cout << "Error deleting file." << endl;
    } else {
        cout << "File " << filename << " was successfully deleted." << endl;
    }
}

int main()
{
    const int PR_number = 985, N = 10;
    int **array = fillArray(N);
    processArray(array, PR_number);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << array[i][j] << ' ';
        }
        cout << endl;
    }

    int* sums = calculateSums(array, N);
    bool writeResult = writeToFile(sums, N, "output.txt");
    if (writeResult) {
        cout << "Written successfully." << endl;
    } else {
        cout << "Error writing into the file" << endl;
    }

    deleteFile("output.txt");

    for (int i = 0; i < N; i++) {
        delete[] array[i];
    }
    delete[] array;
    delete[] sums;

    return 0;
}
