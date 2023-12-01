#include <iostream>
using namespace std;

int main() {
  long long h1, h2, h3, h4;
  long long d1, d2, d3, d4;
  
    
    cin >> h1 >> h2 >> h3 >> h4;

    cin >> d1 >> d2 >> d3 >> d4;
    
     if (d1 > h1 ||  d2 > h2 || d3 > h3 || d4 > h4) 
    {
        cout << " ERROR" << endl;
        return 0;
    }

    h1 -= d1;
    
    long long minLeg = min(min(min(h1, h2), h3), h4);
    long long maxLeg1 = max(max(max(h1, h2), h3), h4);
    

    if (maxLeg1 >= 2 * minLeg) 
    {
        cout << "NO" << endl;
        return 0;
    }
    h2 -= d2;
    long long maxLeg2 = max(max(max(h1, h2), h3), h4);
    if (maxLeg2 >= 2 * minLeg) 
    {
        cout << "NO" << endl;
        return 0;
    }
    h3 -= d3;
    long long maxLeg3 = max(max(max(h1, h2), h3), h4);
    if (maxLeg3 >= 2 * minLeg) 
    {
        cout << "NO" << endl;
        return 0;
    }
    h4 -= d4;
    long long maxLeg4 = max(max(max(h1, h2), h3), h4);
    if (maxLeg4 >= 2 * minLeg) 
    {
        cout << "NO" << endl;
        return 0;
    }



    if(h1 == h2 && h2 == h3 && h3 == h4)
    {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}