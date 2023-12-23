#include <iostream>
using namespace std;

int limit(){
    int a;
    cin >> a;
    while(true){
        if(a >= 1 && a <= 1000) break;
        else cin >> a;
    }
    return a;
}

int main(){
    int N, M;
    N = limit();
    M = limit();
    char cave[N][M];

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> cave[i][j];
        }
    }

    for(int i = N-1; i >= 0; i--){
        for(int j = 0; j < M; j++){
            if(cave[i][j]=='O'){
                for (int k=i; k>= 0; k--){
                    if (cave[k][j]=='S'){
                        cave [i][j]='S';
                        cave [k][j]='O';
                        break;
                    }
                    else if (cave[k][j]=='X') break;
                }
            }
        }
    }

    cout << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << cave[i][j];
        }
        cout << endl;
    }

    return 0;
}