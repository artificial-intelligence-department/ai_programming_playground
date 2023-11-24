#include <cstdio>
#include <cmath>
#include <iostream>



int main()
{
    char name[30]; //Оголошуємо змінну для імені
    double principal; //Оголошуємо змінну для початкової суми
    double rate; //Оголошуємо змінну для проценту депозиту
    short years; //Оголошуємо змінну для періоду депозиту
    long result; //Оголошуємо змінну для результату обчислень
    int period; //Оголошуємо змінну для кількості складань в рік

    printf("Enter your name:\n");
    scanf("%s",name); //приймаємо змінну для імені
    printf("Enter the principal amount: \n");
    scanf("%lf", &principal); //приймаємо змінну для відсотку
    printf("Enter the rate of interest (in percentage): \n");
    scanf("%lf", &rate); //приймаємо змінну для відсотку
    printf("How times per year your principal would increase: print 1 - yearly, 4 - by season, 12 - monthly");
    scanf("%i", &period); //приймаємо змінну для періодичності відсотку
    printf("Enter the number of years: \n");
    scanf("%hd", &years); //приймаємо змінну для років

    result = principal*pow((1+(rate/100)),years*period); // Обчислюємо складений депозит за формулою

    printf("Hello, %s", name," ! \n");
    printf(" The compound interest for a principal of %lf", principal);
    printf("at a rate of %lf", rate); 
    printf(" %i times ", period);
    printf("for %hd ", years);
    printf("years is: %lu", result); //Виводимо фінальний результат
    
    return 0;
}
