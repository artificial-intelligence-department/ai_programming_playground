#include<iostream>
using namespace std;
int main()
{
    int exception=0;
    string result="YES";
    long long h1,h2,h3,h4;
    long long d1,d2,d3,d4;
    cout<<"4 leg length: ";
    cin>>h1>>h2>>h3>>h4;
    cout<<"4 length of sawing: ";
    cin>>d1>>d2>>d3>>d4;

    if(d1>h1 || d2>h2 || d3>h3 || d4>h4 )
        result="ERROR";
    if(d1<0 || d2<0 || d3<0 || d4<0)
        result="ERROR";
    if(d1==h1 || d2==h2 || d3==h3 || d4==h4 ){
        exception=1;
        if(d1!=h1 || d2!=h2 || d3!=h3 || d4!=h4 )
            result="NO";
    }


    if(h1==0)
    h1++;
    if(h2==0)
    h2++;
    if(h3==0)
    h3++;
    if(h4==0)
    h4++;

    if (result!="ERROR" && exception != 1 ){
        h1-=d1;
        if(h2/h1>=2 || h3/h1>=2 || h4/h1>=2)
            result ="NO";

        h2-=d2;
        if(h1/h2>=2 || h3/h2>=2 || h4/h2>=2)
            result="NO";
        
        h3-=d3;
        if(h1/h3>=2 || h2/h3>=2 || h4/h3>=2)
            result="NO";

        h4-=d4;
        if(h1/h4>=2 || h3/h4>=2 || h2/h4>=2)
            result="NO";
    }
    
    cout<<result;

    return 0;
}