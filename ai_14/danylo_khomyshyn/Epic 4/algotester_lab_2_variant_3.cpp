#include <iostream>

using namespace std;

int main() 
{
    int len;
    int leftd, rightd, posl, posr = 0;
    cin >> len;

    int* array = new int[len];
    for (int i = 0; i < len; ++i) {
        cin >> array[i];
    }

    posr = len - 1;
    while (posl + 1 < posr) {
        leftd = array[posl];
        rightd = array[posr];
        posl += leftd;
        posr -= rightd;
    }

    cout << posl + 1 << endl << posr + 1 << endl;

    if (posl == posr) {
        cout << "Collision";
    } else if (posl + 1 == posr) {
        cout << "Stopped";
    } else {
        cout << "Miss";
    }

    return 0;
}