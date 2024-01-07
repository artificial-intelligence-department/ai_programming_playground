#include <iostream> 
#include <vector> 
#include <queue> 
using namespace std; 
 
void paint_the_landscape(int N, int M, int X, int Y) { 
    vector<vector<int>> map(N, vector<int>(M, -1)); 

    queue<pair<int, int>> queue_mountain; 
    queue_mountain.push({X - 1, Y - 1}); 

    map[X - 1][Y - 1] = 0; 
    
    const int x[] = {1, -1, 0, 0}; 
    const int y[] = {0, 0, 1, -1}; 

    while (!queue_mountain.empty()) { 
        pair<int, int> current = queue_mountain.front(); 
        queue_mountain.pop(); 
        for (int i = 0; i < 4; ++i) { 
            int nx = current.first + x[i]; 
            int ny = current.second + y[i]; 
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] == -1) { 
                map[nx][ny] = map[current.first][current.second] + 1; 
                queue_mountain.push({nx, ny}); 
            } 
        } 
    } 
    int max_height = 0; 
    for (int i = 0; i < N; ++i) { 
        for (int j = 0; j < M; ++j) { 
            max_height = max(max_height, map[i][j]); 
        } 
    } 
    for (int i = 0; i < N; ++i) { 
        for (int j = 0; j < M; ++j) { 
            cout << max_height - map[i][j] << " "; 
        } 
        cout << endl; 
    } 
} 
int main() { 
    int Min = 1; 
    int Max = 1000; 

    int N, M, X, Y; 

    cin >> N >> M; 
    cin >> X >> Y; 

    if (N >= Min && N <= Max && M >= Min && M <= Max && 
        X >= Min && X <= N && Y >= Min && Y <= M) { 
        paint_the_landscape(N, M, X, Y); 
    } 
    else { 
        cout << "Invalid input, please try again."; 
    } 
    return 0; 
}