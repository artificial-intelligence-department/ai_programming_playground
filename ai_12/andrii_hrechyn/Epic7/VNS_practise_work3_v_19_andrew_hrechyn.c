#include <stdio.h>      //Підключаю бібліотеку С (вводу, виводу)
#include <math.h>       //Підключаю бібліотеку математичних функцій

void cash();    //прототип функції

int main(){     //основна функція
    puts("Enter coordinates:");     //вивід стрічки "Enter coordinates:"
    int coordinates[3][2];          //ініціалізація двовимірного масиву
    for(int i = 0; i < 3; ++i){                 //за допомогою цієї частинки коду, записую x та y в двовимірний масив
        for(int j = 0; j < 2; ++j){
            scanf("%d", &coordinates[i][j]);
        }
    }

    int vec1[2], vec2[2], vec3[3];      //ініціалізував 3 вектори

    vec1[0] = (coordinates[1][0] - coordinates[0][0]);    
    vec1[1] = (coordinates[1][1] - coordinates[0][1]);    
    vec2[0] = (coordinates[2][0] - coordinates[0][0]);    
    vec2[1] = (coordinates[2][1] - coordinates[0][1]);    //знаходжу координати векторів у цій частині коду
    vec3[0] = (coordinates[1][0] - coordinates[2][0]);    
    vec3[1] = (coordinates[1][1] - coordinates[2][1]);    

    double l1 = sqrt(pow(vec1[0],2) + pow(vec1[1],2));    
    double l2 = sqrt(pow(vec2[0],2) + pow(vec2[1],2));    //ініціалізую і знаходжу довжини векторів
    double l3 = sqrt(pow(vec3[0],2) + pow(vec3[1],2));    
    double p = (l1+l2+l3)/2;                              //знаходжу півпериметр

    double S = sqrt(p * (p - l1) * (p - l2) * (p - l3));    //знаходжу площу за формулою Герона 
    printf("Area %lf\n", S);                                //виводжу площу 

    printf("Task 2\n");   

    cash();     //виклик функції cash()

    return 0;       
}

void cash(){                                    //оголошую функцію, яка не приймає і не виводить нічого void               
    double pen_c, copybook_c;                   //ініціалізую дійсні змінні: ціна 1 ручки, ціна 1 зошита
    int pen_n, copybook_n;                      //ініціалізую цілочисельні змінні: кількість ручок та кількість зошитів
    puts("Enter costs:");                       //виводжу стрічку "Enter costs: "
    scanf("%lf %lf",&pen_c, &copybook_c);       //зчитую ціну ручки та зошита
    puts("Enter number of pens and copybooks"); //виводжу стрічку "Enter number of pens and  copybooks"
    scanf("%d %d", &pen_n, &copybook_n);        //зчитую кількість ручок та зошитів
    double cost = pen_c * pen_n + copybook_c * copybook_n;  //ініціалізую змінну cost 
    printf("Cost is: %lf", cost);               //виводжу результат
}                                               //кінець функції