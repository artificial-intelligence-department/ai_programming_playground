#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cout << "Enter m, n\n";
    cin >> m >> n;

    cout << "1) --m-++n = " << --m-++n << endl;
    //тепер m=m-1; n=n+1
    if (m*n < n++){
        cout << "2) m*n < n++: " << true << endl;
    }
    else{
        cout << "2) m*n < n++: " << false << endl;
    }
    //тепер n=n+1

    if (n-- > m++){
        cout << "3) n-- > m++: " <<true << endl;
    }
    else{
        cout << "3) n-- > m++: " <<false << endl;
    }
    //тепер n=n-1; m=m+1
    return 0;
}