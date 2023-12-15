#include <iostream>
#include <string>
#include <vector>
 int main(){
    using namespace std;
    int choise;

    std::vector<string> list = {"Bible", "algebra 5 class", "Dog Money"};
    std::vector<bool> available = {true, true, true};
    std::vector<string> borrowed{7, "empty"};
    bool yon = true;
    bool repeat = true;
     string gift;
     string cond;

cout << "Вітаємо вас в бібліотеці НУЛП. Тут ви можете знайти великий вибір книжок\n ";
menu :
while(repeat){
    yon = true;
cout << "Що ви бажаєте зробити (напишіть цифру)\n";
cout << "1)переглянути список книги\n";
cout << "2) взяти книгу в бібліотеці\n";
cout << "3) повернути книгу\n";
cout << "4) вийти з програми\n";
cin >> choise;
cout << endl;



switch(choise){



     case 1:
    cout << "У нас є такі книги:" << endl ;
    for(int i = 0; i<size(list); i++){
        if(available[i] == false)
        cout << list[i] << " немає в наявності\n";


        else if(available[i] == true)
        cout << list[i] << " є в наявності\n";
    
    

    }
    goto abil;

    case 2:
    cout << "в нас є такий вибір книжок:\n";



    for(int i = 0; i<size(available); i++)
    if(available[i] != false)
    cout << i+1 << ") " << list[i]<< endl;

    cout << "яку книжку ви бажаєте взяти?:";
    int number;
    cin >> number;
    number = number - 1;
    if(available[number] == false){
        goto wrong;
    }
    else if(number>= 0 && number<available.size()){
    cout << "вітаю ви взяли книжку "<< list[number] << endl;
    available[number]= false;
    borrowed[number] = list[number];
    goto abil;
    }

    else {
    goto wrong;
    }


    case 3:
    cout << "яку книжку ви бажаєте повернути?\n";
    for(int i=0;i<size(borrowed); i++){

        if( borrowed[i ]!= "empty")
        cout << i+1 << ")"<< borrowed[i] << endl;
       
    }
        cin  >> number;
        number = number-1;
        if(borrowed[number] != "empty" && number <=size(borrowed) && number >= 0 ){
        borrowed[number] = "empty";
        available[number] = true;
        cout << "Вітаю! Ви законопослушний громадянин, бо повернули книгу " << list[number] << endl;
        goto abil;
        }
        else{
            goto wrong;

        }
   

    
   
    goto abil;

    



    case 4:
    cout << "дякую що відвідали нашу бібліотеку!";
    repeat = false; 
    break;



wrong :
 cout << "неправильний вибір\n";
    goto menu;



    abil :
char ans;
cout << "Бажаєте продовжити?(y/n) ";
cin >> ans;
if(ans == 'Y' || ans == 'y'){
    goto menu;

}
if(ans == 'n' || ans == 'N'){
     repeat = false; 
    break;
}
else{
    goto abil;
}



}


}














    return 0;
 }