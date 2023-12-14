#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int i = 0;//починаємо обрахунок з 0 степеня
    while(i<=10){//проходимо від 1 степеня до 10
        cout<<pow(2,i)<<endl;//виводимо 2 в степені і
        i++;//наступний степінь
    }
}