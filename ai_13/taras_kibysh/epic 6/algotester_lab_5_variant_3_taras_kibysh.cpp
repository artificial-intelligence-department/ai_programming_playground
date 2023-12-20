#include <iostream>
#include <vector>

using namespace std;

void up(int N, int M, vector<vector<int>> &massive, int x, int y) {
    
    if (x == 0) {
        return; 
    }

    for (int i = 0; i < M; i++) {

            massive[x - 1][i] = massive[x][i] - 1;
        
    }


        up(N, M, massive, x - 1, y);
}


void down(int N, int M, vector<vector<int>> &massive, int x, int y) {

     if (x  == N-1) {
        return;  
    }

    for (int i = 0; i < M; i++) {
            massive[x+1][i] = massive[x][i] - 1;
    
    }


        down(N, M, massive, x + 1, y);
    
}


int main() {
    int N, M;
    int x, y;

    cin >> N >> M;
    cin >> x >> y;


    vector<vector<int>> field(N, vector<int>(M, 0));
    int start;
    int x1 = x, y1 = y;

    if(x*2 <= N+1 &&  y*2 <= M+1){
         start = (N - x) + (M - y);

    }
    else{
        if(x >= N/2 + 1){
            x1 = N -x +1;

        }

        if( y >= M/2 +1){
            y1 = M -y +1;
        }
        start = (N - x1) + (M - y1);
    }
    

    x--;
    y--;

    field[x][y] = start;

    int t = 1;
    for (int i = y + 1; i < M; i++) {
        field[x][i] = start - t;
        t++;
    }

    t = 1;
    for (int i = y - 1; i >= 0; i--) {
        field[x][i] = start - t;
        t++;
    }

if(N > 1){
    up(N, M, field, x, y);
    down(N, M, field, x, y);

     for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << field[i][j] << " ";
        }
        cout << endl;
    }
}
else{
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << field[i][j] << " ";
        }
        cout << endl;
    }

}


   

    return 0;
}
