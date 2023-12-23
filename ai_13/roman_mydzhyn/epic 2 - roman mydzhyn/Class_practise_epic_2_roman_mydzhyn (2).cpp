#include <iostream>
using namespace std;
int main()
{ 
long long int n;
long long int sum=0;
cin>>n;
for(int i=0; i<n; i++){
	long long int x ;
	cin >> x ;
	sum+=x-1;
}

cout<<sum<<endl;
return 0;
}
