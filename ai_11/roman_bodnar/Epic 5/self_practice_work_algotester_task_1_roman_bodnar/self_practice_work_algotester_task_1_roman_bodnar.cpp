#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int count, min_repetance;
    cin >> count >> min_repetance;

    vector<string> arr(count);
    map<string, int> counts;
    set<char> c;

    for (int i = 0; i < count; ++i) {
        cin >> arr[i];
        for (int j = 0; j < arr[i].size(); j++) {
            arr[i][j] = tolower(arr[i][j]);
        }
        counts[arr[i]]++;
    }
    
    for (const auto& dict_entry : counts)
        if (dict_entry.second >= min_repetance)
            for (int i = 0; i < dict_entry.first.size(); ++i)
                c.insert(dict_entry.first[i]);

    if (c.empty()) {
        cout << "Empty!";
        return 0;
    }

    cout << c.size() << endl;
    for(auto it = c.rbegin(); it != c.rend(); ++it)
        cout << *it << " ";

    return 0;
}
