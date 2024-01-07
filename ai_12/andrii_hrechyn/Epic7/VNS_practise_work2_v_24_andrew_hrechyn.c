#include<stdio.h>   //Підключаю бібліотеку С (вводу, виводу)
#include<math.h>    //підключаю математичну бібліотеку

double function(double x) {         //початок функції function
    return exp(-x) * cos(pow(x,2));         //повернення результату обчислення
}

int main() {        //початок функції main
    double low = 0.3;
    double up = 5.0;        //ініціалізація дійсних змінних і присвоєння їм значень
    double step = 0.1;

    int negative_amount = 0;    //ініціалізація цілочисельної змінної і присвоєння їй значення

    for (double x = low; x <= up; x += step) {      //початок циклу
        double result = function(x);                //ініціалізація дійсної змінної і присвоєння їй значення функції

        if (result < 0) {           //умова
            negative_amount++;      //якщо умова істинна, виконується дія
        }
    }

    printf("\n\033[34;1mNumber of times the function is negative :\033[0m\n\033[33;1m%d \033[0m", negative_amount);     //виведення результату

    return 0;
}

