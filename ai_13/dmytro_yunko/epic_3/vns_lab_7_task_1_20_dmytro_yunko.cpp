#include <iostream>
#include <cstdarg>
using namespace std;

#define EXIST_TRIANGLE(x, y, z) ((x + y > z) && (x + z > y) && (y + z > x))

int triangle(int n, ...){
    va_list args;
    va_start(args, n);
    int triangleAm {0};
   
for (int i = 0; i < n-2 ; i+=3) {
        
        int x = va_arg(args, int);
        int y = va_arg(args, int);
        int z = va_arg(args, int);

        if (EXIST_TRIANGLE(x, y, z)) {
            triangleAm++;
            cout<< x<< " "<<y<<" "<<z<<endl;
        }



}
return triangleAm;
}




int main(int argc, char const *argv[])
{
    cout<< triangle(3,3,4,5)<<endl;
    cout<< triangle(9,9,1, 3, 4, 5,6,8,7,13)<<endl;
    cout<< triangle(11,9,1, 3, 2, 5,6,8,2,13, 15,16)<<endl;
    return 0;
}
