#include <iostream>
using namespace std;

int main()
{
    int m,n;
    cout << "Enter m and n:\n";
    cin >> m >> n;
    cout << "RESULT m+--n: " << m+--n;
    cout << "\nRESULT m++<++n: ";
    if(m++<++n){
        cout << "TRUE";
        }
    else{
        cout << "FALSE";
        }
    cout << "\nRESULT n--<--m: ";
    if(n--<--m){
        cout << "TRUE";
        }
    else{
        cout << "FALSE";
        }
    return 0;
}