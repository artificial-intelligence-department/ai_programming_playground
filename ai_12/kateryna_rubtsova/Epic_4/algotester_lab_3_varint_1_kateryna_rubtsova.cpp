#include <iostream>

using namespace std;

int main()
{
    int N, M, uni;
    cin>>N;
    int arrN[N];

    for (int i = 0; i < N; ++i) {
        cin >> arrN[i];
    }
    
    cin>>M;

    int arrM[M];

    for (int i = 0; i < M; ++i) {
        cin >> arrM[i];
    }
    int same = 0;
    for(int i = 0; i<N; ++i){
        for(int k = 0; k < M; ++k){
            if(arrN[i] == arrM[k]){
                same++;
            }
        }
    }
    uni = N + M - same;
    cout<<same<<endl;
    cout<<uni<<endl;
    

    return 0;
}