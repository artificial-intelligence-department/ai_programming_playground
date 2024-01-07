#include <stdio.h>
#include <string.h>

int main(){
    char weather[10];
    printf("Введіть поточні погодні умови(sunny, rainy, cloudy, snowy, windy): ");
    scanf("%s", weather);
    if(weather[1]=='n'||weather[0]=='r'){
        printf("Вам потрібно взяти куртку.\n");
    }else{
        printf("Куртка не потрібна.\n");
    }
    if(strcmp(weather, "sunny")==0){
        printf("Чудовий день для пікніка!\n");
    }else if(strcmp(weather, "rainy")==0){
        printf("Ідеальна погода, щоб читати книгу всередині!\n");
    }else if(strcmp(weather, "cloudy")==0){
        printf("Може, відвідати музей?\n");
    }else if(strcmp(weather, "snowy")==0){
        printf("Як щодо того, щоб зліпити сніговика?\n");
    }else if(strcmp(weather, "windy")==0){
        printf("Запустіть повітряного змія, якщо він у вас є!\n");
    }else{
        printf("Будь ласка, введіть дійсну умову погоди.\n");
    }
    switch (weather[0]){
        case 's':
        if(strcmp(weather, "sunny")==0){
            printf("Взуй улюблені кросівки!\n");
        }else{
            printf("Снігові черевики зігріють ваші ноги!\n");
            }        
            break;
        case 'r':
            printf("Дощові чоботи - гарна ідея!\n");
            break;
        case 'c':
            printf("Сьогодні підходить будь-яке взуття.\n");
            break;
        case 'w':
            printf("Одягніть щось міцне!\n");
            break;
        default:
            printf("Взуйте мешти\n");
            break;
    }

    return 0;
}