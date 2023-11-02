#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    long long hi;
    long long mi;
    long long H;
    long long M;
    cout<<"Enter hp and mana: ";
    cin>>H>>M;
    if(H<1)
        H=1;
    if(H<1)
        M=1;
    string condition="YES";
    for (int i=0;i<3;i++)
    {
        cout<<"Enter price(hp and mana): "<<endl;
        cin>>hi>>mi;
        if(hi>0 && mi>0){
            condition ="NO";
        }
        H-=hi;
        M-=mi;
        if (H<=0 || M<=0){
            condition="NO";
        }
        cout<<"H: "<<H<<endl;
        cout<<"M: "<<M<<endl;

    }
    cout<<condition;

    return 0;
}