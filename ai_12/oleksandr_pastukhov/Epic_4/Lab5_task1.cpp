#include <iostream>
#include <algorithm>

void printMatrix(int** matrix, int N){
    for(int i = 0; i < N;i++){
        for(int j = 0;j < N;j++){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int** createMatrix(std::string inputString,int N){
    if (inputString.length() != N * N){
        std::cout << "Некоректна довжина рядка." << std::endl;
        return nullptr;
    }

    int** matrix = new int*[N];
    for(int i = 0;i < N;i++) 
        matrix[i] = new int[N];

    for(int i = 0;i < N;i++){
        std::string SubString = inputString.substr(i * N,N);
        std::sort(SubString.begin(), SubString.end());

        for (int j = 0;j < N;j++) {
            matrix[j][i] = SubString[j] - '0';
        }
    }

    return matrix;
}

void freeMatrixMemory(int** matrix, int N) {
    for (int i = 0;i < N;i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    using namespace std;
    int N;

    cout << "Введіть N: ";
    cin >> N;

    string inputString;
    cout << "Введіть рядок довжиною у " << N * N << " цифр: ";
    cin >> inputString;

    int** resultMatrix = createMatrix(inputString, N);
    if (resultMatrix != nullptr) {
        cout << "Двовимірний масив N x N з цифрами в порядку зростання в першому стовпці:" << endl;
        printMatrix(resultMatrix, N);
    }

    return 0;
}