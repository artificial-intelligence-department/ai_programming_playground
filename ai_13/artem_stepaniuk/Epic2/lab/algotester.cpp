#include <iostream>
#include <algorithm>


int main() {
    
    long int h[4], d[4];

    for (int i = 0; i < 4; i++) {
        std::cin >> h[i];
    }
    
    for (int i = 0; i < 4; i++){
        std::cin >> d[i];
        if (d[i] > h[i]) {
            std::cout << "ERROR" << std::endl;
            return 0;
        }
    }
    
    for (int i = 0; i < 4; i++) {
        
        h[i] -= d[i];

        long hmax = *std::max_element(h, h+4);
        long hmin = *std::min_element(h, h+4);
        
        if (hmax >= 2 * hmin)
        {
            std::cout << "NO";
            return 0;
        }

    }
    
    std::cout << "YES" << std::endl;

    return 0;
}
