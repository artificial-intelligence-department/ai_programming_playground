#include <iostream>

using namespace std;

int main() 
{
    int N;
    int leftone = 0;
    int rightone = 0;
    int positleft = 0;
    int positright = 0;

    cin >> N;

    int* array = new int[N];
    for (int i = 0; i < N; ++i) 
    {
        cin >> array[i];
    }

    positright = N - 1;
    while (positleft + 1 < positright) 
    {
        positleft += leftone;
        positright -= rightone;

        leftone = array[positleft];
        rightone = array[positright];
    }

    cout << positleft + 1 << " " << positright + 1 << endl;

    if (positleft + 1 == positright) 
    {
        cout << "Stopped";
    } 
    else if (positleft == positright) 
    {
        cout << "Collision";
    } 
    else 
    {
        cout << "Miss";
    }

    return 0;
}
