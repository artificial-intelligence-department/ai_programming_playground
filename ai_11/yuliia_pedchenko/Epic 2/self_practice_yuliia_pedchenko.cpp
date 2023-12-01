#include <iostream>

using namespace std;
int main()
{

    int n;
    int m;
    Start:
    cout << "your min number" << "\n";
    cin >> n;
    cout << "your max number" << "\n";
    cin >> m;
    if (m<=n) {
        cout << "your min number must be smaller than max number" << "\n";
        goto Start;
    }
    else {
    for (int i = n-1; i <= m; i++)
    {
       
        for (int j = n-1; j <= m; j++) {
            cout << " ";
            if (i==n-1 && j==n-1) {
                cout << "*";
            }
            else if(i==n-1) {
                cout << j;
            }
            else if (j==n-1) {
                cout << i;
            }
            else {
                 cout << i*j;
            }
            
        }
        cout << endl;
    }
    
}
}