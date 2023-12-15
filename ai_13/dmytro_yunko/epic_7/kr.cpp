#include <iostream>
#include <fstream>

#include <cmath>

using namespace std;

//функція яка створює матрицю 10х10 заповнену дійсними числами
float** createFloatMatrix()
{
    float** matrix = new float*[10];
    for (int i = 0; i < 10; i++)
    {
        matrix[i] = new float[10];
        for (int j = 0; j < 10; j++)
        {
            matrix[i][j] = sin(i * j);
        }
    }
    return matrix;
}
//функція яка сортує стовпці матриці за зростанням
void sortColumns(float** matrix, float PRN){
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 9; j++){
            if (matrix[j][i] > matrix[j + 1][i]){

                swap(matrix[j][i], matrix[j + 1][i]);
            }
        }
    }
}
//функція яка виводить матрицю на екран
void printMatrix (float** matrix){
    for (size_t i = 0; i < 10; i++)
    {

        for (size_t j = 0; j < 10; j++)
        {
            cout <<  matrix[i][j]<< " ";
        }
        cout<<endl;
    }
}
//фунція яка створює новий масив сум
int* createSumMatrix(float** matrix) {
    int* sums = new int[10];
    cout<< "========";

    for (size_t i = 0; i < 10; i++) {
        int sum = 0;
        for (size_t j = 0; j < 4; j++) {
            int randId = rand() % 10;
            sum += matrix[randId][i];
            cout<<matrix[randId][i]<<" ";
        }
        cout << endl;
        cout << sum << " ";
        sums[i] = sum;
    }
    return sums;
}
//функція яка записує масив сум в файл
bool writeToFile(int* ar){
    ofstream file("out.txt");
    if (!file)
    {
        cout << "Error writing file" << endl;
        return false;
    }
        cout<< "hello";
       for (size_t i = 0; i < 10; i++)
       {
            file << ar[i]<< " ";
       }
       file.close();
       return true;
       
    
    
}





int main(int argc, char const *argv[])
{
    const float PRN {866};
    float** matrix = createFloatMatrix();
    printMatrix(matrix);
    cout<<endl;
    sortColumns(matrix, PRN);
    printMatrix(matrix);
    int* sums = createSumMatrix(matrix);

    cout<< "========";
    for (size_t i = 0; i < 10; i++)
    {
        cout<<sums[i]<<" ";
    }
    writeToFile(sums);
    
    return 0;
}

