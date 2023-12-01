#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    long long n, kc,vc, krc,vrc;
    kc = 0;
    vc = 0;
    krc = 0;
    vrc = 0;

    cin >> n;
    cin.ignore();

    char array;
    for (int i = 0; i < n; i++){
        cin >> array;
        if (array == 'K'){
            kc++;
        }
        else
            vc++;
        if ((kc >= 11 || vc >= 11) && abs(kc - vc) >= 2){
            if (kc > vc){
                krc++;
                kc = 0;
                vc = 0;
            }
            else
                vrc++;
                kc = 0;
                vc = 0;
        }
        else
            continue;
    }
    if (kc == 0 && vc == 0){
        cout << krc << ":" << vrc << endl;
    }
    else{
        cout << krc << ":" << vrc << endl;
        cout << kc << ":" << vc << endl;
    }
    return 0;
}