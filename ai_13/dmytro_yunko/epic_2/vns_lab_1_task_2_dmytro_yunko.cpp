
#include <iostream>

using namespace std;

int main()
{
    int m {0};
    int n {0};

    cin >> m;
    cin >> n;
    cout << m-++n << endl;
    bool first = ++m > --n;
    bool second = --n < ++m;
    cout <<  first << endl;
    cout <<  second << endl;


    return 0; 
}
