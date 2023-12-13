#include <iostream> 
#include <cstdarg>
#include <cmath> 

using namespace std; 
 
void print_helper(int count, int temp, va_list args) { 
    if (temp < count) {
        double currentArg = va_arg(args, double);
        temp++;
        cout << "The length of the height drawn from the side " << temp << " is: " << currentArg << endl;
        print_helper(count, temp, args); //15. в коді використано рекурсивну функцію 
    }
}

void print(int count, int temp, ...) { //13. в коді використано еліпсис 
    cout << "Side of triangle are: 5, 7 and 6" << endl;
    va_list args;
    va_start(args, temp);
    print_helper(count, temp, args);
    va_end(args);
}
int main() { 
    double mas[3][2]; //7. в коді використаний двовимірний масив 
    int a = 6, b = 5; //1. в коді використана як мінімум одна цілочисельна змінна
    const int c = 3; //4. в коді використана як мінімум одна цілочисельна константа
    float p; //2. в коді використана як мінімум одна дійсна змінна
    mas[0][1] = a;
    mas[1][1] = b;
    mas[2][1] = c;
    p = (a + b + c) / 2; //17. в коді використано математичні операції та математичні функції
    for(int i=0; i<3; i++){ //10. в коді використаний for цикл 
        mas[i][0] = round((2.0 / mas[i][1]) * sqrt(p * (p - a) * (p - b) * (p - c)) * 10) / 10; 
    }
    print(3, 0, mas[0][0], mas[1][0], mas[2][0]); //16. в коді використано параметри та аргументи функції
}