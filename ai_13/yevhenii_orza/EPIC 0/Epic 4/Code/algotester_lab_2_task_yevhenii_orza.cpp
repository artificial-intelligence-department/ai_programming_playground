#include <iostream>
using namespace std;

int main ( ) {
    int i;
    cin >> i;
    if (i < 1 || i > 1000){
        return 0; 
    }

    int N[i];
    for (int n = 0; n < i; n++){
        cin >> N[n];
    }

    int dron_pos1 = 1; // Start from 1 to match the problem statement
    int dron_pos2 = i; // Start from i to match the problem statement

    while((dron_pos1 < dron_pos2) && (dron_pos2 - dron_pos1 > 1)){
        dron_pos1 = dron_pos1 + N[dron_pos1 - 1];
        dron_pos2 = dron_pos2 - N[dron_pos2 - 1];
    }
    cout<<dron_pos1 << " " << dron_pos2<<endl;
   if (dron_pos1 == dron_pos2){
        cout << "Collision"<< endl;
    } else if (dron_pos2 - dron_pos1 == 1){
        cout << "Stopped" << endl;
    } else if (dron_pos1 > dron_pos2 || dron_pos1 < dron_pos2){
        cout << "Miss" << endl;
    }
    return 0;
}
