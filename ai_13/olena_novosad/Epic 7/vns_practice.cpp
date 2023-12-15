#include <iostream>
#include <cmath>
#include <vector>// використовую стандартні бібліотеки для підключкеея певного функціоналу
using namespace std;
#define N 10


double** create_matrix_double() {
    double** matrix = new double*[N];

    for (int i = 0; i < N; i++) {
        matrix[i] = new double[N];

        for (int j = 0; j < N; j++) {
            matrix[i][j] = atan(j * 10.0 + i);
        }
    }

    return matrix;
}
int** create_matrix_int() {
    int** matrix = new int*[N];

    for (int i = 0; i < N; i++) {
        matrix[i] = new int[N];

        for (int j = 0; j < N; j++) {
            matrix[i][j] = static_cast<int>(atan(j * 10.0 + i));
        }
    }

    return matrix;//код з чатику, щоб переробити вектори в масиви
}

vector<vector<double>> create_matrixDoubl(){
 vector<vector<double>> matrix;
 for (int i=0; i<N; i++){
    vector <double> matrix01;
    for(int j=0; j<N; j++){
      matrix01.push_back((atan(j*10+i)));
    }
    matrix.push_back(matrix01);
 }
return matrix;
}

vector<vector<int>> create_matrixInt(){
 vector<vector<int>> matrix;
 for (int i=0; i<N; i++){
    vector <int> matrix01;
    for(int j=0; j<N; j++){
      matrix01.push_back((atan(j*10+i)));
    }
    matrix.push_back(matrix01);
 }
return matrix;
}



int main(){
const int number = 1012;
vector<vector<double>> MATRIX = create_matrix();
if(number%2==0){
    vector<vector<double>> MATRIX = create_matrixDoubl();
} else {
    vector<vector<int>> MATRIX = create_matrixInt();
}

if(number%2==0){
     MATRIX = create_matrix_double();
} else {
     MATRIX = create_matrix_int() ;
}

return 0;
}