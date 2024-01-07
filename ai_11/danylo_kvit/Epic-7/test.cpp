// Kvit Danylo
#include <iostream>
using namespace std;
int main(){
    // Kvit
    string s = "Kvit";
    int golos = 0; //цілочисельна змінна для підрахунку голосних у слові
    for(char i:s){   //for цикл
        char x = tolower(i);
        if(x=='i'||x=='y'||x=='o'||x=='a'||x=='u'||x=='e')golos++;
    }
    float l = 0.8*golos*s.size(); //дійсна змінна для загальної довжини
    double left = l/2-1.5;        //дійсна змінна з подвійною точністю для координати найлівішої точки центральних двох метрів
    double right = l/2+1.5;
    cout << l << '\n';
    cout << "Left to right: ";
    for(int i=0;i<s.size();i++){
        double start_of_letter = 0.8*golos*i;
        double end_of_letter = 0.8*golos*(i+1);
        //умовний оператор
        if( (end_of_letter<=right&&end_of_letter>=left) || (start_of_letter<=right&&start_of_letter>=left)){
            cout << s[i] << ' ';
        }
        if(start_of_letter>left) break; // оператор break для того щоб не перевіряти зайві букви після виходу з центральних 3-ьох метрів
    }
    reverse(s.begin(),s.end());
    cout << "\nRight to left: ";
    for(int i=0;i<s.size();i++){
        double start_of_letter = 0.8*golos*i;
        double end_of_letter = 0.8*golos*(i+1);
        if( (end_of_letter<right&&end_of_letter>left) || (start_of_letter<right&&start_of_letter>left)){
            cout << s[i] << ' ';
        }
        if(start_of_letter>left) break;
    }
    return 0;
}
