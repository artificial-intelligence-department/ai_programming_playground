#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct xy
{
    int x;
    int y;
};
const int step_x[] = {0, 1, 0, -1};
const int step_y[] = {1, 0, -1, 0};

void paintMap(vector<vector<int>> &height, int x, int y) 
{
    int N = height.size();
    int M = height[0].size();
    queue<xy> q;
    q.push({x, y});
    while (!q.empty()) 
    {
        xy current = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) 
        {
            int next_x = current.x + step_x[i];
            int next_y = current.y + step_y[i];

            if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M && height[next_x][next_y] == 0) 
            {
                height[next_x][next_y] = height[current.x][current.y] - 1;
                q.push({next_x, next_y});
            }
        }
    }
}
int main() 
{
    int N, M, x, y;
    cin >> N >> M >> x >> y;
    x--, y--;
    vector<vector<int>> height(N, vector<int>(M, 0));
    height[x][y] = N * M;
    paintMap(height, x, y);
    int min = height[0][0];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (height[i][j] < min) min = height[i][j];
        }
    }
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++) 
        {
            cout << height[i][j] - min << " ";
        }
        cout << endl;
    }
}