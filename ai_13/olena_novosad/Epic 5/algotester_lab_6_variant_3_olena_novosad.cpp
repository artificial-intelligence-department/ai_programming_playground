#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
struct Coord
{
    int x;
    int y;
};
int N;
int Q;
vector<vector<int>> Sudoky;

void possibilityAndAnswer(Coord c)
{
    vector<int> possibleAnswer;
    for (int i = 0; i < N; i++)
    {
        if (Sudoky[c.y - 1][c.x - 1] != 0)
        {
            cout << 1 << "\n"
                 << Sudoky[c.y - 1][c.x - 1] << "\n";
            return;
        }
    }

    for (int i = 0; i < N; i++)
    {
        possibleAnswer.push_back(i + 1);
    }

    for (int i = 0; i < N; i++)
    {
        if (Sudoky[c.y - 1][i] != 0 && i != (c.x - 1))
        {
            int value = Sudoky[c.y - 1][i];
            possibleAnswer[value - 1] = 0;
        }
    }

    for (int j = 0; j < N; j++)
    {
        if (Sudoky[j][c.x - 1] != 0 && j != (c.y - 1))
        {
            int value = Sudoky[j][c.x - 1];
            possibleAnswer[value - 1] = 0;
        }
    }

    int answers = 0;
    for (int i = 0; i < possibleAnswer.size(); i++)
    {
        if (possibleAnswer[i] != 0)
        {
            answers++;
        }
    }

    cout << answers << endl;

    for (int i = 0; i < possibleAnswer.size(); i++)
    {
        if (possibleAnswer[i] != 0)
        {
            cout << possibleAnswer[i] << " ";
        }
    }
    cout << endl;
}

int main()
{

    cin >> N;
    string numbers;

    for (int i = 0; i < N; i++)
    {
        vector<int> sudoky1;

        for (int j = 0; j < N; j++)
        {
            sudoky1.push_back(0);
        }

        cin >> numbers;

        for (int i = 0; i < numbers.length(); i++)
        {
            char ch = numbers.c_str()[i];
            int elem = atoi(&ch);
            sudoky1[i] = elem;
        }

        Sudoky.push_back(sudoky1);
    }

    cin >> Q;
    vector<Coord> coords;
    for (int i = 0; i < Q; i++)
    {
        Coord c;
        cin >> c.y >> c.x;
        coords.push_back(c);
    }
    for (int i = 0; i < Q; i++)
    {
        possibilityAndAnswer(coords[i]);
    }
}
