#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int N, Q;
    cin >> N;
    int playground[N][N];

    for(int i = 0; i < N; ++i)
    {
        string row;
        cin >> row;

        for(int j = 0; j < N; ++j)
        {
            playground[i][j] = row[j] - '0';
        }
    }

    cin >> Q;
    int questions[Q][2];

    for(int i = 0; i < Q; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            cin >> questions[i][j];
        }
    }

    vector <int> answer;
    
    for(int i = 0; i < Q; ++i)
    {
        int x = questions[i][0] - 1;
        int y = questions[i][1] - 1;

        int number = 1;
        for(int i = 0; i < N; ++i)
        {
            answer.push_back(number);
            number++;
        }
        if(playground[x][y] == 0)
        {
            for(int j = 0; j < N; ++j)
            {
                if(playground[j][y] != 0)
                {
                    answer.erase(remove(answer.begin(), answer.end(), playground[j][y]), answer.end());
                }

                if(playground[x][j] != 0)
                {
                    answer.erase(remove(answer.begin(), answer.end(), playground[x][j]), answer.end());
                }
            }
        }
        else
        {
            vector<int> newAnswer;
    
            for (int j = 0; j < N; ++j)
            {
                if (answer[j] == playground[x][y])
                {
                    newAnswer.push_back(answer[j]);
                }
            }

            answer = newAnswer;
        }
        
        cout << answer.size() << endl;
        for(int k = 0; k < answer.size(); ++k)
        {
            cout << answer[k] << " ";
        }
        cout << endl;

        answer.clear();
    }
    return 0;
}
