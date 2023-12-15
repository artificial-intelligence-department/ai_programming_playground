#include <iostream>

int main() {
    int n, bills = 0;
    std::cin >> n;
    
    while(n > 0){
        bills += 1;
        if(n >= 500){
            n -= 500;
        }else if (n >= 200){
            n -= 200;
        }else if(n >= 100){
            n -= 100;
        }else if(n >= 50){
            n -= 50;
        }else if (n >= 20){
            n -= 20;
        }else if (n >= 10){
            n -= 10;
        }else if(n >= 5){
            n -= 5;
        }else if(n >= 2){
            n -= 2;
        }else {
            n -= 1;
        }
    }

    std::cout << bills << std::endl;

    return 0;
}