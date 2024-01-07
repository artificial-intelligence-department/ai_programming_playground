// Шахова атака
#include <iostream>
#include <vector>

using namespace std;

class Figure
{
public:
    int x;
    int y;
    Figure()
    {
        x = 0;
        y = 0;
    }
    Figure(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

int main()
{
    int n, k = 0;;
    string line;
    vector<Figure> stars;
    bool king;

    cin >> n;
    char board[n][n];

    for(int i = 0; i < n; i++)
    {
        cin >> line;
        for(int j = 0; j < n; j++)
        {
            board[j][i] = line[j];

            if(board[j][i]  == '*')
            {   
                stars.push_back(Figure(j, i));
            }
        }
    }

    for(const auto &star : stars)
    {
        king = false;
        for(int i = -1; i < 2; i++)
        {
            for(int j = -1; j < 2; j++)
            {
                if(star.x+j >=0 && star.x+j < n && star.y+i >=0 && star.y+i < n && board[star.x + j][star.y + i] == 'K')
                {
                    king = true;
                }
            }
        }
        if(king)
        {
            continue;
        }

        if(star.y == n-1)
        {
            cout << "-1" << endl;
            return 0;
        }

        if(star.x-1 >=0 && board[star.x - 1][star.y + 1] == 'P' || star.x+1 < n && board[star.x + 1][star.y + 1] == 'P')
        {
            continue;
        }

        if(star.x-2 >=0 && board[star.x - 2][star.y] == '*' && board[star.x - 1][star.y + 1] == '-')
        {   
            king = false;
            for(int i = -1; i < 2; i++)
            {
                for(int j = -1; j < 2; j++)
                {
                    if(star.x-2 + j >=0 && star.x-2 + j < n  && star.y + i < n && board[star.x-2 + j][star.y + i] == 'K')
                    {
                        king = true;
                    }
                }
            }

            if(!(king))
            {
                if(star.x-3 >=0 && board[star.x - 3][star.y + 1] != 'P')
                {    
                    board[star.x - 1][star.y + 1] = 'P';
                    k++;
                    continue;
                }
                if(star.x-3 < 0)
                {
                    board[star.x - 1][star.y + 1] = 'P';
                    k++;
                    continue;
                }
            }
        }
        if(star.x+2 < n && board[star.x + 2][star.y] == '*' && board[star.x + 1][star.y + 1] == '-')
        {
            king = false;
            for(int i = -1; i < 2; i++)
            {
                for(int j = -1; j < 2; j++)
                {
                    if(star.x+2 + j >=0 && star.x+2 + j < n && star.y + i < n && board[star.x+2 + j][star.y + i] == 'K')
                    {
                        king = true;
                    }
                }
            }

            if (!(king))
            {
                if(star.x+3 < n && board[star.x + 3][star.y + 1] != 'P')
                {    
                    board[star.x + 1][star.y + 1] = 'P';
                    k++;
                    continue;
                }
                if(star.x+3 >= n)
                {    
                    board[star.x + 1][star.y + 1] = 'P';
                    k++;
                    continue;
                }                
            }            
        }

        if(star.x-1 >= 0 && board[star.x - 1][star.y + 1] == '-')
        {
            board[star.x - 1][star.y + 1] = 'P';
            k++;
            continue;
        }
        if(star.x+1 < n && board[star.x + 1][star.y + 1] == '-')
        {
            board[star.x + 1][star.y + 1] = 'P';
            k++;
            continue;
        }

        cout << "-1" << endl;
        return 0;
    }

    // for(int i = 0; i < n; i++)
    // {
    //     for(int j = 0; j < n; j++)
    //     {
    //         cout << board[j][i];
    //     }
    //     cout << endl;
    // }

    cout << k << endl;

    return 0;
}
