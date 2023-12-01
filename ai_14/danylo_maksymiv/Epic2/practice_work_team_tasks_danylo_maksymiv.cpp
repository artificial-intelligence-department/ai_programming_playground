#include <iostream>
#include <string>

using namespace std;

string wheather;


int main()

{
    bool correctwheather = false; 
    
    while(correctwheather!=true){
    
    cout<<"Введіть поточні погодні умови( sunny, rainy, cloudy, snowy, windy ):" <<endl;
    cin>> wheather ;

    if (wheather == "sunny" || wheather == "rainy" || wheather == "cloudy" ||  wheather == "snowy" || wheather == "windy" )
    {
        correctwheather=true;
    } 
    
    else
    {
        cout<<"Введіть коректні значення!!!"<<endl;
    }
    }
    


    if(wheather == "rainy" || wheather == "snowy" )
    {
    cout<<"Візьміть сьогодні куртку!"<<endl;
    }
    
    else{
    cout<<"Куртка сьогодні не потрібна!"<<endl;    
    }


    if(wheather == "sunny"){
    cout<<"Саме час для пікніку з друзями!"<<endl;
    } 

    else if(wheather == "rainy"){
    cout<<"Не забудьте взяти парасольку!"<<endl;
    }

    else if(wheather == "windy"){
    cout<<"Запустіть повітряного змія!"<<endl;
    }
    
    else if(wheather == "cloudy"){
    cout<<"Гайда в кіно!"<<endl;
    }
    
    else if(wheather == "snowy"){
    cout<<"Як давно ви ліпили сніговика?Перші 40 років дитинства найкращі!"<<endl;
    }

    char i = wheather[0];

    switch(i){
    case 'r':
       cout<<"Не беріть біле взуття ;)"<<endl;
       break;
    case 'w':
       cout<<"Будь яке взуття підійде)"<<endl;
       break;
    case 'c':
       cout<<"Про всяк випадок візьміть черевики,не випробовуйте долю"<<endl;
       break;
    case 's':
       if (wheather[1]=='u'){
       cout<<"Босоніжки чудовий вибір саме сьогодні!З шкарпетками дивиться ще краще:)"<<endl;
       }
       else{
       cout<<"Найцупкіші черевики і дві пари шкарпеток врятують вас від холоду.Але це не точно))"<<endl;
       }

       break;
    }

}