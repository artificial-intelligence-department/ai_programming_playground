#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int N, M, x, y;
    cin >> N >> M >> x >> y;

    int map[N][M];
    x -= 1;
    y -= 1;
    int pick = 0;
    int step;
    int minimal = 0;
    

    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < M; ++j)
        {
            if(i == x && j == y)
            {
                map[i][j] = pick;
            }

            else
            {   
                step = abs(i - x) + abs(j - y);
                map[i][j] = pick - step; 
            }

            if(minimal > map[i][j])
            {
                minimal = map [i][j]; 
            }
        }
    }

    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < M; ++j)
        {
            cout << map[i][j] - minimal << " ";
        }
        cout << endl;
    }
}
