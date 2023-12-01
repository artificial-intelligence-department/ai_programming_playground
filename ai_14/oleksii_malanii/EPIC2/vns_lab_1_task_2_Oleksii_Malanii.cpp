#include <iostream>
using namespace std;
int main () {
    int m;
    int n;
    cout << "Enter m: ";
    cin >> m;
    cout << "Enter n: ";
    cin >> n;
    int result1;
    string result2;
    string result3;
    result1 = n---m;
    if (m--<n) result2 = "true"; else result2 = "false";
    if (n++>m) result3 = "true"; else result3 = "false";
    cout << "Result1 = "<< result1 <<endl;
    cout << "Result2 = "<< result2 <<endl;
    cout << "Result3 = "<< result3;
    return 0;
}