// algotester 0531 веселі каруселі
#include <iostream>

using namespace std;

int main(){
    int c[100], number , money;

    cin >> money >> number;

    for (int i = 0; i< number; i++){
        cin >> c[i];
    }

    for (int j = 0; j < number - 1; j++){
        for (int i = 0; i < number - j - 1; i++) {
            if (c[i] > c[i+1]){
                int temp = c[i];
                c[i] = c[i+1];
                c[i+1] = temp;
            }
        }
    }

    int count = 0;
    for(int i = 0; i < number; i++){
        if(money < c[i]){
            break;
        } else{
            money-=c[i];
            count++;
        }
    }

    cout << count << endl;
    return 0;
}