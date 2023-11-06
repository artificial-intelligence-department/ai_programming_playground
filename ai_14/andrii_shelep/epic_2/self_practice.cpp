// algotester 0531
#include <iostream>

using namespace std;

int main(){
    int c[100], n , k;
// вводимо к-ть грошей та атракціонів
    cin >> k >> n;
// вводимо ціну на атракціони
    for (int i = 0; i< n; i++){
        cin >> c[i];
    }
// відсортовуємо ціни по порядку зростання    
    for (int j = 0; j < n - 1; j++){
        for (int i = 0; i < n - j - 1; i++) {
            if (c[i] > c[i+1]){
                int temp = c[i];
                c[i] = c[i+1];
                c[i+1] = temp;
            }
        }
    }
// тоді перевіряємо для скількох атракціонів вистачить грошей
// сума починається з першого атракціону тоді перевіряємо чи вистачить грошей, 
// якщо так, то зараховуємо атракціон і йдемо до наступного
    int amount=0;
    int sum = c[0];
    int i = 0;
    while(sum <= k && i < n){
        amount++;
        i++;
        sum += c[i];
    }

    /*int amount = 0;
    for (int i = 0, sum = c[0]; sum <=k && i < n; i++, sum+=c[i]){
        amount++;
    }*/

    cout << amount << endl;
    return 0;
}