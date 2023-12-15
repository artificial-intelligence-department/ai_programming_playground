#include <iostream>
#include <cmath>
using namespace std;

int main(){

    int size1;
    int size2;
    int comonElments  = 0;

    cin >> size1;

    int arr1 [size1];
    for(int i = 0; i < size1; i++){
        cin >> arr1[i];
    }
    cin >> size2;
    int arr2 [size2];
    for(int i = 0; i < size2; i++){
        cin >> arr2[i];
    }

    for(int i = 0; i < size1; i++){
       for(int j = 0; j < size2; j++ ){
        if(arr1[i] == arr2[j]){
            comonElments++;
        }
       }
    }
    
    int uniqueElements = size1 + size2 - comonElments;

    cout << comonElments << endl;
    cout << uniqueElements;

    return 0;
}