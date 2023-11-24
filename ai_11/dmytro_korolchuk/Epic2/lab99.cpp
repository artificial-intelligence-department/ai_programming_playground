#include <iostream>
using namespace std;

int main(){

 int m,n,sum;
 cin>>m;
 cin>>n;
 cout<< --m - ++n <<endl;
 --n;
 ++m;
 bool res2=m*n < n++; 
 cout<<res2<<endl;
 --n;
 bool res3=n-- > m++; 
 cout<<res3<<endl;

}
