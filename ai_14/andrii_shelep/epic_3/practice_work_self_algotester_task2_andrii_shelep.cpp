//задача з алготестеру 1792 - Стипендія
#include <iostream>

using namespace std;

int main(){
    int number;
    cin >> number;
    int mark[7];
    for(int i = 0; i < number; i++){
        cin >> mark[i];
    }
    int min_mark = mark[0];
    for(int i = 0; i < number; i++){
        if(mark[i]<=min_mark)
            min_mark = mark[i];
    }
    if(min_mark<51){
        cout << "Zabud pro stypendiiu";
    } else if(min_mark>=51 && min_mark < 90){
        cout << "Zvychaina";
    } else{
        cout << "Pidvyshchena";
    }
}