#include <iostream>
using namespace std;
int main() 
{
    int N, M;
    cin >> N;
    cin >> M;
    char cave[N][M];
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> cave[i][j];
        }
    }
    for (int i = N - 1; i >= 0; i--){
        for (int j = 0; j < M; j++){
            if (cave[i][j] == 'S'){
                int k = i;
                while (k+1 < N && cave[k+1][j] == 'O'){
                    swap(cave[k][j], cave[k+1][j]);
                    k++;
                }
            }
        }
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cout << cave[i][j];
        }
        cout << endl;
    }
}
