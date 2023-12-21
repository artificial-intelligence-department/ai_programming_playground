#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
        //input
    int length;
    cin >> length;

    string field[length];
    for (int i = 0; i < length; i++)
        cin >> field[i];


    int q, iteration = 0;
    cin >> q;
    int prompting[q][2];
    for (int i = 0; i < q; i++)
    {
        for (int j = 0; j < 2; j++)
            cin >> prompting[i][j];
    }

    for (int iteration = 0; iteration < q; iteration++)
    {
        int cX = prompting[iteration][0], cY = prompting[iteration][1];
        cX--; cY--;

        if (field[cX][cY] != '0')
            cout << "1" << endl << field[cX][cY] << endl << endl;
        else
        {
            vector<int> nums;

            for (int i = 0; i < length; i++)
                nums.push_back(field[i][cY] - '0');
            for (int i = 0; i < length; i++)
                nums.push_back(field[cX][i] - '0');

            int result = 0;
            for (int i = 1; i <= length; i++)
            {
                auto search = find(nums.begin(), nums.end(), i);

                if (search == nums.end())
                    result++;
            }

            cout << result << endl;
            for (int i = 1; i <= length; i++)
            {
                auto search = find(nums.begin(), nums.end(), i);

                if (search == nums.end())
                    cout << i << " ";
            }
            cout << endl << endl;
        }
    }
}