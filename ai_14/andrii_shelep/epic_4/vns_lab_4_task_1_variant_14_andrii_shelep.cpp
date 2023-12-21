#include <iostream>
#include <ctime>

using namespace std;

int main(){
    int N;
    cin >> N;
    int * arr = new int [N];
    srand(time(NULL));
    for(int i = 0; i < N; i++){
        arr[i] = rand()%20;
    }
    cout << "array: ";
    for(int i = 0; i < N; i++){
        cout << arr[i] << " ";
    }
    for(int i = 0, j = N-1; i<j ;i++, j--){
        int tmp = arr[i];
        arr[i]=arr[j];
        arr[j]=tmp;
    }
    cout << endl << "rotated array: ";
    for(int i = 0; i < N; i++){
        cout << arr[i] << " ";
    }
    if(N%2 != 0){
        N--;
        int * new_arr = new int [N];
        for(int i = 0, j=0; i<N; i++, j++){
            if(j==N/2){
                i--;
            } else{
                new_arr[i]=arr[j];
            }
        }
        delete[] arr;
        arr = new_arr;
        cout << endl << "array without element: ";
        for(int i = 0; i < N; i++){
            cout << arr[i] << " ";
        }
    } 
    int new_size = N+3;
    int *final_arr = new int [new_size];
    for(int i = 0; i < 3; i++){
        final_arr[i]=arr[i+10]-2;
    }
    for(int i = 3; i < new_size; i++){
        final_arr[i]=arr[i-3];
    }
    cout << endl << "final array: ";
    for(int i = 0; i < new_size; i++){
        cout << final_arr[i] << " ";
    }
    delete[] final_arr;
    delete[] arr;
    return 0;
}