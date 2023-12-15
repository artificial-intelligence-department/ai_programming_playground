#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Введіть кількість чисел послідовності: ";
    cin>>n;

    double avarage=0;
    
    for(int i=1; i<=n; i++)
    {
        double a;
        cin>>a;
        avarage=(avarage*(i-1)+a)/i;
        cout<<"Середнє значення = "<<avarage;
    }
    return 0;
}