#include <cstdarg>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
vector<int> numbers; 
void process(int);
int ternary(int, ...);
int main()
{
    ternary(3, 10, 15, 3);
        for (int i = 0; i<numbers.size(); i++){
            cout << numbers.at(i) <<" ";
         }
         cout << endl;

        numbers.clear();
    ternary(4, 15, 8, 11, 4);
        for (int i = 0; i<numbers.size(); i++){
            cout << numbers.at(i) <<" ";
        }
        cout << endl;

        numbers.clear();
    ternary(7, 19, 22, 43, 14, 23, 15, 2);
        for (int i = 0; i<numbers.size(); i++){
            cout << numbers.at(i) <<" ";
        }
        cout << endl;

    return 0;
}

void process(int num) {
    int ternary = 0, k = 0;
    while (num > 0) {
        ternary += (num % 3) * pow(10, k);
        num /= 3;
        k++;
    }
    numbers.push_back(ternary);
}

int ternary(int c, ...){
    va_list chusla;

    va_start(chusla, c);

    for(int i = c;i!=0;i--)
    {
        int x = va_arg(chusla, int);
        process(x);
    }
    va_end(chusla);
    return 0;
}
