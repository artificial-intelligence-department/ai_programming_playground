#include <iostream>
#include <cmath>

using namespace std;

bool ability(int x, int y, int z) {
    return (x + y > z) && (x + z > y) && (y + z > x);
}


int countTriangles(int n, ...) {
    va_list args;
    va_start(args, n);

    int triangleCount = 0;

    for (int i = 0; i < n - 2; i += 3) {
        int x = va_arg(args, int);
        int y = va_arg(args, int);
        int z = va_arg(args, int);

        if (ability(x, y, z)) {
            triangleCount++;
        }
    }

    va_end(args);

    return triangleCount;
}

int main() {
    int trianglesCount1 = countTriangles(3, 3, 4, 5);
    cout << "Number of triangles for case 1: " << trianglesCount1 << endl;

    int trianglesCount2 = countTriangles(9, 3, 4, 5, 6, 7, 8, 9, 10, 11);
    cout << "Number of triangles for case 2: " << trianglesCount2 << endl;

    int trianglesCount3 = countTriangles(11, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);
    cout << "Number of triangles for case 3: " << trianglesCount3 << endl;

    return 0;
    
}