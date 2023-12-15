#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

void sortArr (int arr[][100], int rows, int cols){
    for(int i=0; i<rows; i++)
    {
        for(int j=i+1; j<rows; j++) { if(arr[i][2]>arr[j][2])
            {
                vector<int> temp;
                for (int k = 0; k < cols; k++){
                    temp.push_back(arr[i][k]);
                    arr[i][k] = arr[j][k];
                    arr[j][k] = temp[k];
                }
            }
        }
    }
}

int main() {
    srand(time(nullptr));
    int a[100][100];
    int rows, cols;
    cin >> rows >> cols;
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            a[i][j] = rand() % 10;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            cout << a[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
    sortArr(a, rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            cout << a[i][j] << " ";
        cout << "\n";
    }
    return 0;
}