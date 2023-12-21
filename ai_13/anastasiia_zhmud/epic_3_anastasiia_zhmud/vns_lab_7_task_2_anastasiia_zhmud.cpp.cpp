#include <iostream>
using namespace std;
int function(int n ,int arr[], int c) {
    int amount = arr[0];
        for (int j = 0; j < amount ; ++j) {
            int temp = arr[0];
            for (int i = 0; i < n ; ++i) {
                arr[i] = arr[i + 1];
            }
            arr[n - 1] = temp;
        }
        for(int i=0; i<n; ++i){
            cout<<arr[i];
        }
}

int function(int n, int arr[], double c) {
        int amount = arr[n-1];
        for (int j = 0; j < amount ; ++j) {
            int temp = arr[n-1];
            for (int i = n-1; i >0 ; --i) {
                arr[i] = arr[i-1];
            }
            arr[0] = temp;
        }
        for(int i=0; i<n; ++i){
            cout<<arr[i];
        }
}

int main() {

    int array1[7] = {3, 9, 8, 1, 2, 3, 2};
    bool c=array1[0]%2;
    function(7, array1, c);
    return 0;
}