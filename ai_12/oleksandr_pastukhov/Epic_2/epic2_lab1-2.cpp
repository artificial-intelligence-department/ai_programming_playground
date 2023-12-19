#include<iostream>

using std::cout, std::cin, std::endl;

int main(){
    int m,n;
    cout << "Enter m and n:";
    cin >> m >> n;

    cout << "--m-++n = " << --m-++n << endl;
    cout << "m*n<n++: " << (m*n<n++) << endl;
    cout << "n-->m++: " << (n-->m++) << endl;

    return 0;
}