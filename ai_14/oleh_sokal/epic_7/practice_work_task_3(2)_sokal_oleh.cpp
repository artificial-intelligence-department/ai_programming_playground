#include <iostream>
#include <vector>
using namespace std;

int main() {
    double shift,day, month, speed;
    cin >> speed;
    shift = speed*(8-1);
    day= 2*speed*(8-1);
    month=(30-4)*2*speed*(8-1);
    cout << shift << endl;
     cout << day << endl;
      cout << month << endl;
 
    return 0;
}