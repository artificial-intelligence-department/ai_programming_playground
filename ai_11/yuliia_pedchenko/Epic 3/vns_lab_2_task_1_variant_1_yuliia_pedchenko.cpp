// Знайти суму цілих додатніх чисел, кратних 3 і менших 200
#include <iostream>

using namespace std;
int main() {
    int result; 
    result = 0;
for (int i = 3; i < 200; i+=3) {
    result += i;
}
cout << result;
return 0;
}