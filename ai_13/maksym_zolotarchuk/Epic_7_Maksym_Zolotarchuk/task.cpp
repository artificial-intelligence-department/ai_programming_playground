#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

 int processMatrix(int matrix[10][10], int value)
{
    srand(time(0));
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            matrix[i][j] = (rand()) / (RAND_MAX) * 10.0;
            return matrix[i][j];
        }
    }


   void bubbleSort(int a[], int n) 
   {
    for (int i = 0; i < n-1; i++) 
    {
        for (int j = 0; j < n-i-1; j++)
         {
            if (a[j] > a[j+1]) 
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}
int sum;
bool File() {
    fstream file("D:\\SI\\F1.txt");
    if (!file) {
        return false;
    }
    for (int i = 0; i < 10; i++) {
        file << sum[i] << " ";
    }
    file.close();
    return true;
}

int calculate() {
    fstream file("D:\\SI\\F1.txt");
    if (!file) {
        cout << "Error" << std;
        return -1;
    }
    int product = 1;
    int number;
    while (file >> number) {
        product *= number;
    }
    file.close();
    return product;
}


int main()
{
  const int pullRequest = 1070;

    fullMatrix();
    calculate();
    if (File()) {
        std::cout << "Succses" << std::endl;
    } else {
        std::cout << "Error" << std::endl;
    }
    int result = calculate();
    if (result != -1) {
        cout << " Result" << result << endl;
    }
    deleteFile();

  return 0;
}