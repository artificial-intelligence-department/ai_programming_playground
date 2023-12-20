#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int N, M, x, y;
    cin >> N;
    cin >> M;
    cin >> x;
    cin >> y;
    vector<vector<int>> map(N, vector<int>(M, 0));

    int Peak = max(x-1, N - x) + max(y-1, M - y);

    for (int i =  0; i < N; i++){
        for (int j = 0; j < M; j++){
            map[i][j] = Peak - abs((abs(y-1) - j)) - abs(abs((x-1)) - i);
        }
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cout << map[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}