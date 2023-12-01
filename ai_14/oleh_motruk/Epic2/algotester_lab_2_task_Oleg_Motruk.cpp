#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n , i , x;
    cout << "Enter list size: ";
    cin >> n;
    x = n - 1; 
    vector<int> road(n);

    cout << "Enter the list's elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> road[i];
    }

    int max = road[0];
    int min = road[0];
    int diff;
    int temp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (road[j] > road[j + 1]) {
                temp = road[j];
                road[j] = road[j + 1];
                road[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (road[i] > max) {
            max = road[i];
        }
        if (road[i] < min) {
            min = road[i];
        }
        diff = max - min;
    }

    vector<int> updroad(road);

    int updmax = updroad[1];
    int updmin = updroad[1];
    int upddiff;

    for (int i = 1; i < n; i++) {
        if (updroad[i] > updmax) {
            updmax = updroad[i];
        }
        if (updroad[i] < updmin) {
            updmin = updroad[i];
        }
        upddiff = updmax - updmin;
    }


    vector<int> updroad2(road);

    int updmax2 = updroad2[0];
    int updmin2 = updroad2[0];
    int upddiff2;

    for (int i = 0 ; i < x; i++){
        if (updroad2[i] > updmax2){
            updmax2 = updroad2[i];
        }
        if (updroad2[i] < updmin2){
            updmin2 = updroad2[i];
        }
        upddiff2 = updmax2 - updmin2;
    }
    
    if (road.size() < 2){
        road[0] = 0;
        updroad[0] = 0;
        updroad2[0] = 0;
        cout << "Minimal fatigue is: " << road[0] << endl;
    }
    else if (road.size() >= 2){    
        if (upddiff2 == upddiff || upddiff < upddiff2){
            cout << "Minimal fatigue is:" << upddiff << endl;
        }
        else if (upddiff2 < upddiff){
            cout << "Minimal fatigue is:" << upddiff2 << endl;
        }
    }

}        