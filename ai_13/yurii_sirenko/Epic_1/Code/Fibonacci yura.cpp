#include <iostream>
#include <windows.h> 

using namespace std;

int main()
{
    HANDLE console_color; 
    console_color = GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleTextAttribute(console_color, 2); //Для створення кольору консолі
    unsigned long long int a1 = 1; //Оголошення змінних
    unsigned long long int a2 = 1;
    unsigned long long int a3;
    cout <<"1 \n1 \n";
    for(int n = 0; n<10; n++) //Створення циклу спнцифічного для чисел Фібоначчі
    {
    a3=a2+a1;
    a1=a2;
    a2=a3;
    cout << a3 <<"\n"; //Вивід значень
    } 
}