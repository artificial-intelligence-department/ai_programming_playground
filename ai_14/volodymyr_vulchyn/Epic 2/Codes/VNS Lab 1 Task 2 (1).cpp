// 1) m-++n

#include <iostream>
using namespace std;

int main(){

        int m, n;
        cout << "Enter m: " << endl;
        cin >> m;
        cout << "Enter n: " << endl;
        cin >> n;
//  m-++n = означає що ми від числа M віднімає число N збільшене на одиницю
        cout << "Знайчення виразу дорівнює: " << (m-(++n)); 

return 0;
}