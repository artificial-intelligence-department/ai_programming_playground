#include <iostream>
#include <algorithm>


using namespace std;

int main() {
    long long int h1,s1,s2,s3,s4, h2, h3, h4; 
    long long int d1, d2, d3, d4, hmax1,hmax2,hmax3, hmax4; 

    cout << "Enter the lengths of the table legs: ";
    cin >> h1 >> h2 >> h3 >> h4;
    cout << "Enter the lengths to be cut from each leg: ";
    cin >> d1 >> d2 >> d3 >> d4;

    s1 = h1 - d1;
    hmax1 = max({s1, h2, h3, h4});
    s2= h2 - d2;
    hmax2 = max({s1, s2, h3, h4});
    s3= h3 - d3;
    hmax3 = max({s1, s2, s3, h4});
    s4= h4 - d4;
    hmax4 = max({s1, s2, s3, s4});
    
    if(d1>h1 || d2>h2 || d3>h3 || d4>h4){
        cout<<"ERROR";
    }
    else if(hmax1>=s1*2 || hmax2>=s2*2 ||hmax3>=s3*2 || hmax4>=s4*2){
        cout<<"NO";
    }
    else if(s1==s2 && s2==s3 && s3==s4){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    
    return 0;
}