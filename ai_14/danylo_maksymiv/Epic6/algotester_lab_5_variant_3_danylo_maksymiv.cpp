#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, M, x, y;
    cin >> N >> M >> x >> y;
    int dx = x - 1;
    int dy = y - 1;

    int** arr = new int*[N];
    for (int i = 0; i < N; ++i)
    {
        arr[i] = new int[M];
    }

    int maxh = max({(M - y) + (N - x), (M - y) + dx, (N - x)+dy  ,dx + dy});

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++) 
        {
            arr[i][j] = maxh - abs(x - 1 - i) - abs(y - 1 - j);
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < N; ++i)
    {
        delete[] arr[i];
    }
    delete[] arr;
}
