#include <iostream>
using namespace std;
int main(){
    long long mas[8], sumM = 0, sumH = 0;
    for (int i = 0; i < 8; i++){
        cin >> mas[i];
    }
    sumM = mas[2] + mas[4] + mas[6];
    sumH = mas[3] + mas[5] + mas[7];
    if (sumM < mas[0] && sumH < mas[1] && mas[2] * mas[3] == 0 && mas[4] * mas[5] == 0 && mas[6] * mas[7] == 0) {
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return 0;
}