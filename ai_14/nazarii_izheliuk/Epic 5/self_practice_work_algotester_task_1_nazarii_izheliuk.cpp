#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> aray(N);
    for (int i = 0; i < N; i++) {
        cin >> aray[i];
    }

    sort(aray.begin(), aray.end());

    auto last = unique(aray.begin(), aray.end());
    aray.erase(last, aray.end());

    rotate(aray.begin(), aray.begin() + K % aray.size(), aray.end());

    cout << aray.size() << endl;
    for (int i = 0; i < aray.size(); i++) {
        cout << aray[i] << " ";
    }

    return 0;
}
