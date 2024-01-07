#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int* array = new int[N];
    for (int i = 0; i < N; ++i) 
    {
        cin >> array[i];
    }

    int leftOne = 0;
    int rightOne = 0;
    int posLeft = 0;
    int posRight = N - 1;

    while (posLeft + 1 < posRight) 
    {
        posLeft += leftOne;
        posRight -= rightOne;

        leftOne = array[posLeft];
        rightOne = array[posRight];
    }

    cout << posLeft + 1 << " " << posRight + 1 << endl;

    if (posLeft + 1 == posRight) 
    {
        cout << "Stopped";
    } 

    else if (posLeft == posRight) 
    {
        cout << "Collision";
    } 

    else 
    {
        cout << "Miss";
    }
    
    return 0;
}