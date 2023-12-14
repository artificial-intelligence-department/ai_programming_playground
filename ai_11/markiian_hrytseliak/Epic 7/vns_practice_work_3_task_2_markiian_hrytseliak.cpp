#include <iostream>

using namespace std;

int main()
{
    double U, I, R;
    cout<<"Введіть електричну напругу(А): ";
    cin>>U;
    cout<<"Введіть силу струму(В): ";
    cin>>I;
    R=U/I;
    cout<<"Електричний опір(Ом)= "<<R;

}