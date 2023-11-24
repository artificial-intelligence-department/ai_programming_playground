#include <iostream>
#include <cmath>
#include <string>
using namespace std;

main(){

    int n1,m2,a;
    
    cout << "choose m2 \n";
    cin >> m2;
    cout << "choose n1 \n";
    cin >> n1;
    cout <<"choose action \n" << "1.sum 2.difference 3.multiplication 4.devide \n";
    cin >> a;


    switch (a)
    {
    case 1:
        cout << n1 + m2 <<endl;
        break;

    case 2:
       cout << n1 - m2 <<endl;
       break;
    case 3:
        cout << n1 * m2 <<endl;
       break;
    case 4:
        cout << n1/m2 <<endl;       
       break;
    default:
        cout <<"sorry i dont now this action"<<endl;
        break;
    }
    return 0;
}