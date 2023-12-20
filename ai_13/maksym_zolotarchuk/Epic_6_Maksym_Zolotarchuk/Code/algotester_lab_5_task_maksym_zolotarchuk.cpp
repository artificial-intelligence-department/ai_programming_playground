#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() 
{
    int N, M;
    cin >> N;
    cin>> M;
    vector<string> cave(N);
    for (int i = 0; i < N; ++i) 
    {
      cin >> cave[i];
    }

    for (int i = N - 1; i >= 0; --i) 
    {
        int empty = N - 1;

        for (int j = 0; j < M; ++j) 
        {
            if (cave[i][j] == 'X') 
            {
                empty = i - 1; // встановлюю позицію найнижчої пустоти
            }
            else if (cave[i][j] == 'S') 
            {
                cave[i][j] = 'O';
                cave[empty][j] = 'S';
                --empty;
            }
        }
    }
    cout << endl;

    for (string k : cave) 
    {
        cout << k << endl;
    }

    return 0;
}
