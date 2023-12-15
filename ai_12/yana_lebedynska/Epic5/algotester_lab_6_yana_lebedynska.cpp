#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

void CellCheck(const vector<string> &NUMS, int X, int Y)
{
    X--;
    Y--;

    if(NUMS[X][Y] == '0')
    {
        unordered_set<char> possibleNums;

        for(int i = 1; i <= NUMS.size(); i++)
        {
            possibleNums.insert('0' + i);
        }

        for(int i = 0; i < NUMS.size(); i++)
        {
            possibleNums.erase(NUMS[X][i]);
            possibleNums.erase(NUMS[i][Y]);
        }

        vector<char> totalResult(possibleNums.begin(), possibleNums.end());
        sort(totalResult.begin(), totalResult.end());

        cout << totalResult.size() << endl;
        for(char num : totalResult)
        {
            cout << num << " ";
        }
    }

    else
    {
        cout << "1" << endl << NUMS[X][Y];
    }

    cout << endl;
    cout << endl;
}

int main()
{
    int N, M;

    cin >> N;
    vector<string> numbers(N);

    for(string &ROW : numbers)
    {
        cin >> ROW;
    }

    cin >> M;
    int arr[M][2];

    for(int i = 0; i < M; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
    }

    for(int i = 0; i < M; i++)
    {
        CellCheck(numbers, arr[i][0], arr[i][1]);
    }

    return 0;
}
