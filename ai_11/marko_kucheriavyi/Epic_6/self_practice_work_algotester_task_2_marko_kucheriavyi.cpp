#include <iostream>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    char mas[N][M];
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> mas[i][j];
        }
    }
    for (int j = 0; j < M; j++){
        for (int i = N-1; i > 0; i--){
            while (i < N && mas[i-1][j] == 'S' && mas[i][j] == 'O'){
                swap(mas[i-1][j], mas[i][j]);
                i++;
            }
        }
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cout << mas[i][j];
        }
        cout << endl;
    }
    return 0;
}