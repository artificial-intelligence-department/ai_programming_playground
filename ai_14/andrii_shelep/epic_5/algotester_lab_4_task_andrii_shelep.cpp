#include <iostream>

using namespace std;

int main(){
    int N, K;
    cin >> N >> K;

    int *a = new int [N];

    for(int i = 0; i < N; i++){
        cin >> a[i];
    }

    int new_N = N;
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            if(a[i]==a[j]){
                new_N -= 1;
                int *arr = new int [new_N];
                for(int k = 0, ind=0; k < new_N; k++, ind++){
                    if(ind == i){
                        k--;
                    } else{
                        arr[k]=a[ind];
                    }
                }
                delete[] a;
                a = arr;
                N = new_N;
                i--;
                j--;
            }
        }
    }

    for(int i = 0; i < N-1; i++){
        for(int j = 0; j < N-i-1; j++){
            if(a[j]>a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    for(int i = 0; i < N; i++){
        cerr << a[i] << " ";
    }
    cerr << endl;

    int *new_a = new int [N];
    if(K>N){
        K%=N;
    }
    for(int i = 0, j = K; j < N; i++, j++){
        new_a[i]=a[j];
    }
    for(int i = N-K, j = 0; i < N; i++, j++){
        new_a[i]=a[j];
    }

    cout << N << endl;
    for(int i = 0; i < N; i++){
        cout << new_a[i] << " ";
    }
    cout << endl;

    delete[] a;
    delete[] new_a;
    return 0;
}