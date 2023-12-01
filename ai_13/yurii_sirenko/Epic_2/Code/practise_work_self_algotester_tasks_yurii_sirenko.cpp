#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    char number1[100];
    char number2[100];

    cin>>number1>>number2;
    
    int current = 0;

    for(int i = 1;number1[i]!=0;i=i+2)
    {
        if(number1[i]=='u')
        {
            current = current+2;
        }
        else if(number1[i]=='y')
        {
            current = current+1;
        }
    }
    for(int i = 1;number2[i]!=0;i=i+2)
    {
        if(number2[i]=='u')
        {
            current = current+2;
        }
        else if(number2[i]=='y')
        {
            current = current+1;
        }
    }
    int o = current % 2;
    if(o>0)
    {
        current = current/2;
        for(int i = 0;i<current;i++)
        {
            cout<<"ku";
        }
        cout<<"kyu";
    }
    else if(o==0)
    {
        current = current/2;
        for(int i = 0;i<current;i++)
        {
            cout<<"ku";
        }
    }
}