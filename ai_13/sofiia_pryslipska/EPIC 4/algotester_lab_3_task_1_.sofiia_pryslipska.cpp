

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int M, N;
    cin >> N;
    vector<int> numbers1(N);
    for (int i = 0; i < N; i++)
    {
        cin >> numbers1[i];
    }
    cin >> M;
    vector<int> numbers2(M);
    for (int i = 0; i < M; i++)
    {
        cin >> numbers2[i];
    }

    int common = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (numbers1[i] == numbers2[j])
            {
                common++;
                break;
            }
        }
    }

    int unique = N + M - common;

    cout << common << endl;
    cout << unique;

    return 0;
}
