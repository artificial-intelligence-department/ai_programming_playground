#include<iostream>
using namespace std;

int main(){
int N;
cin >> N;
int array1[N];

for(int i = 0; i < N; i++){
    cin >> array1[i];
}

int M;
cin >> M;
int array2[M];
for(int i = 0; i < M; i++){
    cin >> array2[i];
}
int sum = N+M;
int count = 0;
for(int i = 0; i < N; i++ ){
        for(int j = 0; j < M; j++){
            if(array1[i] == array2[j]){
                count++;
                break;
            }
        }
}
    cout << count << endl;
    cout << sum - count;
    return 0;
}