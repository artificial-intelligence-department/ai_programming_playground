#include <iostream>
#include <string>
using namespace std;

string Reverse (string str) {
    string new_str;
    new_str=str;
    int n = size(str);
    for (int i=0; i<size(str); i++) {
        new_str[i]=str[n-1];
        n--;
    } 
    return new_str;
}

int main () {
    string cline;
    cout << "Enter text : ";
    getline(cin, cline);
    
    cout << Reverse(cline);

    return 0;

}