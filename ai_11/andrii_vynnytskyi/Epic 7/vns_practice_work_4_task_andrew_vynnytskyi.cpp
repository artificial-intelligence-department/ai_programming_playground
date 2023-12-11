#include<iostream>
using namespace std;

int main()
{

        for(int i = 1; i < 10; i+=2)
    {

        for(int j = 1; j < 10; j+=2)
        {
            cout<< (i * 10 + j) * (i * 10 + j)<<' ';
        }
        cout<<endl;
    }
    return 0;
}