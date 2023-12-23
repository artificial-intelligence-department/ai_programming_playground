#include <iostream>
#include <string>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    char cave[N][M];
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> cave[i][j];
        }
    }
    cout << endl;

    for (int j = 0; j < M; j++){
        for (int i = N-1; i > -1; i--){
            if (cave[i][j] == 'S'){ //пісок, що рухається
                if (cave[i+1][j] == 'O'){ //клітинка під піском вільна
                    cave[i+1][j] = 'S';
                    cave[i][j] = 'O';
                    i=N-1;
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
    return 0;
}
