#include <iostream>
#include <vector>
using namespace std;

void findIntersection( vector<int> &a, vector<int> &b, vector<int> &c){
    for( int i = 0; i < a.size(); i++){
        for( int j = 0; j < b.size(); j++ ) {
            if(a[i] == b[j]){
            c.push_back(a[i]);
            break;
            }
        }
    }
}

int main(){ 

    int N, M, num;
    vector<int> a, b, intersec;

    cin >> N;
    for (int i=0; i<N; i++){ 
    cin >> num;
    a.push_back(num);
    }

    cin >> M;
    for (int i=0; i<M; i++){ 
    cin >> num;
    b.push_back(num);
    }

    findIntersection(a, b, intersec);
    cout << intersec.size() << endl;
    cout << (M + N) - intersec.size() << endl;
    
return 0;
}