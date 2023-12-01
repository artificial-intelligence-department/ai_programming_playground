#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    
    cout << *min_element(a, a + n) + *min_element(b, b + m);
    return 0;
}

