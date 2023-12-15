#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N;
    int a[N];
    for(int i=0; i<N; ++i) {
        cin >> a[i];
    }
    cin >> M;
    int b[M];
    for(int i=0; i<M; ++i) {
        cin >> b[i];
    }
    int similar=0;
    int unique=N+M;
    for(int i=0; i<N; ++i) {
        for(int j=0; j<M; ++j) {
            if(a[i] == b[j]) {
                similar++;
                unique--;
            }
        }
    }
    
    cout << similar << endl;
    cout << unique << endl;
}