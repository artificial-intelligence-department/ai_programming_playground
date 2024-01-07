#include <iostream>

int main()
{
    using namespace std;

        //prompting
    char cave[1000][1000];
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cin >> cave[i][j];
    }

        //solution
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n - 1; j++)
        {
            for(int p = 0; p < n - j - 1; p++)
            {
                if(cave[p][i] == 'S' && cave[p+1][i] == 'O')
                {
                    char tmp = cave[p][i];
                    cave[p][i] = cave[p+1][i];
                    cave[p+1][i] = tmp;
                }
            }
        }
    }
    cout << endl;

        //output
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cout << cave[i][j];
        cout << endl;
    }
    
    return 0;
}