//v-1
#include <iostream>

using namespace std;

int main(){
    int arr[100];
    int size;
    int k;
    cout << "write array size (1-100): ";
    cin >> size;

    for(int i = 0; i < size; i++){
        arr[i] = rand();
        cout << arr[i] << endl;
    }

    cout << "choose the element to delete (1-" << size <<"): ";
    cin >> k;

    k--;
    size--;

    for(int j = k; j < size; j++){
        arr[j] = arr[j+1];
    }

    for(int i = 0; i < size; i++){
        if(arr[i] % 2 == 0){
            
            for(int j = size; j > i; j--){
                arr[j] = arr[j-1];
            }
            arr[i+1] = 0;
            size++;
            i++;
        }
    }
    
    for(int i = 0; i < size; i++){
        cout << arr[i] << endl;
    }

    return 0;
}