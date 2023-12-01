#include <iostream>

using namespace std;

int main()
{   
    double n, m;
    cout << "Enter n and m\n";
    if(!(cin >> n && cin >> m))
    {
        cout << "Wrong input!\n";
        return 1;
    }


    cout << "n++*m is: " << n++*m << '\n';
    cout << "n++<m is: " << (n++<m) << '\n';
    cout << "m-->m is: " <<  (m-->m) << '\n';
    
    return 0;
}
