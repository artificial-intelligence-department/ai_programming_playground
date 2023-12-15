#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(){
    srand(time(0));
    const int lenght = 10;
    int arr[lenght];
    for (int i = 0; i < lenght; ++i){
        arr[i] = rand() % 10;
    }
    for (int i = 0; i < lenght; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
    int* newArr = new int[lenght];
    int newSize = 0;
    for (int i = 0; i < lenght; ++i){
        if (arr[i] != 0) {
            newArr[newSize++] = arr[i];
        }
    }
    for (int i = 0; i < newSize; ++i){
        if (newArr[i] % 2 == 0) {
            for (int j = newSize; j > i; --j){
                newArr[j] = newArr[j - 1];
            }
            newArr[i + 1] = newArr[i] + 2;
            ++newSize;
            break;
        }
    }
    for (int i = 0; i < newSize; ++i){
        cout << newArr[i] << " ";
    }
    cout << endl;
    delete[] newArr;
    return 0;
}
