#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int N, M;
    cin >> N;
    int arrayA[100];  
    for (int i = 0; i < N; ++i){
        cin >> arrayA[i];
    }
    cin >> M;
    int arrayB[100];  
    for (int i = 0; i < M; ++i){
        cin >> arrayB[i];
    }
    sort(arrayA, arrayA + N);
    sort(arrayB, arrayB + M);
    int commonElements = 0;
    int uniqueElements = 0;
    int i = 0, j = 0;
    while (i < N && j < M){
        if (arrayA[i] < arrayB[j]){
            ++i;
        } else if (arrayB[j] < arrayA[i]){
            ++j;
        } else{
            ++commonElements;
            ++i;
            ++j;
        }
    }
    uniqueElements = N + M - commonElements;
    cout << commonElements << endl;
    cout << uniqueElements << endl;
    return 0;
}
