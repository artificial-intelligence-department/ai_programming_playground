#include <iostream>
#include <vector>


using namespace std;

int main(){
    int N, pos1, pos2, i1, i2;
    string result="-";
    cin >> N;
    int *arr = new int[N];

    for(int i = 0 ; i < N; i++){
        cin >> arr[i];
    }

    if(N==2){
        result="Stopped";
    } else if (N==1){
        result="Collision";
    }
    i1 = 0;
    i2 = N-1;
    for(; i1<N && i2>i1-1 && i2>i1+1; ){
        i1+=arr[i1];
        i2-=arr[i2];
    }
    if(i1>i2){
        result="Miss";
    }else if(i1==i2){
        result="Collision";
    }else if(i1==i2-1 || i1==i2+1){
        result="Stopped";
    }
    cout << i1 + 1 << ' '<< i2 + 1 << endl<< result << endl;
}