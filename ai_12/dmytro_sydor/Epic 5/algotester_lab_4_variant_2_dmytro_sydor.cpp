#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> vec;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        vec.push_back(num);
    }

    sort(vec.begin(), vec.end());
    auto new_end = unique(vec.begin(), vec.end());

    vec.erase(new_end, vec.end());

    sort(vec.begin(), vec.end());

    while (K > vec.size())
    {
        K -= vec.size();
    }
    rotate(vec.begin(), vec.begin() + K, vec.end());

    cout << vec.size() << endl;
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }

    return 0;
}
