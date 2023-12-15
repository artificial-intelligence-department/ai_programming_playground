#include <iostream>
#include <algorithm>


using namespace std;

int main() {

    long int h[4], d[4];
    cout << "Enter height of nizhka: ";
    for (int i=0; i<4; i++){
        cin >> h[i];
    }
    cout << "Enter height of vidpil: ";
    for (int j=0; j<4; j++){
        cin >> d[j];
    }

    if(d[0] > h[0] || d[1] > h[1] || d[2] > h[2] || d[3] > h[3]){
        cout << "ERROR" << endl;
        return 0;
    }

    for (int a=0; a<4; a++){
        if (h[a]>=0 || d[a]>=0){
            long int temp = h[a] - d[a];
            h[a] = temp;
            
            long int max_value = *max_element(h, h + 4);
            long int min_value = *min_element(h, h + 4);

            if (max_value >= 2 * min_value) {
                cout << "NO" << endl;
                exit(0);
            } else {
                continue;
            }
        } else {
            cout << "ERROR" << endl;
        }
    }

    long int min_height = *min_element(h, h + 4);

    if (min_height != 0){
        if (h[0] == h[1] && h[1] == h[2] && h[2] == h[3]) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    } 
    else {
        cout << "NO" << endl;
    }
    

    return 0;
}