#include <iostream>

using namespace std;

int main () {

double m;
cout << "Enter m :";
cin >> m;
double n;
cout << "Enter n :";
cin >> n;

cout << "--m-++n " << (--m-++n) << endl;
cout << "m*n<n++ " << (m*n<n++) << endl;
cout << "n-->m++ " << (n-->m++) << endl;



}