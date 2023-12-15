#include <iostream>
int main(){
    using namespace std;



float m;
float n;
cout<<"write number m:";
cin>> m;

cout<<"write number n:";
cin>> n;


float result1 =(m+--n);
float result2 =(m++<++n);
float result3 =(n--< --m);
cout<<result1<<endl;
cout<<result2<<endl;
cout<<result3<<endl;



return 0;
}
