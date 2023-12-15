#include <iostream>
using namespace std;

int m,n;
bool status;

int main(){
  cout<<"Enter m"<<endl;
  cin>>m;
  cout<<"Enter n"<<endl;
  cin>>n;

  cout<<"m++ - n ="<<m++-n<<endl;

if(m-- >n){
bool status = true;
cout<<"m-- > n:"<<status<<endl;
}
else{
bool status = false;
cout<<"m-- > n:"<<status<<endl;
}

if(n-- >m){
bool status = true;
cout<<"n-- > m:"<<status<<endl;
}
else{
bool status = false;
cout<<"n-- > m:"<<status<<endl;
}

return 0;
}