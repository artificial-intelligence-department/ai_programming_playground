#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void coutRes(vector<int> result, int size)
{
    sort(result.begin(), result.end());
    cout << size << endl;
    for (int element : result)
    {
        cout << element << " ";
    }
    cout << endl;
}

int main()
{
    int N;
    vector<int> V1N;
    cin >> N;
    int num;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        V1N.push_back(num);
    }

    int M;
    vector<int> V2M;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> num;
        V2M.push_back(num);
    }

    vector<int> difference;

    set_difference(V1N.begin(), V1N.end(), V2M.begin(), V2M.end(), back_inserter(difference));
    coutRes(difference, difference.size());
    difference.clear();

    set_difference(V2M.begin(), V2M.end(), V1N.begin(), V1N.end(), back_inserter(difference));
    coutRes(difference, difference.size());
    difference.clear();

    set_intersection(V1N.begin(), V1N.end(), V2M.begin(), V2M.end(), back_inserter(difference));
    coutRes(difference, difference.size());
    difference.clear();

    set_union(V1N.begin(), V1N.end(), V2M.begin(), V2M.end(), back_inserter(difference));
    coutRes(difference, difference.size());
    difference.clear();

    set_symmetric_difference(V1N.begin(), V1N.end(), V2M.begin(), V2M.end(), back_inserter(difference));
    coutRes(difference, difference.size());

    return 0;
}