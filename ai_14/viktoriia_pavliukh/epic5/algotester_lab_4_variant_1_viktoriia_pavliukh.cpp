#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N;
    int temp = N;
    cin >> K;
    vector<int> a(N);

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if(a[j]==a[i]){
                a.erase(a.begin() + j);
                N--;
                j--;

            }
        }
    }
   if(K>a.size()) {
       K = K % N;
   }
    sort(a.begin(), a.end());

    rotate(a.begin(), a.begin() + K, a.end());

    cout<<a.size();
    cout<<endl;

    for (int i : a) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}