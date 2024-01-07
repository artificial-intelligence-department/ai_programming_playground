#include <iostream>

using namespace std;

int main(){
    char cave[1000][1000];
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> cave[i][j];
        }
    }

    for(int i = 0; i < M; i++){
        for(int j = N-1; j >= 0; j--){
            if(cave[j][i]=='S'){
                int k = j+1;
                while(k<N && cave[k][i]!='X' && cave[k][i]!='S'){
                    k++;
                }
                k--;
                if(k!=j){
                    char tmp = cave[j][i];
                    cave[j][i]=cave[k][i];
                    cave[k][i]=tmp;
                }
            }
        }
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << cave[i][j];
        }
        cout << endl;
    }
    return 0;
}