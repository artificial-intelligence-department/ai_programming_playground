#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    int N, Q;
    cin >> N;

    vector<string> field(N);
    for (int i = 0; i < N; i++)
    {
        cin >> field[i];
    }

    cin >> Q;

    vector<pair<int, int>> coordinates(Q);
    for (int i = 0; i < Q; i++)
    {
        cin >> coordinates[i].first >> coordinates[i].second;
        --coordinates[i].first;
        --coordinates[i].second;
    }

    for (int i = 0; i < Q; i++)
    {
        int M = 0;
        set<int> possible_numbers;

        if (field[coordinates[i].first][coordinates[i].second] != '0')
        {
            cout << '1' << endl;
            cout << field[coordinates[i].first][coordinates[i].second] << endl << endl;
            continue;
        }

        for (int j = 1; j <= N; j++)
        {
            bool yeap = false;

            for (int k = 0; k < N; k++)
            {
                if (field[coordinates[i].first][k] - '0' == j || field[k][coordinates[i].second] - '0' == j)
                {
                    yeap = true;
                    break;
                }
            }

            if (!yeap)
            {
                M++;
                possible_numbers.insert(j);
            }
        }

        cout << M << endl;

        if (M > 0)
        {
            for (int digit : possible_numbers)
            {
                cout << digit << ' ';
            }
            cout << endl;
        }

        cout << endl;
    }

    return 0;
}
