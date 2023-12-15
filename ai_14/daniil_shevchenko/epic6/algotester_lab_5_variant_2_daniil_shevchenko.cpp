// ConsoleApplication109.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    int N, M;
    cin >> N >> M;
    vector<string>cave;
    cave.resize(N);
    cin.ignore(30000, '\n');
    for (int i = 0; i < N; i++)
    {
        getline(cin, cave[i]);
    }
    for (int column = 0; column < M; column++)
    {
        
        for (int currentheight = N - 2; currentheight >= 0; currentheight--)
        {
            if (cave[currentheight][column] == 'S')
            {
                int fall = 0;
                for (int heightcheck = currentheight+1; heightcheck <= N - 1; heightcheck++)
                {

                    if (cave[heightcheck][column] == 'O')
                    {
                        fall++;
                    }
                    if (cave[heightcheck][column] == 'X')
                    {
                        break;
                    }
                    if (cave[heightcheck][column] == 'S')
                    {
                        break;
                    }
                    
                }
                if (fall > 0)
                {
                    cave[currentheight][column] = 'O';
                    cave[currentheight + fall][column] = 'S';
                }
            }
        }
    
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << cave[i][j];
        }
        cout << endl;
    }

}


