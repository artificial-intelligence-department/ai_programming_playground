#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main()
{
    unsigned int N;
    cin >> N;

    vector<unsigned int> array(N);
    for(unsigned int i = 0; i < N; i++)
    {
        cin >> array[i];
    }

    vector<unsigned int> remainder0, remainder1, remainder2;
    for(unsigned int i = 0; i < N; i++)
    {
        int rem = array[i] % 3;

        if(rem == 0)
        {
            remainder0.push_back(array[i]);
        }
        else if(rem == 1)
        {
            remainder1.push_back(array[i]);
        }
        else
        {
            remainder2.push_back(array[i]);
        }
    }

    sort(remainder1.begin(), remainder1.end(), greater<int>());
    sort(remainder0.begin(), remainder0.end());
    sort(remainder2.begin(), remainder2.end());

    vector<unsigned int> result;
    result.insert(result.end(), remainder0.begin(), remainder0.end());
    result.insert(result.end(), remainder1.begin(), remainder1.end());
    result.insert(result.end(), remainder2.begin(), remainder2.end());

    auto last = unique(result.begin(), result.end());
    result.erase(last, result.end());

    cout << result.size() << endl;
    for(unsigned int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}
