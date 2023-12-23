#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int limit(){
    int a;
    cin >> a;
    while(true){
        if(a >= 1 && a <= pow(10, 5)) break;
        else cin >> a;
    }
    return a;
}

int LimitOfArray(){
    int a;
    cin >> a;
    while(true){
        if(a >= 0 && a <= pow(10, 5)) break;
        else cin >> a;
    }
    return a;
}

int main(){
    int N, a, b, c;
    N = limit();
    
    vector<int> r(N);
    for(int i = 0; i < r.size(); i++){
        r[i] = LimitOfArray();
    }

    a = LimitOfArray();
    b = LimitOfArray();
    c = LimitOfArray();

    for(int i = 0; i < r.size(); i++){
        check: if(r[i] == a || r[i] == b || r[i] == c){
            r.erase(r.begin() + i);
            N--;
            if(r.size() == 0) break;
            goto check;
        }
    }

    if(N == 0 || N == 1){
        cout << 0 << endl;
        return 0;
    }

    int M = r.size() - 1;
    vector<int> new_r;
    for (int i = 1; i < r.size(); i++)
        for (int j = i - 1; j < i; j++)
            new_r.push_back(r[i] + r[j]);
    
    cout << endl;
    cout << new_r.size() << endl;
    for(int i = 0; i < M; i++){
        cout << new_r[i] << " ";
    }

    return 0;
}