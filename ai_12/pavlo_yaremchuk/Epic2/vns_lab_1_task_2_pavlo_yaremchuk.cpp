#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    int n = 3;
    int m = 7;

    int result1 = --m-++n;
    cout << result1 << endl;

    bool result2 = m*n<n++;
    cout << result2 << (result2 ? "true" : "false") << endl;

    bool result3 = n-- > m++;
    cout << result3 << (result3 ? "true" : "false") << endl;
    return 0;
}