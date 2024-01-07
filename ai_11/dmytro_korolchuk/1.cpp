#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

void mat(int mat1[10][10]){
    for(int i = 0; i<10;i++){
        for(int j = 0; j<10; j++){
            mat1[i][j] = pow(i+1, 2);
        }
    }
}

void matfloat(float mat2[10][10]){
    for(int i = 0; i<10;i++){
        for(int j = 0; j<10; j++){
            mat2[i][j] = pow(i,j)*log(abs(i+2*2*2))/(j+1);
        }
    }
}

void printMat(float mat[10][10]){
    for(int i = 0; i<10;i++){
        for(int j = 0; j<10; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}
void sortColumns(float matrix[10][10], int value) {
    for (int j = 0; j < 10; j++) {
        for (int i = 0; i < 10 - 1; i++) {
            for (int k = 0; k < 10 - i - 1; k++) {
                if (matrix[k][j] > matrix[k + 1][j]) {
                    swap(matrix[k][j], matrix[k + 1][j]);
                }
            }
        }
    }
}

void sortRows(int matrix[10][10], int value) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10 - 1; j++) {
            for (int k = 0; k < 10 - j - 1; k++) {
                if (matrix[i][k] < matrix[i][k + 1]) {
                    swap(matrix[i][k], matrix[i][k + 1]);
                }
            }
        }
    }
}
int* calculateSums(float matrix[10][10]) {
    static int sums[10]; 

    for (int j = 0; j < 10; j++) {
        float columnSum = 0.0;

        for (int k = 0; k < 4; k++) {
            int randomRow = rand() % 10;
            columnSum += matrix[randomRow][j];
        }

        if (columnSum == static_cast<int>(columnSum)) {
            sums[j] = static_cast<int>(columnSum);
        } else {
            sums[j] = 0; 
        }
    }

    return sums;
}

bool writeArrayToFile(int array[10], string fileName) {
    ofstream outputFile(fileName);
    if (outputFile.is_open()) {
        for (int i = 0; i < 10; i++) {
            outputFile << array[i] << " ";
        }
        outputFile.close();
        return true;
    } else {
        return false;
    }
}

int calculateProductFromFile(string fileName) {
    int product = 1;
    ifstream inputFile(fileName);

    if (inputFile.is_open()) {
        int value;
        while (inputFile >> value) {
            product *= value;
        }
        inputFile.close();
    } else {
        product = 0; 
    }

    return product;
}

void deleteFile(string fileName) {
    if (remove(fileName.c_str()) == 0) {
        cout << "File \"" << fileName << "\" deleted successfully.\n";
    } else {
        cout << "Error deleting file \"" << fileName << "\".\n";
    }
}

int main(){
    const int a = 37;
    int mat1[10][10];
    float mat2[10][10];
    string fileName = "output.txt";
    if(a%2==0){
        mat(mat1);
        sortRows(mat1, a);
        int* sums = calculateSums(reinterpret_cast<float(*)[10]>(mat1));
        writeArrayToFile(sums, fileName);
    }
    else if(a%2!=0){
        matfloat(mat2);
        sortColumns(mat2, a);
        int* sums = calculateSums(mat2);
        writeArrayToFile(sums, fileName);
    }
    int productFromFile = calculateProductFromFile(fileName);
    cout << productFromFile;

    deleteFile(fileName);
}