#include <iostream>
#include <algorithm>
using namespace std;



int main()
{
long long int N,m;
cin >> N;
int arr[N];
for(int i = 0;i<N;i++)
{
    cin >> arr[i];
}
sort (arr,arr+N);


if(arr[N-1]-arr[1]>arr[N-2]-arr[0]){
    m =arr[N-2]-arr[0];
}
else {
    m = arr[N-1]-arr[1];
    }
if (N == 1)
{
   m = 0;
}
cout << m;
return 0;
}