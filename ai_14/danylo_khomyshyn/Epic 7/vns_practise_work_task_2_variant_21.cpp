#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int sides[15]; //Вимога №6: в коді використаний одновимірний масив 
    int h_a[5];
    int p; //Вимога №1: в коді використана як мінімум одна цілочисельна змінна

    for(int i=0; i<15; i++) { //Вимога №10: в коді використаний for цикл 
        if(i>=0) { //Вимога №5: в коді використані умовні оператори та розгалуження
            cin >> sides[i];
            continue;
        } else {
            break; //Вимога №11: в коді використано оператори break і continue
        }
    } 
    
    for(int i=0; i<5; i+=3) {
        p = (sides[i]+sides[i+1]+sides[i+2])/2;
        h_a[i] = 2/sides[i] * sqrt(p*(p-sides[i])*(p-sides[i+2]));
    }

    int h_a_max = h_a[0];
    int i=0;

    while (i<5){ //Вимога №9: в коді використаний while цикл
        if(h_a[i]>=h_a_max) {
            h_a_max = h_a[i];
        }
        i++;
    }

    cout << "Найбільша висота: " << h_a_max;


    return 0;
}
