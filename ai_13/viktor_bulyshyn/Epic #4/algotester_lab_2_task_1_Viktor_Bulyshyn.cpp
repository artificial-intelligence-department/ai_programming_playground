#include <iostream>
using namespace std;

int main() {

int N;

cin >> N;

int speed[N];
for (int i = 0; i < N; i++)

cin >> speed[i];
int leftPos = 0;
int rightPos = N - 1;
    while(true) {
        if (leftPos == rightPos)
        {
            cout << leftPos + 1 << " " << rightPos + 1 << endl;
            cout << "Collision"; 
            return 0;
        }
        else if (rightPos - leftPos == 1)
        {
            cout << leftPos + 1 << " " << rightPos + 1 << endl;
            cout << "Stopped"; 
            return 0;
        }
        else if (rightPos - leftPos <= -1)
        {
            cout << leftPos + 1 << " " << rightPos + 1 << endl;
            cout << "Miss"; 
            return 0;
        }
leftPos += speed[leftPos];
rightPos -= speed[rightPos];
    }
    return 0;
}