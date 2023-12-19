#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    size_t size_n, size_m;
    vector<int> vector_n, vector_m;
    vector<int> diff1, diff2, intersect, union_set, symmetricDiff;

    cin >> size_n;
    int temp;
    for (int i = 0; i < size_n; i++)
    {
        cin >> temp;
        vector_n.push_back(temp);
    }
    cin >> size_m;
    for (int i = 0; i < size_m; i++)
    {
        cin >> temp;
        vector_m.push_back(temp);
    }

    sort(vector_n.begin(), vector_n.end());
    sort(vector_m.begin(), vector_m.end());

    set_difference(vector_n.begin(), vector_n.end(), vector_m.begin(), vector_m.end(), back_inserter(diff1));
    set_difference(vector_m.begin(), vector_m.end(), vector_n.begin(), vector_n.end(), back_inserter(diff2));
    set_intersection(vector_m.begin(), vector_m.end(), vector_n.begin(), vector_n.end(), back_inserter(intersect));
    set_union(vector_m.begin(), vector_m.end(), vector_n.begin(), vector_n.end(), back_inserter(union_set));
    set_symmetric_difference(vector_m.begin(), vector_m.end(), vector_n.begin(), vector_n.end(), back_inserter(symmetricDiff));

    cout << diff1.size() << endl;
    for (int in : diff1)
    {
        cout << in << " ";
    }
    cout << endl
         << endl;

    cout << diff2.size() << endl;
    for (int in : diff2)
    {
        cout << in << " ";
    }
    cout << endl
         << endl;

    cout << intersect.size() << endl;
    for (int in : intersect)
    {
        cout << in << " ";
    }
    cout << endl
         << endl;

    cout << union_set.size() << endl;
    for (int in : union_set)
    {
        cout << in << " ";
    }
    cout << endl
         << endl;

    cout << symmetricDiff.size() << endl;
    for (int in : symmetricDiff)
    {
        cout << in << " ";
    }

    return 0;
}
