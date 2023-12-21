#include <iostream>
#include <cstdarg>

using namespace std;

string triykova (int a, ...)
{
    string result;
    va_list args;
    va_start(args, a); 

    while (a > 0)
    {
        int remainder = a % 3;
        result = to_string(remainder) + result;
        a /= 3;
    }

    va_end(args);

    return result;
}

int main() {
    cout << triykova(123) << endl;
    cout << triykova(7564) << endl;
    cout << triykova(1230456) << endl;
    return 0;
}

