#include <iostream>

using namespace std;

int main(){
    int n;
    int m;
    cin >> n >> m;



    cout << n+++m << endl;
    bool result2 = m-- > n;
    bool result3 = n-- > m;
    cout << result2 << endl;
    cout << result3 << endl;

    return 0;
    
}