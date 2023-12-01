#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    int H, M, temp1, temp2, hp = 0, mn = 0; // H, M - початкове хп, temp1, temp2 - затрати хп і мани на ході, hp = 0, mn = 0 - загальні витрати мани.
    cout << "Enter your initial hitpoints: ";
    cin >> H;
    while(H < 1 || H > pow(10,12)){ // умова виконання
        cout << "Enter your initial hitpoints again: ";
        cin >> H;
    }
    cout << "Enter your initial mana: ";
    cin >> M;
    while(M < 1 || M > pow(10,12)){ // умова виконання
        cout << "Enter your mana initial again: ";
        cin >> M;
    }
    cout << "Enter amount of hitpoints you will spend on turn 1: ";
    cin >> temp1;
    while(temp1 < 0 || temp1 > pow(10,12)){ // умова виконання
        cout << "Enter your hitpoints again: ";
        cin >> temp1;
    }
    hp += temp1; // додавання загального хп і хп, яке було вказане під час ходу 1 
    cout << "Enter amount of mana you will spend on turn 1: ";
    cin >> temp2;
    while(temp2 < 0 || temp2 > pow(10,12)){ // умова виконання
        cout << "Enter your mana again: ";
        cin >> temp2;
    }
    mn += temp2; // додавання загальної мани і мант, яка була вказана під час ходу 1 
    if(temp1 != 0 && temp2 != 0){ // умова виконання
        H =-1; // Якщо, хоча б одне з них не дорівнює 0, то максимальне значення хп стає -1
    }
    cout << "Enter amount of hitpoints you will spend on turn 2: ";
    cin >> temp1;
    while(temp1 < 0 || temp1 > pow(10,12)){ // умова виконання
        cout << "Enter your hitpoints again: ";
        cin >> temp1;
    }
    hp += temp1; // додавання загального хп і хп, яке було вказане під час ходу 2 
    cout << "Enter amount of mana you will spend on turn 2: ";
    cin >> temp2;
    while(temp2 < 0 || temp2 > pow(10,12)){ // умова виконання
        cout << "Enter your mana again: ";
        cin >> temp2;
    }
    mn += temp2; // додавання загальної мани і мант, яка була вказана під час ходу 2 
    if(temp1 != 0 && temp2 != 0){
        H = -1; // Якщо, хоча б одне з них не дорівнює 0, то максимальне значення хп стає -1
    }
    cout << "Enter amount of hitpoints you will spend on turn 3: ";
    cin >> temp1;
    while(temp1 < 0 || temp1 > pow(10,12)){ // умова виконання
        cout << "Enter your hitpoints again: ";
        cin >> temp1;
    }
    hp += temp1; // додавання загального хп і хп, яке було вказане під час ходу 3 
    cout << "Enter amount of mana you will spend on turn 3: ";
    cin >> temp2;
    while(temp2 < 0 || temp2 > pow(10,12)){ // умова виконання
        cout << "Enter your mana again: ";
        cin >> temp2;
    }
    mn += temp2; // додавання загальної мани і мант, яка була вказана під час ходу 3 
    if(temp1 != 0 && temp2 != 0){ // умова виконання
        H = -1; // Якщо, хоча б одне з них не дорівнює 0, то максимальне значення хп стає -1
    }
    if((H - hp) >= 0 && (M - mn) >= 0){ // умова виконання
        cout << "YES (Player win!)"; 
    }else{
        cout << "NO (Player lose!)";
    }
}