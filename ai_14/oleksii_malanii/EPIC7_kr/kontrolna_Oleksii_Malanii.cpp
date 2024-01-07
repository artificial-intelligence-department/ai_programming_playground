#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
const int CONSTANT = 957;
const char txt1[] = "output.txt";
vector<vector<int>> createMatrix() {
    vector<vector<int>> matrix(10,vector<int>(10));
    double x = 1.45;
    double y = 1.22;
    double z = 3.5;
    for (int i = 0; i < 10; i++)
    {
       for (int j = 0; j <  10; j++)
       {
        double a = (2 * cos(x - M_PI / 6) * CONSTANT) / (1.0 / 2 + sin(y) * sin(y));
        double b = 1 + (x * x) / (3 + (x * x) / 5);
        matrix[i][j] = static_cast<int>(a * b);
        x += 0.1;
       }
       y += 0.2;
    }
    return matrix;
}
vector<vector<double>>SortMatrix(vector<vector<double>>matrix, double floatValue0){ // Фунція Сортування
for (int col = 0; col < 10; col++)
{
   for (int i = 0; i < 10 - 1; ++i)
   {
    for (int j = 0; j < 10 - i - 1; ++j)
    {
       if (matrix[j][col] > matrix[j + 1][col])
       {
        swap(matrix[j][col], matrix[j + 1][col]);
       }
       
    }
    
   }
   
}

}
int main() {
    srand(time(0));
vector<vector<int>> IntegerMatrix = calculateMatrix();
vector<vector<double>>floatMatrix(10, vector<double>(10));
int intValue;
cout <<"Enter an integer value: ";
cin >> intValue;
double  floatValue;
cout <<"Enter Value: ";
cin >> floatValue;
floatMatrix = sortMatrix(floatMatrix, floatValue);
integerMatrix = sortMatrix(integerMatrix, intValue);
int* sumsArray = calculateSumsAndCreateArray(IntegerMatrix);
if (writeArrayToFile(sumsArray))
{
    
}

}