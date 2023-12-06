#include <iostream>
#include <algorithm>
using namespace std;
int FindDecreasingSequence(int *mas,int N);
int main(){
int n;
cin>>n;
int *arr=new int[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}
 cout<<FindDecreasingSequence(arr,n);

delete[] arr;


    return 0;
}
int FindDecreasingSequence(int *mas,int N){
int f[N];

f[0]=1;
for(int i=1;i<N;i++){
    f[i]=1;
    for (int j=0;j<i;j++){
        if(mas[j]<mas[i]){
            f[i]= max(f[i],f[j]+1);
        }
    }

}
int length=1;
for(int i=0;i<N;i++){
length = max(length, f[i]);

}
return length;}