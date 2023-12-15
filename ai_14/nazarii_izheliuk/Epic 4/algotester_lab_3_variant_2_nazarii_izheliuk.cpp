#include<iostream>

using namespace std;

int main(){
    int N, M;

    cin >> N;
    int arreaN[N];
    for(int i = 0; i < N; i++){
        cin >> arreaN[i];
    }

    cin >> M;
    int arreaM[M];
    for(int i = 0; i < M; i++){
        cin >> arreaM[i];
    }

    int count = 0; 

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(arreaN[i] == (arreaM[j])){
                count = count + 1;
            }
        }
    }
    cout << count << endl;

    cout << N + M - count;

    return 0;
}