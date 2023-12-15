#include <iostream>
#include <string>

using namespace std;

int main(){
    int amount = 1; 
    string strichka, compressedStrichka;
    cin >> strichka;
    for (int i = 0; i < strichka.size(); i++){
        if (strichka[i] == strichka[i + 1]){
             amount++;
        } else {
            compressedStrichka += strichka[i];
                if (amount > 1){
                    compressedStrichka += to_string(amount);
                    // to_ string для конвертації числа в стрінгове значення
                }
        amount = 1;
        }
    }
    cout << compressedStrichka << endl;
    return 0;
}