#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    string s;
    cin >> s;
    int x,y;
    cin >> x >> y;
    int R = 0;
    int U = 0;

    for(int i=0; i<s.size(); ++i){
      if(s[i] == 'R'){
        ++R;
      }
      else if(s[i] == 'U'){
        ++U;
      }
    }

    if(x>=0 && y>=0 && x<=R && y<=U){
      cout << "YES" << endl;
    }
    else {
      cout << "NO" << endl;
    }

    return 0;
}
