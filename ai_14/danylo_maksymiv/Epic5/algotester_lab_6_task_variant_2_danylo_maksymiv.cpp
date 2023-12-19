#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool pawn   (int y, int x, char board[8][8]);
bool king   (int y, int x, char board[8][8]);
bool knight (int y, int x, char board[8][8]);
bool queen  (int y, int x, char board[8][8]);
bool bishop (int y, int x, char board[8][8]);
bool rock   (int y, int x, char board[8][8]);

int main()
{
    int q;
    char desk[8][8];

    // ввід дошки
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cin >> desk[i][j];
        }
    }

    // ввід запитів
    cin >> q;
    int inputs[q][2];
    for (int i = 0; i < q; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> inputs[i][j];
        }
    } 

    // для рожного РЯДКА із запитів
    for (int i = 0; i < q; i++)
    {
        
        int y = inputs[i][0];
        int x = inputs[i][1];
        x--;
        y--;

        vector<char> attackingFigures;

        // в клітинці фігура
        if (desk[y][x]!='O')
        {
            cout << 'X' << endl;
        }
        else
        {
            //перевірка кожної з умов
            if(pawn(y,x,desk))
            {
                attackingFigures.push_back('P');
            }
            if(rock(y,x,desk))
            {
                attackingFigures.push_back('R');
            }
            if(queen(y,x,desk))
            {
                attackingFigures.push_back('Q');
            }
            if(king(y,x,desk))
            {
                attackingFigures.push_back('K');
            }
            if(knight(y,x,desk))
            {
                attackingFigures.push_back('N');
            }
            if(bishop(y,x,desk))
            {
                attackingFigures.push_back('B');
            }

            // клітку не атакують
            if (attackingFigures.empty())
            {
                cout << "O";
            }
            else
            {
                // сортування і вивід вектора
                sort(attackingFigures.begin(), attackingFigures.end());
                auto last = unique(attackingFigures.begin(), attackingFigures.end());
                attackingFigures.resize(distance(attackingFigures.begin(), last));

                for (char a : attackingFigures)
                {
                    cout << a;
                }
            }


            cout<<endl;
            attackingFigures.clear();
        }

    }

    return 0;
}


bool pawn (int y, int x, char desk[8][8])
{
    if (y - 1 >= 0 && x + 1 < 8 && desk[y - 1][x + 1] == 'P')
    {
        return true;
    }
    if (y - 1 >= 0 && x - 1 >= 0 && desk[y - 1][x - 1] == 'P')
    {
        return true;
    }    

    return false;
}

bool rock (int y, int x, char desk[8][8])
{
    for (int j = 0; j < 8; j++)
    {
        if (y >= 0 && y < 8 && j >= 0 && j < 8 && (desk[y][j] == 'R' || desk[j][x] == 'R'))
        {
            return true;
        }
    }
    
    return false;
}

bool queen (int y, int x, char desk[8][8])
{
    for (int j = 0; j < 8; j++)
    {
        if (y >= 0 && y < 8 && j >= 0 && j < 8 && (desk[y][j] == 'Q' || desk[j][x] == 'Q'))
        {
            return true;
        }
    }
    for (int j = 1; y + j < 8 && x + j < 8; j++)
    {
        if (desk[y + j][x + j] == 'Q')
        {
            return true;
        }
    }

    for (int j = 1; y - j >= 0 && x - j >= 0; j++)
    {
        if (desk[y - j][x - j] == 'Q')
        {
            return true;
        }
    }

    for (int j = 1; y + j < 8 && x - j >= 0; ++j)
    {
        if (desk[y + j][x -j] == 'Q')
        {
            return true;
        }
    }

    for (int j = 1; y - j >= 0 && x + j < 8; ++j)
    {
        if (desk[y - j][x + j] == 'Q')
        {
            return true;
        }
    }
    return false;
}

bool bishop (int y, int x, char desk[8][8])
{
    for (int j = 1; y + j < 8 && x + j < 8; ++j)
    {
        if (desk[y + j][x + j] == 'B')
        {
            return true;
        }
    }

    for (int j = 1; y - j >= 0 && x - j >= 0; ++j)
    {
        if (desk[y - j][x - j] == 'B')
        {
            return true;
        }
    }

    for (int j = 1; y + j < 8 && x - j >= 0; ++j)
    {
        if (desk[y + j][x -j] == 'B')
        {
            return true;
        }
    }

    for (int j = 1; y - j >= 0 && x + j < 8; ++j)
    {
        if (desk[y - j][x + j] == 'B')
        {
            return true;
        }
    }    

    return false;
}

bool knight (int y, int x, char desk[8][8])
{
    if( y+2<8 && x+1<8 && desk[y+2][x+1] == 'N' )
    {
        return true;
    }
    if( y+1<8 && x+2<8 && desk[y+1][x+2] == 'N' )
    {
        return true;
    }
    if(y-1>=0 && x+2<8 && desk[y-1][x+2] == 'N'  )
    {
        return true;
    }
    if( y-2>=0 && x+1<8 && desk[y-2][x+1] == 'N' )
    {
        return true;
    }
    if(y-2>=0 && x-1>=0 && desk[y-2][x-1] == 'N'  )
    {
        return true;
    }
    if(y-1>=0 && x-2>=0  && desk[y-1][x-2] == 'N' )
    {
        return true;
    }
    if(y+1<8 && x-2>=0 && desk[y+1][x-2] == 'N'  )
    {
        return true;
    }
    if(y+2<8 && x-1>=0 && desk[y+2][x-1] == 'N'  )
    {
        return true;
    }

    return false;
}

bool king (int y, int x, char desk[8][8])
{
    if (y + 1 < 8 && x - 1 >= 0 && desk[y + 1][x - 1] == 'K')
    {
        return true;
    }
    if (y - 1 >= 0 && desk[y - 1][x] == 'K')
    {
        return true;
    }
    if (y - 1 >= 0 && x + 1 < 8 && desk[y - 1][x + 1] == 'K')
    {
        return true;
    }
    if (x + 1 < 8 && desk[y][x + 1] == 'K')
    {
        return true;
    }
    if (y + 1 < 8 && x + 1 < 8 && desk[y + 1][x + 1] == 'K')
    {
        return true;
    }
    if (y + 1 < 8 && desk[y + 1][x] == 'K')
    {
        return true;
    }
    if (y - 1 >= 0 && x - 1 >= 0 && desk[y - 1][x - 1] == 'K')
    {
        return true;
    }
    if (x - 1 >= 0 && desk[y][x - 1] == 'K')
    {
        return true;
    }

    return false;
}