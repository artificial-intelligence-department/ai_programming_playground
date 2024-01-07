#include<bits/stdc++.h> 
using namespace std;

int main() {
    int x, z;
    float y, c;
cout << "enter amount of copybooks" << endl;
cin >> x;
cout << "enter the price of 1 copybook" << endl;
cin >> y;
cout << "enter amount of pencils" << endl;
cin >> z;
cout << "enter the price of 1 pencil" << endl;
cin >> c;

double total = x*y + z*c;
cout << total;
    return 0;
}