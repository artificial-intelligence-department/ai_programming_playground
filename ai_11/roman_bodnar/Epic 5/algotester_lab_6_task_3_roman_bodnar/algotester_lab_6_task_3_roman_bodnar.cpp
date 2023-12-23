#include <iostream>
#include <vector>
#include <set>
using namespace std;

template<typename T>
void print(const set<T>& _set)
{
    cout << _set.size() << endl;
    for (auto &number : _set)
        cout << number << " ";
    cout << endl;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int> > matrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        string line;
        cin >> line;
        for (int j = 0; j < n; ++j)
        {
            // cast digit char into respective int
            matrix[i][j] = line[j] - '0';
        }
    }

    int requests;
    cin >> requests;

    for (int i = 0; i < requests; ++i)
    {
        int x, y;
        cin >> x >> y;

        set<int> possibilities;
        x--;
        y--;

        int current = matrix[x][y];
        if (current) {
            possibilities.insert(current);
            print(possibilities);
            continue;
        }

        for (int k = 1; k <= matrix.size(); ++k)
        {
            possibilities.insert(k);
        }

        for (int k = 0; k < matrix.size(); ++k)
        {
            possibilities.erase(matrix[x][k]);
            possibilities.erase(matrix[k][y]);
        }

        print(possibilities);
    }

    return 0;
}