#include <iostream>
using namespace std;

int limit(){
    int a;
    bool review = false;
    cin >> a;
    while(review == false){
        if(a >= 0 && a <= 100) review = true;
        else cin >> a;
    }
    return a;
}

int main(){
    int N, M;
    int count = 0, unique;

    N = limit();
    int array1[N];
    for(int i = 0; i < N; i++){
        array1[i] = limit();
    }
    cout << endl;

    M = limit();
    int array2[M];
    for(int i = 0; i < M; i++){
        array2[i] = limit();
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(array1[i] == array2[j]){
                count++;
                break;
            }
        }
    }
    unique = N + M - count;
    cout << endl;
    cout << count << endl;
    cout << unique << endl;
    return 0;
}