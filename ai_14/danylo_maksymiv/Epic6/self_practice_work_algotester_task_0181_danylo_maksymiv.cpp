#include<iostream>

using namespace std;

int main()
{
    short row,column,win;

    cin>>row;
    cin>>column;
    win=row*column;
    if (win%2==0)
    {
        cout<<"Dragon";
    }
    else
    {
        cout<<"Imp";
    }
}