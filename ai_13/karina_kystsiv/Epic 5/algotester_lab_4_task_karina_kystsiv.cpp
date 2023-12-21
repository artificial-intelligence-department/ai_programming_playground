#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int N, K;
    cin >> N >> K;

    vector<int> a(N);
    for (int &num : a) {
        cin >> num;
    }

    sort(a.begin(), a.end());
    auto last = unique(a.begin(), a.end());
    a.erase(last, a.end());


    cout << a.size() << endl;
    if (K > a.size()) {
        K %= a.size();
        rotate(a.begin(), a.begin() + K, a.end());
    }
    else
        rotate(a.begin(), a.begin() + K, a.end());
    for (int num : a) {
        cout << num << " ";
    }

    return 0;

}