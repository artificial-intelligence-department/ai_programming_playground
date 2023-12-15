#include <iostream>
using namespace std;
void printarray(int** array, int size){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void findnegative(int**& array, int size, int row){
    int** newarray = new int*[size];
    for (int i = 0; i < size; i++){
        newarray[i] = new int[size];
    }
    for (int i = 0; i < row; i++){
        for (int j = 0; j < size; j++){
            newarray[i][j] = array[i][j];
        }
    }
    for (int i = row + 1; i < size; i++){
        for (int j = 0; j < size; j++){
            newarray[i - 1][j] = array[i][j];
        }
    }
    for (int j = 0; j < size; j++){
        if (array[row][j] < 0){
            newarray[size - 1][j] = 0;
        }
        else{
            newarray[size - 1][j] = array[row][j];
        }
    }
    for (int i = 0; i < size - 1; i++) {
        delete[] array[i];
    }
    delete[] array;
    array = newarray;
}
int main(){
    int size = 3, row;
    int **array = new int*[size];
    for (int i = 0; i < size; i++){
        array[i] = new int[size];
    }
    for (int i = 0; i < size; i++){
        cout << "Enter " << i + 1 << " row: ";
        for (int j = 0; j < size; j++){
            cin >> array[i][j];
        }
    }
    cout << "Enter the number of a row: ";
    cin >> row;
    findnegative(array, size, row - 1);
    printarray(array, size);
    for (int i = 0; i < size - 1; i++) {
        delete[] array[i];
    }
    delete[] array;
    return 0;
}