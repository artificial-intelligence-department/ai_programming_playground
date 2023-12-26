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

    // Sort buckets
    for (int i = 0; i < 3; ++i)
    {
        // Sort first bucket ascending, second bucket descending
        if (i == 1)
        {
            sort(buckets[i].rbegin(), buckets[i].rend());
        }
        else
        {
            sort(buckets[i].begin(), buckets[i].end());
        }
    }

    // Merge buckets back into `mas`
    mas.clear();
    for (const auto &bucket : buckets)
    {
        mas.insert(mas.end(), bucket.begin(), bucket.end());
    }

    // Remove duplicates
    int i = 0;
    int j = 1;
    while (j < mas.size())
    {
        if (mas[i] == mas[j])
        {
            // Duplicate found, skip j
            ++j;
        }
        else
        {
            // Keep element, advance both i and j
            ++i;
            mas[i] = mas[j];
            ++j;
        }
    }
    mas.resize(i + 1); // Shrink to new size

    // Print results
    cout << mas.size() << endl;
    for (int i = 0; i < mas.size(); ++i)
    {
        cout << mas[i] << " ";
    }
    cout << endl;

    return 0;
}
