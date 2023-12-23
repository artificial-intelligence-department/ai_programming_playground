#include <iostream>
using namespace std;
    /*matrix determinant calculator*/
int main() {
   cout<< "Print out your 3x3 matrix ";
    signed int array1[3];
    signed int array2[3];
    signed int array3[3];


    scanf("%d", &array1[0]);
    scanf("%d", &array1[1]);
    scanf("%d", &array1[2]);

        scanf("%d\n", &array2[0]);
        scanf("%d", &array2[1]);
        scanf("%d", &array2[2]);

            scanf("%d\n", &array3[0]);
            scanf("%d", &array3[1]);
            scanf("%d", &array3[2]);

signed int a1 = array1[0]*array2[1]*array3[2];
signed int b1 = array1[1]*array2[2]*array3[0];
signed int c1 = array1[2]*array2[0]*array3[1];

    signed int a2 = array1[2]*array2[1]*array3[0];
    signed int b2 = array1[0]*array2[2]*array3[1];
    signed int c2 = array1[1]*array2[0]*array3[2];


        cout << "Here is determinant\n" << a1 + b1 + c1 - a2 - b2 - c2;

}