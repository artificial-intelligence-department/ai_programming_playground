#include <iostream>
#include <string>
#include <fstream>
#include <cmathc>
using namespace std;

int main(){
    double dovzhyna = 118.872, shyryna = 91.44;
    int count1 = 0;
    int count2 = 0;
    string syrname;
    //char syrname[30];
    cin>>syrname;
    for(int i = 0; i < syrname.size(); i++){
        if(syrname[i] == 'o' || syrname[i] == 'a' || syrname[i] == 'i' || syrname[i] == 'y' || syrname[i] == 'e' || syrname[i] == 'u'){
            count1++;
        }
            count2++;
    }
    double shyryna_bukvy = count1*0.8;
    cout<<count1<<endl;
    cout<<count2;
    //Використовуючи Ваше прізвище розрахувати найменшу довжину,
    // яка необхідна для розміщення банера з Вашим прізвищем.
    double dovzhyna_syrname = shyryna_bukvy*count2;
    //1) при написанні прізвища з лівого краю поля —>  до правого

    //кількісь букв які помістяться на полі
    int number = dovzhyna/shyryna_bukvy;


    if(count1>1) {
        if(number%2==0) {
            int start_index = static_cast<int>(std::floor((number / 2) - 1));  // Початковий індекс для виведення символів
            int end_index = static_cast<int>(std::floor(start_index + 2));// Кінцевий індекс для виведення символів
        }else{
            int start_index = (number / 2) - 1;  // Початковий індекс для виведення символів
            int end_index = start_index + 2;// Кінцевий індекс для виведення символів
        }
    }else{
        int start_index = (number / 2) - 2;
        int end_index = start_index + 3;
    }
    cout << "Символи на 3-х центральних метрах при написанні прізвища з лівого краю до правого: ";
    for (int i = start_index; i < end_index; i++) {
        cout << syrname[i];
    }
    
    return 0;
}
