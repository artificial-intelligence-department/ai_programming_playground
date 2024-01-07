#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int result;
    // Вводим початкове значення x
    double x = 0.3;
    while(x <= 5){
        // обчислюєм вираз
        double y = cos(pow(x,2))*pow(M_E, -x);
        // якщо вираз відємний додаєм до result 1
        if(y<0){
        result++;
        }
    // змінюєм значення x
        x += 0.1;

    }
    // виводим результат
    cout << result;



    return 0;
}