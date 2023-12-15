#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    int N, M, x, y;
    cin >> N >> M;
    cin >> x >> y;

    vector<vector<int>> peak(N, vector<int> (M, 0));

    int heaightOfPeak = 0;

    for(int X = 0; X < N; X++)
    {
        for(int Y = 0; Y < M; Y++)
            {
                peak[X][Y] = abs(x - 1 - X) + abs(y - 1 - Y);

                heaightOfPeak = max(heaightOfPeak, peak[X][Y]);
            }
    }

    for(int i = 0; i <  N; i++)
    {
        for(int l = 0; l < M; l++)
        {
            peak[i][l] = heaightOfPeak - peak[i][l];
        }
    }

    for(int i = 0; i < N; i++)
    {
        for(int l = 0; l < M; l++)
        {
            cout << peak[i][l] << " ";
        }

        cout << endl;
    }

    return 0;
}
