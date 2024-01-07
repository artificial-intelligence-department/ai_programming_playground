#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

    //слон 
void bishop(int &y, int &x, char desk[8][8], vector<char> &result)
//амперант тут використовуємо щоб не створювати копій х і у, а працювати напряму
//деск ми не використовуємо посилання, бо це масив
{
    int dir1[4][2] = {{1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

    for (int i = 0; i < 4; ++i)
    {
        int dy = dir1[i][0];
        int dx = dir1[i][1];

        for (int j = 1; y + j * dy >= 0 && y + j * dy < 8 && x + j * dx >= 0 && x + j * dx < 8; ++j)
        {
            if (desk[y + j * dy][x + j * dx] == 'B')
            {
                result.push_back('B');
                return;
            }
        }
    }
}

void king(int &y, int &x, char desk[8][8], vector<char> &result)
{
        //король
    int dir2[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

    for (int i = 0; i < 8; ++i)
    {
        int ny = y + dir2[i][0];
        int nx = x + dir2[i][1];

        if (ny >= 0 && ny < 8 && nx >= 0 && nx < 8 && desk[ny][nx] == 'K')
        {
            result.push_back('K');
            break;
        }
    }
}

void queen(int &y, int &x, char desk[8][8], vector<char> &result)
{
    //королева
    int dir4[4][2] = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};

    for (int i = 0; i < 4; i++)
    {
        int dy = dir4[i][0];
        int dx = dir4[i][1];
        for (int j = 1; y + j * dy >= 0 && y + j * dy < 8 && x + j * dx >= 0 && x + j * dx < 8; j++)
        {
            if (desk[y + j * dy][x + j * dx] == 'Q')
            {
                result.push_back('Q');
                return;
            }
        }
    }

    for (int j = 0; j < 8; j++)
    {
        if ((y >= 0 && y < 8 && desk[y][j] == 'Q') || (j >= 0 && j < 8 && desk[j][x] == 'Q'))
        {
            result.push_back('Q');
            return;
        }
    }
}

void rook(int &y, int &x, char desk[8][8], vector<char> &result)
{
    //тура
    int dir5[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    for (int i = 0; i < 4; ++i)
    {
        int dy = dir5[i][0];
        int dx = dir5[i][1];

        for (int j = 1; y + j * dy >= 0 && y + j * dy < 8 && x + j * dx >= 0 && x + j * dx < 8; ++j)
        {
            if (desk[y + j * dy][x + j * dx] == 'R')
            {
                result.push_back('R');
                return;
            }
        }
    }
}


void CheckFigureOnSquare(int y, int x, char desk[8][8], vector<char> &result)
{

    bishop(y, x, desk, result);
    king(y, x, desk, result);
    //кінь
    int dir3[8][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};

    for (int i = 0; i < 8; ++i)
    {
        int ny = y + dir3[i][0];
        int nx = x + dir3[i][1];

        if (ny >= 0 && ny < 8 && nx >= 0 && nx < 8 && desk[ny][nx] == 'N')
        {
            result.push_back('N');
            break;
        }
    }
    //пішак
    if((y - 1 >= 0 && x + 1 < 8 && desk[y - 1][x + 1] == 'P') ||
        (y - 1 >= 0 && x - 1 >= 0 && desk[y - 1][x - 1] == 'P'))
        result.push_back('P');
    queen(y, x, desk, result);
    rook(y, x, desk, result);
}

int main()
{
    char desk[8][8];

    //вводимо елементи 
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            cin >> desk[i][j];
    }

    int q;
    cin >> q;
    int inputs[q][2];
    for (int i = 0; i < q; i++)
    {
        for (int j = 0; j < 2; j++)
            cin >> inputs[i][j];
    } 

        //сам код
    for (int i = 0; i < q; i++)
    {
        
        int y = inputs[i][0] - 1;
        int x = inputs[i][1] - 1;

        vector<char> result;

        //перевіряємо чи є в клітинці якась фігура
        if (desk[y][x] != 'O')
        {
            cout << 'X' << endl;
            continue;
        } else
        {
            CheckFigureOnSquare(y, x, desk, result);

            //якщо ми не додали жодної літери у відповідь (тобто клітинку ніхто не атакує)
            if (result.empty())
                cout << "O";
            else
            {
                for (char a : result)
                    cout << a;
            }
            cout << endl;
        }
    }

    return 0;
}