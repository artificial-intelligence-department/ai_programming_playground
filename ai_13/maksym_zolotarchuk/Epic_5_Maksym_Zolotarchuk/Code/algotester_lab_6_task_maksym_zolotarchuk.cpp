#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Figure 
{
    char type;
    int row;
    int col;

    Figure(char t, int r, int c) : type(t), row(r), col(c) {}
};

char isUnderAttack(const Figure& piece, int x, int y) 
{
    int a = piece.row + 1;
    int b = piece.col + 1;

    if (x == a && y == b) 
    {
        return 'X';
    }

    switch (piece.type) 
    {
    case 'P':
        return (x == a + 1 && (y == b + 1 || y == b - 1)) ? 'P' : 0;
    case 'R':
        return (x == a || y == b) ? 'R' : 0;
    case 'B':
        return (abs(x - a) == abs(y - b)) ? 'B' : 0;
    case 'N':
        return ((abs(x - a) == 2 && abs(y - b) == 1) || (abs(x - a) == 1 && abs(y - b) == 2)) ? 'N' : 0;
    case 'Q':
        return (x == a || y == b  || abs(x - a) == abs(y - b)) ? 'Q' : 0;
    case 'K':
        return (abs(x - a) <= 1 && abs(y - b) <= 1) ? 'K' : 0;
    default:
        return 0;
    }
}

bool isInvalid(char c) 
{
    return c == 'R' || c == 'P' || c == 'R' || c == 'B' || c == 'N'||  c == 'Q' || c == 'K' || c == 'X';
}

bool check(const string& str) 
{
    return all_of(str.begin(), str.end(), [](char c) { return !isInvalid(c); });
}

void processQueries(const vector<Figure>& pieces, const vector<pair<int, int>>& queries) {
    for (const auto& query : queries) 
    {
        int x = query.first;
        int y = query.second;
        string answer;

        for (const Figure& piece : pieces) 
        {
            char resultChar = isUnderAttack(piece, x, y);
            if (isalpha(resultChar)) {
                answer += resultChar;
            }
        }

        if (check(answer)) 
        {
            cout << 'O' << endl;
        }
        else {
            size_t position = answer.find('X');
            if (position != string::npos) 
            {
                cout << "X" << endl;
            }
            else 
{
                sort(answer.begin(), answer.end());
                auto it = unique(answer.begin(), answer.end());
                answer.erase(it, answer.end());
                cout << answer << endl;
            }
        }
    }
}

int main() 
{
    vector<Figure> pieces;
    vector<pair<int, int>> queries;

    for (int i = 0; i < 8; i++) 
    {
        for (int j = 0; j < 8; j++) 
        {
            char type;
            cin >> type;
            if (type != 'O') 
            {
                pieces.emplace_back(type, i, j);
            }
        }
    }

    int q, x, y;
    cin >> q;

    for (int t = 0; t < q; t++) 
    {
       cin >> x >> y;
        queries.emplace_back(x, y);
    }

    processQueries(pieces, queries);

    return 0;
}
