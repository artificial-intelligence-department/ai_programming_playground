#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double an = 0, an1 = 0, res = 0;
    int n, k = 2; //k - індекс члена
    float facn = 1.0;

    cout << "Enter n: ";
    cin >> n;

    an = pow(10, 1)/facn; //перший член        
    an1 = an*10/k; //другий член
    res=an;
    res+=an1;

    if (n==1){cout << an; return 0;}

    for (int i = 1; i < n-1; i++){
        k++; //збільшення індекса на 1
        an1=an1*10/k; //наступний член
        res+=an1;
    }
    cout << "Sum = " << res;

    return 0;
}