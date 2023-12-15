#include <iostream>


int main() {    
    double M, m, H, h;
    int lose= 0;
    std::cin >> M >> H;


    for (int i = 0; i < 3; ++i) {
        std::cin >> m;
        M -= m;


        std::cin >> h;
        H -= h;
        if (h !=0 && m !=0){
            lose=1;
        }
        }


    if (H < 1 || M < 1 || lose==1) {
        std::cout << "NO\n";
    }


   else {
        std::cout << "YES\n";
    }


    return 0;
    }




