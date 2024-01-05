#include <iostream>

int main(){
    std::cout << "Обчислення швидкості бігу." << std::endl;
    std::cout << "Введіть довжину дистанції (метрів): ";
    double length;
    double time;
    std::cin >> length;
    std::cout << "Введіть час (хвилин.секунд): ";
    std::cin >> time;
    int minutes = time;
    int temp1 = minutes;
    int seconds = time*100 - minutes*100;
    minutes *= 60;    
    double final = minutes + seconds;
    std::cout << "Дистанція: " << length << " м" << std::endl;
    std::cout << "Час: " << temp1 << " хв " << seconds << " с = " << final << " с" << std::endl;
    long double speed = (length/final) * 3.6;
    std::cout << "Швидкість бігу = " << speed << " км/год";

}