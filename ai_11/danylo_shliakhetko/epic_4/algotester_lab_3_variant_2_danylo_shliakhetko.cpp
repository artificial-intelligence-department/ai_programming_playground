#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arrN;

    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        arrN.push_back(input);
    }

    int m;
    cin >> m;
    vector<int> arrM;

    for (int i = 0; i < m; i++)
    {
        int input;
        cin >> input;
        arrM.push_back(input);
    }

    int repeat = 0;

    for (int i = 0; i < n; i++)
    {
        int currentNumber = arrN[i];
        int previouaRepeat = repeat;
        for (int j = 0; j < m; j++)
        {
            if (previouaRepeat == repeat && currentNumber == arrM[j])
            {
                repeat++;
            }
        }
    }

    int unique = n + m - repeat;

    cout << repeat << "\n"
         << unique;

    return 0;
}