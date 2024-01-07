#include <iostream>
#include <vector>

int main(){
    size_t n;
    std::vector<unsigned short int> drones;

    std::cin >> n;

    for (unsigned short int i = 0; i < n; i++ ){
        unsigned short int temp;
        std::cin >> temp;
        drones.push_back(temp);
    }

    short left = 1;
    short right = n;


    while(true){
        if (left == right - 1){
            std::cout << left << ' ' << right << std::endl;
            std::cout << "Stopped";
            return 0;
        } else if (left == right ){
            std::cout << left << ' ' << right << std::endl;
            std::cout << "Collision";
            return 0;
        } else if (left > right){
            std::cout << left << ' ' << right << std::endl;
            std::cout << "Miss";
            return 0;
        }

        left += drones[left-1];
        right -= drones[right-1];
    }
}