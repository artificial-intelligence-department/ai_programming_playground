#include<iostream> // підключення бібліотеки для вводу/виводу
#include<cmath> //підкулючення бібліотеки математичних функцій
#include<cstdarg> //підключення бібліотеки для використання еліпсису
using namespace std;
#define CONST 3 // цілочисельна константа 
double halfperimeter(int num, ...){ //параметри функції
    va_list args; //задаємо еліпсис 
    double sum = 0;

    va_start(args, num);

    for(int i=0;i<num;i++) //цикл for для знаходження суми чисел
        sum += va_arg(args, double);
    
    va_end(args);

    return (sum/2); //функція повертає половину периметра
}



int main(){
    double sides[CONST]; //одновимірний масив для збереження сторін трикутника
    int i = 0; // цілочисельна змінна
    while(i<CONST){ // цикл while для введення значень в масив
        cin>>sides[i]; //оператор введення даних
        i++;
        if(i==3){
            break; 
        }
    }

    double a = sides[0]; //дійсні змнні подвійної точності (задаю повторно для зручності використання) 
    double b = sides[1];
    double c = sides[2];

    if(!(a+b>c)||!(b+c>a)||!(a+c>b)){ //за допомогою оператора розгалуження if перевіряємо чи здійснюється нерівність трикутника
        cout<< "wrong sidelengths!"; //оператор виведення даних
        return 0;
    }

    double p =halfperimeter(CONST, a, b, c);// функція для пошуку напівпериметра, в неї введені аргументи

    double product  = p*(p-a)*(p-b)*(p-c); //знаходимо добуток 
    i = 0;
    do {
    double h = (2/sides[i])*sqrt(product); //знаходимо висоту по формулі, користуємось математичною функцією квадратного кореня
        cout<< h<<"\n"; // виводимо значення
        i++;
        continue; // наступна ітерація циклу
    } while (i<CONST);


    return 0; // кінець
}
