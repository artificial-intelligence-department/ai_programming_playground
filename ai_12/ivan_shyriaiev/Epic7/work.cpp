#include<iostream>
#include<cmath>
#include<random>
#include<time.h>
#include<fstream>
#include<string>
using namespace std;
void deleteMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}


int** matrixMaker(int number){
    int** matrix = new int*[10];
    
    for (int i = 0; i < 10; ++i) {
        matrix[i] = new int[10]; 
        for (int j = 0; j < 10; ++j) {
            matrix[i][j] =(number*i)/((sqrt(number*2))/(j+1) -i/4) ; 
        }
    }
    return matrix;
}
int* sum(int** matrix){
    int* array = new int[10];
    for(int i =0; i<10; i++){
        array[i]= matrix[i][rand()%10 ]+matrix[i][rand()%10]+matrix[i][rand()%10];

    }
    return array;
}
int** funct2(int** matrix, int number){
    
    int i, j, k;
    bool swapped;
    srand(time(0));
    for(k=0; k<10; k++){
    for (i = 0; i < 10 - 1; i++) {
        swapped = false;
        for (j = 0; j < 10 - i - 1; j++) {
            if (matrix[k][j] < matrix[k][j + 1]) {
                swap(matrix[k][j], matrix[k][j + 1]);
                swapped = true;
            }
        }
 
        if (swapped == false)
            break;
    }
    }
 return matrix;
}

bool writeArrayToFile(int arr[], const std::string& filename) {
    std::ofstream file(filename); 
    if (file.is_open()) {
        for (int i = 0; i < 10; ++i) {
            file << arr[i] << " "; 
        }
        file.close(); 
        return true; 
    } else {
        return false; 
    }
}
int main(){
    const string str = "some.dat";
    const int number = 1005;
    if (number%2==0){
        cout<<"parne";
    } else {
        cout<<"neparne";
    }
    int** matrix=matrixMaker(number);
    for(int i =0; i<10; i++){
        cout<<"\n";
        for(int j = 0; j<10; j++){
            cout<<matrix[i][j]<<" ";
        }
    }
    cout<<"\n";
    int** sortedmatrix=funct2(matrix,number);
    for(int i =0; i<10; i++){
        cout<<"\n";
        for(int j = 0; j<10; j++){
            cout<<matrix[i][j]<<" ";
        }
    }
    cout<<"\n\n";
    int* array = sum(matrix);
    for(int i =0; i<10; i++){
        cout<<array[i]<<" ";
    }
    cout<<"\n\n"<<writeArrayToFile(array,str );


}