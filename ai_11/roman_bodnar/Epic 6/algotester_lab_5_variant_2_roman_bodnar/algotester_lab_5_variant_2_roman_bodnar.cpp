#include <iostream>
#include <vector>
using namespace std;

void swapping(vector<string> &_cave, int _r, int _c)
{
    if (_cave[_r][_c] != 'X') {
        return;
    }

    // u - understone
    for (int u1 = _r - 1; u1 >= 0 && _cave[u1][_c] != 'X'; u1--)
        for (int u2 = u1 - 1; u2 >= 0 && _cave[u2][_c] != 'X'; u2--)
            if (_cave[u2][_c] == 'S' && _cave[u1][_c] == 'O')
                swap(_cave[u2][_c], _cave[u1][_c]);
}

int main()
{
    int x, y;
    cin >> x >> y;

    vector<string> cave(x + 1);
    for (int i = 0; i < x; i++)
        cin >> cave[i];

    string stoneFloor(y, 'X');
    cave[x] = stoneFloor;

    // c - column
    // r - row
    for (int c = 0; c < y; c++)
        for (int r = x; r >= 0; r--)
            swapping(cave, r, c);

    for (int i = 0; i < x; ++i)
        cout << cave[i] << endl;
        
    return 0;
}
