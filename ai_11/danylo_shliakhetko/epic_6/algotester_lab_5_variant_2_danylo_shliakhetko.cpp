#include <iostream>
#include <vector>
using namespace std;

enum Cell
{
    O,
    S,
    X,
};

int main()
{
    vector<vector<Cell>> cave;

    int n, m;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        vector<Cell> row;
        for (int j = 0; j < m; j++)
        {
            char input;
            cin >> input;
            Cell cell = (input == 'S' ? S : (input == 'X' ? X : O));
            row.push_back(cell);
        }
        cave.push_back(row);
    }

    for (int j = 0; j < m; j++)
    {
        for (int i = n - 1; i > 0; i--)
        {
            while (i < n && cave[i - 1][j] == S && cave[i][j] == O)
            {
                Cell buff = cave[i][j];
                cave[i][j] = cave[i - 1][j];
                cave[i - 1][j] = buff;
                i++;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char output = (cave[i][j] == S ? 'S' : (cave[i][j] == X ? 'X' : 'O'));
            cout << output;
        }
        cout << "\n";
    }

    return 0;
}