#include <iostream>
#include <vector>
#include <algorithm>

bool comparator(int a, int b) {
    return (a > b);
}

int main() {
    using namespace std;

    int N;
    cin >> N;

    vector<int> rem0, rem1, rem2;

    for (int i = 0; i < N; i++) {
        int currentElem;
        cin >> currentElem;

        (currentElem % 3 == 0) ? rem0.push_back(currentElem) : (currentElem % 3 == 1) ? rem1.push_back(currentElem) : rem2.push_back(currentElem);
    }

    sort(rem0.begin(), rem0.end());
    sort(rem1.begin(), rem1.end(), comparator);
    sort(rem2.begin(), rem2.end());

    vector<int> result;
    result.insert(result.end(), rem0.begin(), rem0.end());
    result.insert(result.end(), rem1.begin(), rem1.end());
    result.insert(result.end(), rem2.begin(), rem2.end());

    result.erase(unique(result.begin(), result.end()), result.end());
    
//   unordered_set<int> uniqSet(result.begin(), result.end());
//   result.assign(uniqSet.begin(), uniqSet.end());

    cout << result.size() << endl;
    for (int number : result) {
        cout << number << " ";
    }

    return 0;
}   

/*
bool compare(int a, int b) {
    return (a % 3 == b % 3) ? ((a % 3) % 2 == 0 ? a < b : a > b) : a % 3 < b % 3;
}

int main() {
    using namespace std;

    int N;
    cin >> N;

    vector<int> array(N);
    for (int i = 0; i < N; i++) {
        cin >> array[i];
    }

    sort(array.begin(), array.end(), compare);

    unordered_set<int> uniqueSet(array.begin(), array.end());
    array.assign(uniqueSet.begin(), uniqueSet.end());

    cout << array.size() << endl;
    for (int num : array) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
*/