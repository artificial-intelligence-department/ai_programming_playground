#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main() {
    #include <iostream>

int main() {
   
    int n, b, y;
    std::cin >> n >> b >> y;

    int color_changes = 0;

    for (int i = 0; i < n; i += (b + 1)) {
        color_changes++;
    }

    for (int i = 0; i < n; i += (y + 1)) {
        color_changes++;
    }


    std::cout << color_changes << std::endl;

    return 0;
}


    return 0;
}
