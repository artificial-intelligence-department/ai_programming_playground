#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main() {
    long long int a1, a2, a3, a4, a5;
    cout << "Please, enter valid numbers: \n";
    cin >> a1;
    cin >> a2;
    cin >> a3;
    cin >> a4;
    cin >> a5;
    if ( (-pow(10, 12) <= a1 && a1 <= pow(10, 12)) &&
        (-pow(10, 12) <= a2 && a2 <= pow(10, 12)) &&
        (-pow(10, 12) <= a3 && a3 <= pow(10, 12)) &&
        (-pow(10, 12) <= a4 && a4 <= pow(10, 12)) &&
        (-pow(10, 12) <= a5 && a5 <= pow(10, 12)) )  {
        long long int array[5] = {a1, a2, a3, a4, a5};
        bool answer = true;
        
        for(int i = 1; i < 5; i++) {
            if(array[i - 1] < array[i]) {
                answer = false;
                break;
            }
        }

        if(array[0] > 0 && array[1] > 0 && array[2] > 0 && array[3] > 0 && array[4] > 0) {
            if(answer == true) {
                cout << "WIN";
            } else {
                cout << "LOSS";
            }
            } else {
                cout << "ERROR";
            }
    }
}


