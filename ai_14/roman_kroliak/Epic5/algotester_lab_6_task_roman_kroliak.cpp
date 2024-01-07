#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void answer(int x, int y, int a[][10], int n, vector<int> avaible_nums, vector<int>& answers){
    if (a[x-1][y-1] != 0)
    {
        answers.push_back(a[x-1][y-1]);
    }
    else{
        for (int i : avaible_nums) 
        {
            bool good = true;
            for (int j = 0; j < n; j++)
            {
                if (i == a[x-1][j])
                {
                    good = false;
                }
            }
            for (int j = 0; j < n; j++)
            {
                if (i == a[j][y-1])
                {
                    good = false;
                }
            }
            if (good) answers.push_back(i);
        }
    }
}

int main(){
    int n, q;
    cin >> n;
    int a[10][10];
    char b[10][10];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> b[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = int(b[i][j] - 48);
    cin >> q;
    int cors [q][2];
    for (int i = 0; i < q; i++)
        cin >> cors[i][0] >> cors[i][1];

    vector<int> avaible_nums;
    for (int i = 1; i <= n; i++)
        avaible_nums.push_back(i);

    for (int i = 0; i < q; i++)
    {
        vector<int> answers;
        answer(cors[i][0],cors[i][1],a,n,avaible_nums,answers);
        sort(answers.begin(), answers.end());
        cout << answers.size() << endl;
        for (int i : answers)
            cout << i << " ";
        cout << "\n\n";
    }
    return 0;
}