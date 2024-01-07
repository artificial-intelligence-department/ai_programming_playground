#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
    char name[100];
    int FinalAmount; 
int Realperiod;
    int time, money, period, stepin;
    float percent, percent0;

    printf("відсоткова ставка?:");
    scanf("%f", &percent0); 
    percent = percent0 / 100;
    
    printf("тривалість депозиту(роки)?:");
    scanf("%d", &time);

    printf("кількість внесених коштів?:");
    scanf("%d", &money);

    printf("нараховування нараховується періодичністю (1,2,3,4,6,12) (в місяцях)?:");
    scanf("%d", &period);

Realperiod = 12/period;

    printf("Ваше Ім'я?:");
    scanf("%s", name);
printf("%d", Realperiod);

    stepin = time * period;
    FinalAmount = money * pow(1 + percent, stepin);

    printf("%s, Вашою кінцевою сумою депозиту буде: %d\n", name, FinalAmount); 
    return 0;
}