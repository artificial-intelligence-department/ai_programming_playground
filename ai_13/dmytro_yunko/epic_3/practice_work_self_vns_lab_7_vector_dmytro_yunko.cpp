#include <iostream>
#include <vector>
using namespace std;

#define EXIST_TRIANGLE(x, y, z) ((x + y > z) && (x + z > y) && (y + z > x))

int triangle(vector<int> n){
    
    int triangleAm {0};

for (int i = 0; i < n.size()-2 ; i+=3) {
        
        int x = n[i];
        int y = n[i+1];
        int z = n[i+2];

        if (EXIST_TRIANGLE(x, y, z)) {
            triangleAm++;
            cout<< x<< " "<<y<<" "<<z<<endl;
        }



}
return triangleAm;
}




int main(int argc, char const *argv[])
{
    cout<< triangle({3,4,5})<<endl;
    cout<< triangle({9,1, 3, 4, 5,6,8,2,13})<<endl;
    cout<< triangle({9,1, 3, 2, 5,6,8,2,13, 15,16})<<endl;
    return 0;
}
