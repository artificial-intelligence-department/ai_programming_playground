#include <iostream>

int FindMaxElement(int arr[], int size){
    int MaxElement = arr[0];
    int MaxIndex = 0;
    for(int i = 0; i < size; i++){ 
        if(arr[i] > MaxElement){
            MaxElement = arr[i];
            MaxIndex = i;
        }
    }
    return MaxIndex;
}

void cycleShift(int arr[], int size, int maxIndex){
    int *arrayshift = new int[size];
    for(int i = 0; i < size; i++){
        arrayshift[i] = arr[(i + maxIndex) % size];
    }
    for (int i = 0; i < size; ++i) {
        arr[i] = arrayshift[i];
    }
    delete[] arrayshift;
}

void MaxAndShift(int arr[][4], int rows, int cols){
    for(int i = 0; i < rows; i++){
        int maxIndex = FindMaxElement(arr[i], cols);
        cycleShift(arr[i], cols, maxIndex);   
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main(){
    const int a = 3;
    const int b = 4;
    int Matrix[a][b] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    MaxAndShift(Matrix, a, b);
   
    return 0;
}