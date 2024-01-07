#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n, k, value;
    cin >> n >> k;

    vector<int> vector = {};
    for (int i = 0; i < n; i++) {

        cin >> value;
        vector.push_back(value);
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (vector[j] < vector[j - 1])
                swap(vector[j], vector[j - 1]);
        }
    }

    for (int i = 0; i < vector.size() - 1; i++)
    {
        if (vector[i] == vector[i + 1])
        {
            vector.erase(vector.begin() + i);
            i--;
        }
    }

    while (k > 0)
    {
        int i = 0;
        vector.push_back(vector[i]);
        vector.erase(vector.begin());
        k--;

    }

    cout << vector.size() << endl;
    for (int i = 0; i < vector.size(); i++) {
        cout << vector[i] << " ";
    }

    return 0;
}