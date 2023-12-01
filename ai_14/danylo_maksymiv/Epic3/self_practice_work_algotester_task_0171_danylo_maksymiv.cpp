#include<iostream>
using namespace std;
#include<cmath>

int main()
{
int n,sum=0,r1,r2;
cin>>n;

int arr[n][4];

for (int i = 0; i<n; i++)
{
cin>>arr[i][0]>>arr[i][1]>>arr[i][2]>>arr[i][3];
sum+=sqrt(pow((arr[i][2]-arr[i][0]),2) + pow((arr[i][3]-arr[i][1]),2));
}

cout<<sum;

}