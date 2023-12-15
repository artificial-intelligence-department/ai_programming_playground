#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int row[N];

    for (int i = 0; i < N; i++) {
        cin >> row[i];
    }
    int M;
    cin >> M;
    int row2;
    int united[M];
    int size = 0;

    for (int i = 0; i < M; i++) {
        cin >> row2;
        for (int j = 0; j < N; j++) {
            if (row2 == row[j]) {
                united[i] = row2;
                size++;
            } 
        }  
    }
    cout << size << endl;
    cout << (N+M)-size << endl;
}