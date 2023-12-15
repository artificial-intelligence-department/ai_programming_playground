#include <iostream>

using namespace std;

int main() {

    int suma = 0;

    for (int i=2; i<100; i+=2){
        suma+=i;
    }

    cout << "Sum = " << suma << endl;


    return 0;
}