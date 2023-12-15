#include <iostream>

int main() {
    long long H, M;
    int i = 0;
    std::cin >> H >> M;

    long long h[3];
    long long m[3];
    for (int i = 0; i < 3; i++){
        std::cin>>h[i];
        std::cin>>m[i];
    }

    // Перевірка для кожного з трьох можливих випадків
    for(int i = 0; i<3; i++){ 
       if(h[i] != 0 && m[i]!=0){
        std::cout << "NO" << std::endl;
        return 0;
       }
    }
    if ((h[0] + h[1] + h[2] < H && m[0] + m[1] + m[2] < M)) {
        std::cout << "YES" << std::endl;
    }    else {
        std::cout << "NO" << std::endl;
    }


    return 0;
}
