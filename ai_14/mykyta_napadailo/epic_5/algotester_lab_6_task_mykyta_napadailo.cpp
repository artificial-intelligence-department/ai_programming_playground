#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N, Q;
    cin >> N;
    string field[N];
    for (int i = 0; i < N; i++)
    {
        cin >> field[i];
    }
    cin >> Q;
    int xy[Q][2];
    for (int i = 0; i < Q; i++)
    {
        cin >> xy[i][0] >> xy[i][1];
        xy[i][0]--, xy[i][1]--;
    }

    for (int i = 0; i < Q; i++)
    {
        int M = 0;
        string answers = "";
        if (field[xy[i][0]][xy[i][1]] != '0')
        {
            cout << '1' << endl;
            cout << field[xy[i][0]][xy[i][1]] << endl << endl;
            continue;
        }
        for (int num = 1; num <= N; num++)
        {
            bool meets = false;
            for (int p = 0; p < N; p++)
            {
                if (field[xy[i][0]][p] - '0' == num || field[p][xy[i][1]] - '0' == num)
                {
                    meets = true;
                    break;
                }
            }
            if (!meets)
            {
                M++;
                answers += '0' + num;
            }
        }
        cout << M << endl;
        if (M > 0)
        {
        for (int j = 0; j < answers.length(); j++) 
        {
            cout << answers[j] << ' ';
        }
        cout << endl;
        }
        cout << endl;
    }
}