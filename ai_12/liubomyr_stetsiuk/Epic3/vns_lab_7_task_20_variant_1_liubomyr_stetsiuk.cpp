#include <iostream>
#include <cstdarg>
using namespace std;

bool isTriangle(int x, int y, int z)
{
    return (x + y > z) && (x + z > y) && (y + z > x);
}

int triangle(int count, ...)
{
    va_list args;
    va_start(args, count);

    int possible_triangles = 0;
    for (int i = 0; i < count - 2; i += 1)
    {
        int x = va_arg(args, int);
        int y = va_arg(args, int);
        int z = va_arg(args, int);

        if (isTriangle(x, y, z))
        {
            possible_triangles++;
        }
    }

    va_end(args);
    return possible_triangles;
}

int main()
{
    int triangles_1 = triangle(3, 3, 4, 5);
    cout << "Number of triangles possible from 3 parameters: " << triangles_1 << endl;

    int triangles_2 = triangle(9, 3, 4, 5, 7, 8, 10, 12, 15, 9);
    cout << "Number of triangles possible from 9 parameters: " << triangles_2 << endl;

    int triangles_3 = triangle(11, 3, 4, 5, 7, 8, 10, 12, 15, 9, 11, 13);
    cout << "Number of triangles possible from 11 parameters: " << triangles_3 << endl;

    return 0;
}
