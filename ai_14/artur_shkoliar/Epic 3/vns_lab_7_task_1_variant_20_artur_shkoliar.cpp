#include <iostream>
#include <cstdarg>

using namespace std;

bool isTriangle(int x, int y, int z) 
{
    return (x + y > z) && (y + z > x) && (x + z > y);
}

int triangle(int count, ...) 
{
    va_list args;
    va_start(args, count);

    int existingTriangles = 0;

    for (int i = 0; i < count; i += 3)
     {
        int x = va_arg(args, int);
        int y = va_arg(args, int);
        int z = va_arg(args, int);

        if (isTriangle(x, y, z)) 
        {
            existingTriangles++;
        }
    }

    va_end(args);

    return existingTriangles;
}

int main()
{
    int trianglesCount = triangle(3, 3, 4, 5, 7, 8, 9, 3, 3, 3);

    cout << "Кількість можливих трикутників: " << trianglesCount << endl;

    return 0;
}
