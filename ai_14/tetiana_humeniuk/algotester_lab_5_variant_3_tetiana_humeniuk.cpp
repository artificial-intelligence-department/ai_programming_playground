#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int top(int N, int M, int x, int y)
{
    int distance_to_right_top = abs(1 - x) + abs(M - y);
    int distance_to_left_top = abs(1 - x) + abs(1 - y);
    int distance_to_right_bottom = abs(N - x) + abs(M - y);
    int distance_to_left_bottom = abs(N - x) + abs(1 - y);
    return max( max(distance_to_left_bottom, distance_to_left_top), max(distance_to_right_bottom, distance_to_right_top));
}

int main()
{
    int N, M, x, y;
    cin>>N>>M;
    cin>>x>>y;
    int map[N][M];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) 
        {
            map[i][j] = 0;
        }
    }
    int apex = top(N, M, x, y);
    map[x-1][y-1] = apex;
    while(apex > 0)
    {
        for(int row = 0; row<N; row++)
        {
            for(int column = 0; column<M; column++)
            {
                if(map[row][column]==apex)
                {
                    if (row - 1 >= 0 && map[row - 1][column] == 0) map[row - 1][column] = map[row][column] - 1;
                    if (row + 1 < N && map[row + 1][column] == 0) map[row+ 1][column] = map[row][column] - 1;
                    if (column - 1 >= 0 && map[row][column - 1] == 0) map[row][column - 1] = map[row][column] - 1;
                    if (column + 1 < M && map[row][column + 1] == 0) map[row][column + 1] = map[row][column] - 1;
                }
            }
        }
        apex --;
    }
    for(int row = 0; row<N; row++)
        {
            for(int column = 0; column<M; column++)
            {
                cout<<map[row][column]<<" ";
            }
            cout<<endl;
        }

}
