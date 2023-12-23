#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> mas(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> mas[i];
    }

    // Group elements into buckets
    vector<vector<int> > buckets(3);
    for (int i = 0; i < n; ++i)
    {
        buckets[mas[i] % 3].push_back(mas[i]);
    }

    sort(buckets[0].begin(), buckets[0].end());
    sort(buckets[1].begin(), buckets[1].end(), greater<int>());
    sort(buckets[2].begin(), buckets[2].end());

    mas.clear();
    mas.insert(mas.end(), buckets[0].begin(), buckets[0].end());
    mas.insert(mas.end(), buckets[1].begin(), buckets[1].end());
    mas.insert(mas.end(), buckets[2].begin(), buckets[2].end());

    auto last_unique = unique(mas.begin(), mas.end());
    mas.resize(distance(mas.begin(), last_unique));

    cout << mas.size() << endl;
    for (int i = 0; i < mas.size(); ++i)
    {
        cout << mas[i] << " ";
    }
    cout << endl;

    return 0;
}
