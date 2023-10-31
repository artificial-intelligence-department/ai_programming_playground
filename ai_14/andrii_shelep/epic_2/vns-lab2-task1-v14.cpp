#include <iostream>
#include <math.h>

using namespace std;
// an=n!/3n^n
// an+1/an=(n/(n+1))^n
// an+1=an*(n/(n+1))^n
int main(){
    int n = 1;
    double a, f=1, s=0, a_next=1, e=0.1;
/*
Щоб порахувати суму ряду з точністю, потрібно вивести наступний член цієї суми
тоді суму потрібно обраховувати, поки наступний член не стане менший за точність
*/
    while (a_next >= e)
    {
       f = f * n; //факторіал, починаючи з одиниці
       a = f/(3*pow(n,n));
       s += a;
       a_next = a*(pow(n,n)/pow(n+1,n));
       n++;
       cout << a << " ";
    }
    cout << "sum: " << s << endl; 
    
    return 0;
}