#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N, M, x, y;
    cin >> N >> M;
    cin >> x >> y;
    int mas[N][M];

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            mas[i][j] = 0;
        }
    }
    
    int maxVal = max(x-1, N - x) + max(y-1, M - y);
    
    // Right-lower section
    for (int i = x - 1; i < N; i++){
        for (int j = y - 1; j < M; j++){
            mas[i][j] = maxVal - (j - (y-1)) - (i - (x-1));
        }
    }
    // Right-upper section
    for (int i = x - 1; i >= 0; i--){
        for (int j = y - 1; j < M; j++){
            mas[i][j] = maxVal - (j - (y-1)) - (x-1 - i);
        }
    }
    // Left-upper section
    for (int i = x - 1; i >= 0; i--){
        for (int j = y - 1; j >= 0; j--){
            mas[i][j] = maxVal - (y-1 - j) - (x-1 - i);
        }
    }
    // Left-lover section
    for (int i =  x - 1; i < N; i++){
        for (int j = y - 1; j >= 0; j--){
            mas[i][j] = maxVal - (y-1 - j) - (i - (x-1));
        }
    }
    
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cout << mas[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}