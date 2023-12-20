#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    char cave[n][m];
    for(int i=0; i<n; i++)
    {
        cin.ignore();
        string input;
        cin >> input;

        for(int j=0; j<m; j++)
        {
            cave[i][j] = input[j];
        }
    }

    for(int i=n-2; i>=0; i--)
    {
        for(int j=0; j<m; j++)
        {
            if(cave[i][j] == 'S')
            {
                int counter = 1, newRow = i;
                while(i+counter<n && cave[i+counter][j] == 'O')
                {
                    newRow++;
                    counter++;
                }

                cave[i][j] = 'O';
                cave[newRow][j] = 'S';
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout << cave[i][j];
        }
        cout << endl;
    }

    return 0;
}