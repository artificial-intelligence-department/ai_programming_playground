#include <iostream>
using namespace std;

int main () 
{
int n, m, c;
    
    cout<<"Enter a first number\n";
    cin>>n;
    cout<<"Enter a second number\n";
    cin>>m;

   c = n++ * m ;

    cout << "The answer is " << c << '\n';

cout << "For n++ < m the eqation is ";
    if (n++ < m) 
        {
        cout<<"True\n";
        }
    else 
        {
        cout<< "False\n";
        }
cout << "For --m > m the eqation is ";
     if (--m > m) 
        {
        cout<<"True\n";
        }
    else 
        {
        cout<< "False\n";
        }

return 0;
}