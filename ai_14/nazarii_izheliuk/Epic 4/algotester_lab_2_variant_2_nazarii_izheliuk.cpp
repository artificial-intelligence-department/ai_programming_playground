#include <iostream>

using namespace std;

int main(){
    long long N, a, b, c;
    cin >> N;

    long long r[N];

    for(int i = 0; i < N; i++){
        cin >> r[i];
    }

    cin >> a >> b >> c;

    int n = 0;

    for(int i = 0; i < N; i++){
        if(r[i] != a && r[i] != b && r[i] != c){
            r[n++] = r[i];
        }
    }

    if(n-1 < 0){
        cout << 0;
        exit(0);
    }

    cout << n-1 << endl;

    long long M[n-1];

    for(int i = 0; i < n - 1; i++){
        M[i] = r[i] + r[i+1];
    }

    for(int i = 0; i < n-1; i++){
        cout << M[i] << " ";
    }
    return 0;
}
