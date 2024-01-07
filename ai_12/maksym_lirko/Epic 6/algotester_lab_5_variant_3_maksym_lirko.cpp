#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    int N, M, X, Y, top = 0;;

    cin >> N >> M;
    cin >> X >> Y;

    X--;
    Y--;

    int array[N][M];

    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++) 
        {
            array[i][j] = abs(X - i) + abs(Y - j);

            top = max(top, array[i][j]);
        }
    }


    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++) 
        {
            array[i][j] -= top;
            array[i][j] *= -1;
        }
    }

    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++) 
        {
            cout << array[i][j] <<"   ";
        }
        cout << endl;
    }
    return 0;
}
