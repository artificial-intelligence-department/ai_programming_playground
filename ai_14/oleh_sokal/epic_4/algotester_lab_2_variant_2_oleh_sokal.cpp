#include <iostream>
#include <vector>
using namespace std;
int main() {
    int N, m;
    cin >> N;

    vector<int> r(N);
    int a, b, c;
    for (int i = 0; i < N; i++) {
        cin >> r[i];
    }

    
    cin >> a >> b >> c;

    for (int i = 0; i < N; i++) {
        if (r[i] == a || r[i] == b || r[i] == c) {
            r.erase(r.begin() + i);
            i--;
            N--;
        }
    }
    m=N-1;
    if(N<2){
m=0;
    }
    cout << m << endl;
    for (int i = 0; i < m; i++) {
        cout << r[i] + r[i + 1] << endl;
    }

    return 0;
}