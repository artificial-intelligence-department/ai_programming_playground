#include <iostream>
using namespace std;

int main() {
    long int n;
    cin >> n;

    string word;
    cin >> word;

    int s = 15;

    for (int i = 0; i < n; ++i) {
        if (word[i] == 'k'){
            s = max(s - 1,0);
        } 
        else if (word[i] == 'p') 
        {
            if (s >= 1) {
                s = 15;
            } else {
                s = 0;
            }
        } 
        else if (word[i] == 'z') 
        {
            if (s >= 1) {
                s = 0;
            } else {
                s = 15;
            }
        }
       
    }

    cout << s << endl;

    return 0;
}