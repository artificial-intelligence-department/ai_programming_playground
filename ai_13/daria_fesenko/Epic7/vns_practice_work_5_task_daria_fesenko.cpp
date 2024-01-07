#include <iostream> //підключення бібліотек 
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std; // використання простору std для уникнення повторень
const int matrixNumber = 1001;
const char outputFileName[]= "output.txt";

int matrix [10][10];

void createMatrix(){
for (int i=0; i<10; ++i){
    for (int j=0; j<10; ++j){
        matrix[i][j] = rand() % 100;
    }
}
}

void processMatrix(float matrix[10][10], float matrixValue){
    for (int i =0; i<10; ++i){
        for(int j=10; j<19; ++j){
            if (matrix[i][j]>matrix [j+1][i]){
                swap(matrix[j][i],matrix[j+1][i]);
            }
        }
    }
}

int* calculateSum(float matrix[10][10]){
    int* sums = new int[10];


for (int i=0; i<10; ++i){
    sums[i] = static_cast<int>(sum);
}
return sums;
}

bool writeToFole(int* staticArray){
    ofstream outputFile(outputFileName);
    if (outoutFile.is_open()) {
        for (int i= 0; i<10; ++i){
            outputFile<<staticArray[i]<<" ";

        }
        outputFile.close();
        return true;
    } else{
        return false;
    }
}

int calculateProductFromFile(){
    ifstream inputFile(outputFileName);
    int product = 1;

    if (inputFile.is_open()){
        int value;
  while (inputFile >> value) {
    cout << value << "";
    product*=value;
  }
  inputFile.close();
    }
  cout<<endl;
}