#include <iostream>

using namespace std;

int main()
{
    double U, I, R;
    cout<<"Введіть електричну напругу(В): ";
    cin>>U;
    cout<<"Введіть силу струму(А): ";
    cin>>I;
    R=U/I;
    cout<<"Електричний опір(Ом)= "<<R;
    return 0;

}