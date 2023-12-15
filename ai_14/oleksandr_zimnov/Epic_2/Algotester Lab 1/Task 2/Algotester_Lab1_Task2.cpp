#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
    int h1, h2, h3, h4, hmax, d1, d2, d3, d4;
    string answer;
    do{
    cout<<"Enter first table leg: ";
    cin>>h1;
    }
    while(h1<0 || h1>pow(10,12));
    do{
    cout<<"Enter second table leg: ";
    cin>>h2;
    }
    while(h2<0 || h2>pow(10,12));
    do{
    cout<<"Enter third table leg: ";
    cin>>h3;
    }
    while(h3<0 || h3>pow(10,12));
    do{
    cout<<"Enter fourth table leg: ";
    cin>>h4;
    }
    while(h4<0 || h4>pow(10,12));
    do{
    cout<<"Enter the cut length of the first table: ";
    cin>>d1;
    }
    while(d1<0 || d1>pow(10,12));
    do{
    cout<<"Enter the cut length of the second table: ";
    cin>>d2;
    }
    while(d2<0 || d2>pow(10,12));
    do{
    cout<<"Enter the cut length of the third table: ";
    cin>>d3;
    }
    while(d3<0 || d3>pow(10,12));
    do{
    cout<<"Enter the cut length of the fourth table: ";
    cin>>d4;
    }
    while(d4<0 || d4>pow(10,12));    
    if(d1>h1 || d2>h2 || d3>h3 || d3>h3){
        answer="ERROR";
    }
    h1-=d1;
    hmax=max({h1, h2, h3, h4});
    if(hmax>=2*h1 && answer!="ERROR"){
        answer="NO";
    }
    h2-=d2;
    hmax=max({h1, h2, h3, h4});
    if(hmax>=2*h2 && answer!="ERROR"){
        answer="NO";
    }
    h3-=d3;
    hmax=max({h1, h2, h3, h4});
    if(hmax>=2*h3 && answer!="ERROR"){
        answer="NO";
    }
    h4-=d4;
    hmax=max({h1, h2, h3, h4});
    if(hmax>=2*h4 && answer!="ERROR"){
        answer="NO";
    }
    if(h1==h2 && h2==h3 && h3==h4 && answer!="ERROR" && answer!="NO"){
        answer="YES";
    }
    cout<<answer;
}